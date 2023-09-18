def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)

    result = []
    i = j = 0
    
    while i < len(left_half) and j < len(right_half):
        if left_half[i] < right_half[j]:
            result.append(left_half[i])
            i += 1
        else:
            result.append(right_half[j])
            j += 1
    # добавляем один из оставшихся массивов (больший массив) в кон
    
    result.extend(left_half[i:])
    result.extend(right_half[j:])

    return result

n = int(input())
arr = list(map(int, input().split()))

sorted_arr = merge_sort(arr)

for num in sorted_arr:
    print(num, end=' ')
