import os
import sys
from typing import List


def normal_vec_convert(s: str) -> str:
    s = s.replace('[', '{')
    s = s.replace(']', '}')
    return s


def char_vec_convert(l: List[str]) -> str:
    return '{' + ', '.join(['\'' + s + '\'' for s in l]) + '}'


if __name__ == '__main__':
    # if len(sys.argv) != 2:
    #     print('No argument!')
    #     exit(-1)
    print(char_vec_convert(["a","b","b","b","b","b","b","b","b","b","b","b","b"]))
