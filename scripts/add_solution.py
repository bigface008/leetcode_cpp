#!/usr/bin/env python3
# Not in use!

import os.path
from typing import List, Tuple, Dict, Set
import sys

SOLUTION_PREFIX = 'add_executable'
LEETCODE_WEB_PREIX = 'https://leetcode.com/problems/'
LEETCODE_CN_WEB_PREIX = 'https://leetcode.cn/problems/'

cpp_template_v2 = """//
// {problem_url}
//

#include "leetcode_utils.hpp"

using namespace std;

{class_content}

int main() {{
    auto f = []({param_list}) {{
        auto output = Solution().{func_call};
        leetcode_assert(output == expect, "{problem_name} {param_format} expect={{}} output={{}}", {param_arg}, expect, output);
    }};
    f();
}}
"""

class LeetCodeFuncDef:
    def __init__(self, func_line: str):
        self.name = self.__get_func_name(func_line)
        self.return_type = self.__get_func_return_type(func_line)
        self.args: List[Tuple[str, str]] = self.__get_func_params(func_line)
        print(f'name={self.name} return_type={self.return_type}')

    def __get_func_name(self, line: str) -> str:
        fn_end = line.find('(')
        fn_start = line.rfind(' ', 0, fn_end)
        return line[fn_start + 1:fn_end]

    def __get_func_return_type(self, line: str) -> str:
        fn_end = line.find('(')
        fn_start = line.rfind(' ', 0, fn_end)
        return line[:fn_start].strip()

    def __get_func_params(self, line: str) -> List[Tuple[str, str]]:
        fn_end = line.find('(')
        f_end = line.find(')')
        params = line[fn_end + 1:f_end].split(', ')
        res: List[Tuple[str, str]] = []
        for param in params:
            tp, pn = param.split()
            if tp.endswith('&'):
                tp += '&'
            res.append((tp, pn))
        return res

    def gen_test_func_param_list(self) -> str:
        params = self.args.copy()
        params.append((self.return_type, 'expect'))
        return ', '.join(f'{tp} {pn}' for tp, pn in params)

    def gen_func_call(self) -> str:
        arg_str = ', '.join(pn for tp, pn in self.args)
        return f'{self.name}({arg_str})'

    def gen_param_format(self) -> str:
        return ' '.join((pn + '={}') for tp, pn in self.args)

    def gen_params(self) -> str:
        return ', '.join(pn for tp, pn in self.args)


class LeetCodeSolutionV2:
    def __init__(self, fname: str, url: str, class_lines: List[str]):
        self.fname = fname
        self.url = url
        self.class_lines = class_lines
        self.func_def = LeetCodeFuncDef(class_lines[2].strip())
        self.file_content = cpp_template_v2.format(
            problem_url=self.url,
            class_content=''.join(self.class_lines),
            param_list=self.func_def.gen_test_func_param_list(),
            func_call=self.func_def.gen_func_call(),
            problem_name=self.fname,
            param_format=self.func_def.gen_param_format(),
            param_arg=self.func_def.gen_params(),
        )

    def write_file(self):
        cpp_fn = 'leetcode/' + self.fname + '.cpp'
        with open('./CMakeLists.txt', 'a') as f:
            f.write(f'{SOLUTION_PREFIX}({self.fname} {cpp_fn})\n')
        if not os.path.exists(cpp_fn):
            with open(cpp_fn, 'w') as f:
                f.write(self.file_content)
            print(f'File {cpp_fn} created.')
        else:
            print(f'File {cpp_fn} already existed.')


def get_name_from_url(url: str) -> str:
    name_start = len(LEETCODE_WEB_PREIX)
    if url.startswith(LEETCODE_CN_WEB_PREIX):
        name_start = len(LEETCODE_CN_WEB_PREIX)
    name_end = url.find('/', name_start)
    if name_end == -1:
        name_end = len(url)
    name = url[name_start: name_end]
    name = name.replace('-', '_')
    return name


def new_solution_v2(url: str) -> LeetCodeSolutionV2:
    name = get_name_from_url(url)
    dep = name + '.cpp'
    print(f'  sol: {name}\n  url: {url}\n  file: {dep}')
    print('Is the name correct? [y/N]')
    op = input()
    if op == 'N':
        print('Terminated.')
        exit(-1)
    if name in read_solution_names():
        print(f'Ops! You have already created solution {name}. Aborting.')
        exit(-1)

    print('Input the class.')
    class_lines = sys.stdin.readlines()
    solution = LeetCodeSolutionV2(name, url, class_lines)
    print('Will generate this file.')
    print(solution.file_content)
    print('Is the file content correct? [y/N]')
    op = input()
    if op == 'N':
        print('Terminated.')
        exit(-1)
    return solution


# def get_curr_solutions() -> Tuple[List, int, int]:
#     print('Reading CMakeLists.txt!')
#     solutions = []
#     prefix_len = len(SOLUTION_PREFIX)
#     start_line = -1
#     end_line = -1
#     with open('../CMakeLists.txt') as cmake_file:
#         lines = cmake_file.readlines()
#         for i, line in enumerate(lines):
#             if line.startswith(SOLUTION_PREFIX):
#                 if start_line == -1:
#                     start_line = i
#                 line_size = len(line)
#                 space_index = line.index(' ')
#                 close_brace_index = line.index(')')
#                 solution_name = line[prefix_len + 1: space_index]
#                 dep = line[space_index + 1: close_brace_index]
#                 solutions.append(LeetCodeSolution(solution_name, [dep]))
#     print(f'Currently you have made {len(solutions)} solutions!')
#     end_line = start_line + len(solutions)
#     return solutions, start_line, end_line

def read_solution_names() -> Set[str]:
    print('Reading CMakeLists.txt!')
    prefix_len = len(SOLUTION_PREFIX)
    solutions = set()
    with open('CMakeLists.txt') as cmake_file:
        lines = cmake_file.readlines()
        for i, line in enumerate(lines):
            if line.startswith(SOLUTION_PREFIX):
                space_index = line.index(' ')
                solution_name = line[prefix_len + 1: space_index]
                solutions.add(solution_name)
    print(f'Currently you have made {len(solutions)} solutions!')
    return solutions


def add_solution(url: str):
    print('Adding new LeetCode solution......')
    if not url.startswith(LEETCODE_WEB_PREIX) and not url.startswith(LEETCODE_CN_WEB_PREIX):
        print('Wrong url!')
        exit(-1)
    # curr_soltions = get_curr_solutions()
    sol = new_solution_v2(url)
    sol.write_file()


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('No LeetCode url!')
        exit(-1)
    url = sys.argv[1]
    add_solution(url)
