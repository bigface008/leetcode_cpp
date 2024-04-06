# Not in use!

import os.path
from typing import List, Tuple, Dict
import sys

SOLUTION_PREFIX = 'add_executable'
LEETCODE_WEB_PREIX = 'https://leetcode.com/problems/'

class LeetCodeSolution(object):
    def __init__(self, name: str, url: str, deps: List[str]):
        self.name = name
        self.url = url
        self.deps = deps


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
    return LeetCodeSolution(name, url, [dep])


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


def write_solutions(solutions: List[LeetCodeSolution], start_line: int, end_line: int):
    pass


cpp_template = """//
// {problem_url}
//

#include "leetcode_utils.hpp"

using namespace std;



int main() {{
    auto f = [](, int expect) {{
        auto output = ;
        leetcode_assert(output == expect, "{problem_name} expect={{}} output={{}}", expect, output);
    }};
    f();
}}
"""


def write_new_solution(sol: LeetCodeSolution):
    cpp_fn = 'leetcode/' + sol.deps[0]
    with open('./CMakeLists.txt', 'a') as f:
        f.write(f'{SOLUTION_PREFIX}({sol.name} {cpp_fn})\n')
    if not os.path.exists(sol.deps[0]):
        with open(cpp_fn, 'w') as f:
            f.write(cpp_template.format(problem_url=sol.url, problem_name=sol.name))
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
