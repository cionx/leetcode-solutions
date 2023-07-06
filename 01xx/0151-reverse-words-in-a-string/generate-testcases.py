import random

charRange = ['a', 'B', '1']
charRange.append(" ")

for _ in range(8):
    length = random.randint(1, 10**4)
    characters = random.choices(charRange, k=length)
    s = "".join(characters)
    print(f"\"{s}\"")

# Note: each run may produce an invalid test case (consisting only of spaces),
# with an extremly low probability of 1/30000.
# The probability that one of the eight test cases is invalid is then 0.00027,
# i.e., 0.027 percent.
