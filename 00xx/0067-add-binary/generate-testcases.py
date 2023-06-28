import random

for _ in range(8):
    n = random.randint(1, 10**4)
    m = random.randint(1, 10**4)
    a = random.choices(["0", "1"], k = n)
    b = random.choices(["0", "1"], k = m)
    if a[0] == "0":
        a[0] = "1"
    if b[0] == "0":
        b[0] = "1"
    print(f"\"{''.join(a)}\"")
    print(f"\"{''.join(b)}\"")
