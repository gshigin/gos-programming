def a_func(n, s):
    z = [0] * n
    for i in range(1, n - 1):
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
    return z

# Ввод данных
N = input()
S = input()

# Вычисление значения функции A
result = a_func(int(N), S)

# Вывод результатов
print(" ".join(map(str, result)))