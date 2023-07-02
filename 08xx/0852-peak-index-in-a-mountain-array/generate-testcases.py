import random

max_len = 10**5
max_val = 10**6

for _ in range(8):
    peak_value = random.randint(0, max_val)
    peak_index = random.randint(1, max_len - 1)

    left = random.choices(range(0, peak_value), k=peak_index)
    left = list(set(left))
    left.sort()

    right = random.choices(
        range(0, peak_value), k=max_len - peak_index - 1
    )
    right = list(set(right))
    right.sort()
    right.reverse()

    result = left + [peak_value] + right

    print(result)
