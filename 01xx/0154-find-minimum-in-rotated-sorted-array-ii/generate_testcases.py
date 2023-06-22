import random

for _ in range(8):
    n = random.randint(1, 5000)
    nums = random.choices(range(-5000, 5001), k=n)
    nums.sort()
    k = random.randint(0, n - 1)
    rotated = nums[k : n - 1] + nums[0 : k - 1]
    print(rotated)
