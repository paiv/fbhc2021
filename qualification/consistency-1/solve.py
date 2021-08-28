#!/usr/bin/env python
import string
import sys
from collections import Counter


def consistency(text):
    abc = set(string.ascii_uppercase)
    vowels = set('AEIOU')
    consonants = abc - vowels

    sv = [x for x in text if x in vowels]
    sc = [x for x in text if x in consonants]
    cv = Counter(sv)
    cc = Counter(sc)
    (mv,nv), = cv.most_common(1) if cv else ((0,0),)
    (mc,nc), = cc.most_common(1) if cc else ((0,0),)

    av = len(sc) + 2 * (len(sv) - nv)
    ac = len(sv) + 2 * (len(sc) - nc)
    return min(av, ac)


def solve(fn):
    for index, s in enumerate(parse(fn), 1):
        print(f'Case #{index}: ', end='', flush=True)
        n = consistency(s)
        print(n, flush=True)


def parse(fn):
    with open(fn) as fp:
        T = int(next(fp))
        for _ in range(T):
            s = next(fp).strip()
            yield s


if __name__ == '__main__':
    solve(*sys.argv[1:])
