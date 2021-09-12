#!/usr/bin/env python
import struct
import subprocess
import sys


def timmy(S):
    def ipack(x): return x.to_bytes(4, 'little')
    data = S.encode()
    data = ipack(len(data)) + data
    p = subprocess.run(['./timmy'], input=data, stdout=subprocess.PIPE)
    ans, = struct.unpack('<I', p.stdout)
    return ans


def solve(fn):
    for index, problem in enumerate(parse(fn), 1):
        print(f'Case #{index}: ', end='', flush=True)
        ans = timmy(*problem)
        print(ans, flush=True)


def parse(fn):
    with open(fn) as fp:
        T = int(next(fp))
        for _ in range(T):
            N = int(next(fp))
            S = next(fp).rstrip()
            yield (S,)


if __name__ == '__main__':
    solve(*sys.argv[1:])
