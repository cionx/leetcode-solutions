import random

n = random.randint(1, 3 * 10**4)

nums = random.choices(range(-10**4, 10**4 + 1), k = n)
nums.sort()

print(list(nums))
