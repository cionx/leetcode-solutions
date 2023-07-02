import random

"""
Some test cases give the following error:
 Error when serializing long: out of range [-(2^53-1), 2^53-1]
I don’t know what LeetCode is doing, since only long long should be used, and
these have up to 2^63 - 1. But it is therefore best to check only one test case
as a time.
"""
n = random.randint(1, 10**5)
nums = random.choices(range(1, 10**6 + 1), k=n)
cost = random.choices(range(1, 10**6 + 1), k=n)
print(nums)
print(cost)
