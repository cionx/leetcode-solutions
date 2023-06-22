import random

for _ in range(16):
    length = random.randint(1, 1000)
    """
    We reduce the range of the entries of nums from [0, 1000] to [0, 100] to
    increase the number of duplicates.
    """
    nums = random.choices(range(0, 100), k=length)
    print(nums)
