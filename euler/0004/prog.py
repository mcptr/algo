#!/usr/bin/env python

import sys


def is_palindrome(n):
    return str(n) == str(n)[::-1]


def find_max_palindrome(bottom, top):
    max_palindrome = 0
    b = t = 0
    for i in range(top, bottom - 1, -1):
        for j in range(bottom, top + 1):
            n = i * j
            if n > max_palindrome and is_palindrome(n):
                max_palindrome = n
                b = i
                t = j
    return (max_palindrome, b, t)


digits = int(sys.argv[1]) if len(sys.argv) > 1 else 3
bottom = 10 ** (digits - 1)
top = 10 ** digits - 1
print(find_max_palindrome(bottom, top))
