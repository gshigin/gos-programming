def insert(root, value):
    if root is None:
        return {"value": value, "left": None, "right": None}
    
    if value < root["value"]:
        root["left"] = insert(root["left"], value)
    elif value > root["value"]:
        root["right"] = insert(root["right"], value)
    
    return root

def find_leaves(root):
    if root is None:
        return []
    
    if root["left"] is None and root["right"] is None:
        return [root["value"]]
    
    left_leaves = find_leaves(root["left"])
    right_leaves = find_leaves(root["right"])
    
    return left_leaves + right_leaves

# Создаем корень дерева
root = None

# Вводим последовательность чисел и строим дерево
input_data =  input("Введите последовательность целых чисел, завершите ввод числом 0: ").split()
for num in input_data:
    num = int(num)
    if num == 0:
        break
    root = insert(root, num)

# Находим и выводим листья в порядке возрастания
leaves = find_leaves(root)
leaves.sort()
for leaf in leaves:
    print(leaf)