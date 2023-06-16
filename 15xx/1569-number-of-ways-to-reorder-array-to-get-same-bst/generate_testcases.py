import random

for _ in range(8):
    n = random.randint(1, 1000)
    nums = list(range(1, n+1))
    random.shuffle(nums)

    print(nums)
