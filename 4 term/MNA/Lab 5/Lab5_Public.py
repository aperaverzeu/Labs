# Собственные значения и векторы
import numpy as np

EPS = 10.0 ** -4
Variant = 5


def initial_input():
    c_matrix = np.array([
        [0.2, 0.0, 0.2, 0.0, 0.0],
        [0.0, 0.2, 0.0, 0.2, 0.0],
        [0.2, 0.0, 0.2, 0.0, 0.2],
        [0.0, 0.2, 0.0, 0.2, 0.0],
        [0.0, 0.0, 0.2, 0.0, 0.2]
    ])
    d_matrix = np.array([
        [2.33, 0.81, 0.67, 0.92, -0.53],
        [0.81, 2.33, 0.81, 0.67, 0.92],
        [0.67, 0.81, 2.33, 0.81, 0.92],
        [0.92, 0.67, 0.81, 2.33, -0.53],
        [-0.53, 0.92, 0.92, -0.53, 2.33]
    ])
    a = Variant * c_matrix + d_matrix
    return a


A = initial_input()
n = len(A)

# 3 

ansV = np.eye(n)
while True:
    max_element = (0, 1)
    for i in range(n):
        for j in range(i + 1, n):
            if abs(A[i][j]) > abs(A[max_element]):
                max_element = (i, j)
    (i, j) = max_element
    if A[i][i] == A[j][j]:
        p = np.pi / 4
    else:
        p = 2 * A[i][j] / (A[i][i] - A[j][j])
    c = np.cos(1 / 2 * np.arctan(p))
    s = np.sin(1 / 2 * np.arctan(p))
    V = np.eye(n)
    V[i][i] = c
    V[i][j] = -s
    V[j][i] = s
    V[j][j] = c
    A = V.T @ A @ V  # По практикуму рекомендуется расписать кучей формул
    ansV = ansV @ V
    if (((A ** 2).sum() - (np.diag(A) ** 2).sum()) / n) < EPS:
        ansW = np.diag(A)
        break

np.set_printoptions(suppress=True, precision=4, floatmode="fixed")

A = initial_input()
print("A = ")
print(A)

print("-----")
print("Ответ:")
(W, V) = (ansW, ansV)
print("Вектор собственных значений =")
print(W)
print("Столбцы - собственные векторы =")
print(V)

print("-----")
print("Проверка:")
(W, V) = np.linalg.eig(A)
print(W)
print(V)
