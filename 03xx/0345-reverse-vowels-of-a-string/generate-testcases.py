import random


def escape(c):
    if c == '"':
        return '\\"'
    if c == "\\":
        return "\\\\"
    return c


escChars = [escape(chr(i)) for i in range(32, 126)]


for _ in range(8):
    length = random.randint(1, 3 * 10**5)
    s = "".join(random.choices(escChars, k=length))
    print(f'"{s}"')
