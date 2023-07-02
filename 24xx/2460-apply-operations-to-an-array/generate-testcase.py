import random

n = random.randint(2, 2000)
nums = random.choices(range(0, 10), k=n)

print(nums)
