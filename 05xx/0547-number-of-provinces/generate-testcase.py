import random

n = random.randint(1, 200)

matrix = []
for i in range(0, n):
    matrix.append(random.choices([0, 1], k=n))
    matrix[i][i] = 1

for i in range(0, n):
    for j in range(i + 1, n):
        matrix[i][j] = matrix[j][i]

print(list(matrix))
