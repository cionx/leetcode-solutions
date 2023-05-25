import random

l = random.randint(1, 10 ** 5)
nums = random.choices([0, 1], k = l)

print(nums)
print(l)
