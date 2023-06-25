import random

for _ in range(8):
    length1 = random.randint(1, 100)
    length2 = random.randint(1, 100)
    l1 = random.choices(range(0, 10), k = length1)
    l2 = random.choices(range(0, 10), k = length2)
    if l1[-1] == 0: l1[-1] = random.randint(1, 9)
    if l2[-1] == 0: l2[-1] = random.randint(1, 9)
    print (l1)
    print (l2)
