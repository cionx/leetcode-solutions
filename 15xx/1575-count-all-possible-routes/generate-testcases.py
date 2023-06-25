import random

for _ in range(8):
    # The list `locations` must not contain duplicate elements.
    length = random.randint(2, 100)
    locations = random.choices(range(1, 101), k=length)
    locations = list(set(locations))
    random.shuffle(locations)
    length = len(locations)
    # The rest is as usual.
    start = random.randint(0, length - 1)
    end = random.randint(0, length - 1)
    fuel = random.randint(1, 200)
    print(locations)
    print(start)
    print(end)
    print(fuel)
