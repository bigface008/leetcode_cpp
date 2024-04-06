import os
import sys

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('No argument!')
        exit(-1)
    str = sys.argv[1]
    str = str.replace('[', '{')
    str = str.replace(']', '}')
    print(str)
