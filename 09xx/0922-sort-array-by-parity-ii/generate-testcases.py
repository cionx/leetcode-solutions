import random

for _ in range(8):
    length = random.randint(1, 10**4)
    evens = random.choices(range(0, 501), k = length)
    evens = list(map((lambda x: 2 * x), evens))
    odds = random.choices(range(0, 500), k = length)
    odds = list(map((lambda x: 2 * x + 1), odds))
    nums = evens + odds;
    random.shuffle(nums)
    print(nums)
