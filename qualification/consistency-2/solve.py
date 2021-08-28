#!/usr/bin/env python
import math
import sys
from collections import defaultdict, deque


def consistency(text, rules):
    rs = defaultdict(list)
    for a, b in rules:
        rs[a].append(b)

    dist = dict()
    for a, _ in rules:
        fringe = deque([(0, a)])
        while fringe:
            n, x = fringe.popleft()
            p = (a, x)
            if p in dist: continue
            dist[p] = n
            for b in rs.get(x, list()):
                fringe.append((n + 1, b))
    for a in text:
        dist[(a, a)] = 0

    best = float('inf')
    for b in set(k for _, k in dist):
        xs = [dist.get((a, b)) for a in text]
        if any(x is None for x in xs):
            continue
        best = min(best, sum(xs))
    return best if math.isfinite(best) else -1


def solve(fn):
    for index, (s, r) in enumerate(parse(fn), 1):
        print(f'Case #{index}: ', end='', flush=True)
        n = consistency(s, r)
        print(n, flush=True)


def parse(fn):
    with open(fn) as fp:
        T = int(next(fp))
        for _ in range(T):
            s = next(fp).strip()
            K = int(next(fp))
            r = list()
            for _ in range(K):
                r.append(next(fp).strip())
            yield s, r


if __name__ == '__main__':
    solve(*sys.argv[1:])
