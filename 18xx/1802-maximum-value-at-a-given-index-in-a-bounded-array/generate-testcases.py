import random

for i in range(8):
    maxSum = random.randint(1, 10**9)
    n = random.randint(1, maxSum)
    index = random.randint(0, n - 1)

    print(n)
    print(index)
    print(maxSum)
