from typing import *


# 初级算法 - 字符串 - 反转字符串
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """


# 寻找数组的中心下标
def pivotIndex(nums: List[int]) -> int:
    l = len(nums)
    for i in range(0, l):
        if i == 0:
            if sum(nums[i + 1:l]) == 0:
                return i
        elif i == l - 1:
            if sum(nums[:i]) == 0:
                return i
        else:
            left_sum = sum(nums[:i])
            right_sum = sum(nums[i + 1:l])
            if left_sum == right_sum:
                return i
    return -1


# 搜索插入位置，leetcode复制过来把类方法参数self去掉
def searchInsert(nums: List[int], target: int) -> int:
    # 解法1：我的暴力解法过于冗余
    # length = len(nums)
    # for index, i in enumerate(nums):
    #     if index <= length-1:  # 在索引范围内
    #         if i == target:
    #             return index
    #         elif index < length-1 and i < target < nums[index + 1]:
    #             return index+1
    #         elif target < i:  # 特殊情况：小于首个元素
    #             return 0
    # if target > nums[-1]:  # 在索引范围外，直接放到最后一个
    #     return length
    # 解法2：标准的暴力解法很清爽，把情况完美合并
    # length = len(nums)
    # for i in range(length):
    #     if nums[i] >= target:
    #         return i
    # return length
    # 解法3：二分搜索
    length = len(nums)
    l, r = 0, length - 1
    while l <= r:
        mid = (l + r) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            l = mid + 1
        else:
            r = mid - 1
    return l  # 说明没有找到，要返回分界点位置


# 合并区间
def merge(intervals: List[List[int]]) -> List[List[int]]:
    intervals.sort(key=lambda x: x[0])
    count = len(intervals)  # 区间个数
    i = 0  # 索引
    while i < count - 1:
        ll = intervals[i][0]
        lr = intervals[i][1]
        rl = intervals[i + 1][0]
        rr = intervals[i + 1][1]
        # 4种需要合并的情况
        if ll <= rl <= lr <= rr:
            intervals.pop(i)
            count -= 1
            intervals.pop(i)
            count -= 1
            intervals.insert(i, [ll, rr])
            count += 1
            i -= 1  # 索引要回退一下
        elif rl <= ll <= rr <= lr:
            intervals.pop(i)
            count -= 1
            intervals.pop(i)
            count -= 1
            intervals.insert(i, [rl, lr])
            count += 1
            i -= 1
        elif rl <= ll <= lr <= rr:
            intervals.pop(i)
            count -= 1
            intervals.pop(i)
            count -= 1
            intervals.insert(i, [rl, rr])
            count += 1
            i -= 1
        elif ll <= rl <= rr <= lr:
            intervals.pop(i)
            count -= 1
            intervals.pop(i)
            count -= 1
            intervals.insert(i, [ll, lr])
            count += 1
            i -= 1
        i += 1
    return intervals


# 旋转矩阵
def rotate(matrix: List[List[int]]) -> None:
    print(1)


if __name__ == '__main__':
    matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    rotate(matrix)
