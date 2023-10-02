import random

for _ in range(8):
    length = random.randint(1, 100);
    nums = random.choices(range(1, 101), k=length)
    print(nums)
