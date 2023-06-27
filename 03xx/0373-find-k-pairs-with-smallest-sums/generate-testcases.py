import random

for _ in range(8):
    length1 = random.randint(1, 10**5)
    length2 = random.randint(1, 10**5)
    nums1 = random.choices(range(-10**9, 10**9 + 1), k = length1)
    nums2 = random.choices(range(-10**9, 10**9 + 1), k = length2)
    nums1.sort()
    nums2.sort()
    k = random.randint(1, 10**4)
    print(nums1)
    print(nums2)
    print(k)
