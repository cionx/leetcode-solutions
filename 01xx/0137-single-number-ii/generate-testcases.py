import random

for _ in range(8):
    thriceLength = random.randint(0, 10**4 - 1)
    thrice = random.choices(range(-2**31, 2**31 - 1), k = thriceLength)
    thrice *= 3
    one = random.randint(-2**31, 2**31 - 1)
    nums = thrice + [one]
    random.shuffle(nums)
    print(nums)
