def prefix(s):
    p = [0] * len(s)
    for i in range(1, len(s)):
        k = p[i - 1]

        while k > 0 and s[k] != s[i]:
            k = p[k - 1] # сброс счетчика если дальше равенство не продолжилось
            
            
        if s[k] == s[i]:
            k += 1

        p[i] = k

    return p

s = input().strip()

result = prefix(s)

print(" ".join(map(str, result)))