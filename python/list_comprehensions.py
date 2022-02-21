import math
# 1. Comprehensions
print()
word = "The Will"
print(f'word: {word}')
list01 = [c for c in word] # <<<<<----------
print(f'list characters of word: {list01}')
print()

numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(f'numbers list: {numbers}')
list02 = [var for var in numbers if var % 2 == 0] # <<<<<----------
print(f'list even numbers: {list02}')

def isPrime(n):
    if (n < 2):
        return False
    sqrtN = int(math.sqrt(n))
    for i in range(2, sqrtN + 1):
        if (n % i == 0):
            return False
    return True
list03 = [isPrime(n) for n in numbers] # <<<<<----------
print(f'is prime -> True: {list03}')

# 2. Function advanced
# sum
print(f'sum(list): {sum(numbers)}')
# zip(lists) -> zip
list04 = zip(list01, list02, list03) # <<<<<----------
list04 = list(list04)
print(f'list(zip(list01, list02, list03)): {list04}')
for x, y, z in list04:
    print(f'ofList1: {x}, ofList2: {y}, ofList3: {z}')
# sort(list, key = lambda el : el[index || key])
# {key : value} -> dictionary
print()
fruits = ['banana', 'apple', 'grape', 'logan', 'watermelon']
print(fruits)
print(f'sorted(list, key = lambda el: el[1]): {sorted(fruits, key = lambda el: el[1])}') # list
students = [{'name': 'Thinh', 'age': 20}, {'name': 'Anh', 'age': 20}, {'name': 'Huong', 'age': 18}]
print(students)
print(f'sorted(list, key = lambda el: el["name"]): {sorted(students, key = lambda el: el["name"])}') # list
# 3. 2D Array/List
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
# transform matrix to list
print()
list05 = [matrix[row][col] for row in range(len(matrix)) for col in range(len(matrix[0]))] # <<<<<----------
print(f'transform matrix to list: {list05}')
# combine columns with zip and *:
list06 = [x for x in zip(*matrix)] # <<<<<----------
print(f'combine columns with zip and *: {list06}')
print()
