import random

for _ in range(8):
    length = random.randint(1, 10**5)
    nums = random.choices(range(1, 10**6 + 1), k=length)
    target = random.randint(1, 10**6)
    print(nums)
    print(target)
