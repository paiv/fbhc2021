#!/usr/bin/env python
import struct
import subprocess
import sys


def dig(C, AB, K):
    def ipack(x): return x.to_bytes(4, 'little')
    def ipack8(x): return x.to_bytes(1, 'little')
    data = ipack(len(C))
    data += ipack(K)
    for x in C:
        data += ipack(x)
    for a,b in AB:
        data += ipack8(a - 1)
        data += ipack8(b - 1)
    p = subprocess.run(['./digger'], input=data, stdout=subprocess.PIPE)
    ans, = struct.unpack('<I', p.stdout)
    return ans


def solve(fn):
    for index, problem in enumerate(parse(fn), 1):
        print(f'Case #{index}: ', end='', flush=True)
        ans = dig(*problem)
        print(ans, flush=True)


def parse(fn):
    with open(fn) as fp:
        T = int(next(fp))
        for _ in range(T):
            N, K = map(int, next(fp).split())
            C = list(map(int, next(fp).split()))
            AB = [tuple(map(int, next(fp).split())) for _ in range(N-1)]
            yield C, AB, K


if __name__ == '__main__':
    solve(*sys.argv[1:])
