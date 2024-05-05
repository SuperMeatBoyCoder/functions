import bisect
import math
import time

LETTERS = 'abcdefghijklmnopqrstuvwxyz'
INF = 2 * 10 ** 9
MOD = 10 ** 9 + 7


def intget():
    return int(input())


def lstget():
    return list(map(int, input().split()))


def strlstget():
    return input().split()


def strget():
    return input()


def bool_to_yesno(is_yes):
    if is_yes:
        print('YES')
    else:
        print('NO')


def func_range_get(f, number):
    return [f() for u in range(number)]


def set_precision_float(val, precision):
    return f"{val:.{precision}f}"


def set_precision_int(val, precision, fill=0):
    return f"{val:{fill}>{precision}d}"

def solve():
    pass


t = intget()
for _ in range(t):
    solve()
