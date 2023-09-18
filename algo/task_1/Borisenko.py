def insert(root, value):
    
    # проверяется, существует ли корень (root)
    # Если корень пустой (равен None), то создается новый узел с заданным значением и двумя пустыми детьми (левым и правым).
    if root is None:
        return {"value": value, "left": None, "right": None}
    
    # в зависимости от того, меньше или больше value по сравнению с текущим корнем, функция рекурсивно вызывается 
    # для левого или правого поддерева, чтобы добавить элемент в соответствующем порядке.
    if value < root["value"]:
        root["left"] = insert(root["left"], value)
    elif value > root["value"]:
        root["right"] = insert(root["right"], value)
    
    return root

# рекурсивно вызывается для левого и правого поддеревьев 
# и возвращает максимальную высоту из них, увеличенную на 1, чтобы учесть текущий узел.
def height(root):
    if root is None:
        return 0
    
    left_height = height(root["left"])
    right_height = height(root["right"])

    print( root["value"])
    print(left_height, right_height)
    
    return max(left_height, right_height) + 1

# Создаем корень дерева
root = None

# Вводим последовательность чисел и строим дерево
input_data = input("Введите последовательность целых чисел, завершите ввод числом 0: ").split()

for num in input_data:
    num = int(num)
    if num == 0:
        break
    root = insert(root, num)

print(root)

# Вычисляем и выводим высоту дерева
tree_height = height(root)
print("Высота дерева:", tree_height)