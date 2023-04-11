from typing import *


# 反转字符串
def reverseString(s: List[str]) -> None:
    s[:] = s[::-1]
    # Do not return anything, modify s in-place instead.


if __name__ == '__main__':
    s = ["h", "e", "l", "l", "o"]
    reverseString(s)
    print(s)
