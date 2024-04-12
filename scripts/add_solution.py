# Not in use!

import os.path
from typing import List, Tuple, Dict
import sys

SOLUTION_PREFIX = 'add_executable'
LEETCODE_WEB_PREIX = 'https://leetcode.com/problems/'

cpp_template = """//
// {problem_url}
//

#include "leetcode_utils.hpp"

using namespace std;

{func_body}

int main() {{
    auto f = []({param_list}) {{
        auto output = {func_call};
        leetcode_assert(output == expect, "{problem_name} {param_format} expect={{}} output={{}}", {param_arg}, expect, output);
    }};
    f();
}}
"""


class LeetCodeSolution(object):
    def __init__(self, name: str, url: str, deps: List[str], func_lines: List[str]):
        self.name = name
        self.url = url
        self.deps = deps
        self.func_lines = [line.strip() for line in func_lines]
        self.cpp_str = self.__gen_cpp_file()

    def __gen_cpp_file(self) -> str:
        line1 = self.func_lines[0]
        open_parenthesis_i = line1.find('(')
        close_parenthesis_i = line1.rfind(')')
        space_i = line1.find(' ')
        func_name = line1[space_i + 1:open_parenthesis_i]
        return_type = line1[:space_i]
        params_str = line1[open_parenthesis_i + 1: close_parenthesis_i]
        param_pair_strs = [ps.split(' ') for ps in params_str.split(', ')]
        param_names = [pair[1] for pair in param_pair_strs]
        param_converted_types = [self.__convert_type(pair[0]) + pair[1] for pair in param_pair_strs]

        param_list_str = f'{", ".join(param_converted_types)}, {self.__convert_type(return_type)}expect'
        func_call_str = f'{func_name}({", ".join(param_names)})'
        container_cmp_str = ''
        should_use_container = self.func_lines[0].startswith('vector<') or self.func_lines[0].startswith('map<')
        if should_use_container:
            container_cmp_str = '\n        bool same = equal(output.begin(), output.end(), expect.begin(), expect.end());'
        param_format_str = ' '.join([pn + '={}' for pn in param_names])
        param_arg_str = ', '.join(param_names)

        return cpp_template.format(
            problem_url=self.url,
            func_body='\n'.join(self.func_lines),
            param_list=param_list_str,
            func_call=func_call_str,
            problem_name=self.name,
            param_format=param_format_str,
            param_arg=param_arg_str,
        )

    def __convert_type(self, type: str) -> str:
        if type == 'string' or type.startswith('vector<') or type.startswith('map<'):
            type = type.strip()
            type = type.rstrip('&')
            return type + ' &&'
        else:
            return type + ' '


def new_solution(url: str) -> LeetCodeSolution:
    name_start = len(LEETCODE_WEB_PREIX)
    name_end = url.find('/', name_start)
    if name_end == -1:
        name_end = len(url)
    name = url[name_start: name_end]
    name = name.replace('-', '_')
    dep = name + '.cpp'
    print(f'  sol: {name}\n  url: {url}\n  file: {dep}')
    print('Is the name correct? [y/N]')
    op = input()
    if op == 'N':
        print('Terminated.')
        exit(-1)
    print('Input the function body.')
    func_lines = sys.stdin.readlines()
    solution = LeetCodeSolution(name, url, [dep], func_lines)
    print('Will generate this file.')
    print(solution.cpp_str)
    print('Is the file content correct? [y/N]')
    op = input()
    if op == 'N':
        print('Terminated.')
        exit(-1)
    return solution


def get_curr_solutions() -> Tuple[List, int, int]:
    print('Reading CMakeLists.txt!')
    solutions = []
    prefix_len = len(SOLUTION_PREFIX)
    start_line = -1
    end_line = -1
    with open('../CMakeLists.txt') as cmake_file:
        lines = cmake_file.readlines()
        for i, line in enumerate(lines):
            if line.startswith(SOLUTION_PREFIX):
                if start_line == -1:
                    start_line = i
                line_size = len(line)
                space_index = line.index(' ')
                close_brace_index = line.index(')')
                solution_name = line[prefix_len + 1: space_index]
                dep = line[space_index + 1: close_brace_index]
                solutions.append(LeetCodeSolution(solution_name, [dep]))
    print(f'Currently you have made {len(solutions)} solutions!')
    end_line = start_line + len(solutions)
    return solutions, start_line, end_line


def write_new_solution(sol: LeetCodeSolution):
    cpp_fn = 'leetcode/' + sol.deps[0]
    with open('./CMakeLists.txt', 'a') as f:
        f.write(f'{SOLUTION_PREFIX}({sol.name} {cpp_fn})\n')
    if not os.path.exists(sol.deps[0]):
        with open(cpp_fn, 'w') as f:
            f.write(sol.cpp_str)
        print(f'File {cpp_fn} created.')
    else:
        print(f'File {cpp_fn} already existed.')


def add_solution(url: str):
    print('Adding new LeetCode solution......')
    if not url.startswith(LEETCODE_WEB_PREIX):
        print('Wrong url!')
        exit(-1)
    # curr_soltions = get_curr_solutions()
    sol = new_solution(url)
    write_new_solution(sol)


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('No LeetCode url!')
        exit(-1)
    url = sys.argv[1]
    add_solution(url)
