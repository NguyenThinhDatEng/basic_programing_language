# 1. Define
myList = [1, 'one', True, None, ['Nguyen Thinh', 'SnakeTZZO', 'The Will']]

# 2. Python's built in enumerate function
for index, element in enumerate(myList):
    print(f'{index}: {element}')
print()

# 3. Operator (*, +): list
print(f'myList * 2: {myList * 2}')
print(f'myList + ["---end---"]: {myList + ["---end---"]}')
print()

# 4. function
# (1) not change list
# list.function
print(f'list.index(value): {myList.index("one")}')  # error or int
print(f'list.count(value): {myList.count(True)}') # int
print()
# function(list)
intList = [10, 49, 2, 20, 2022]
print(f'intList: {intList}')
print(f'sorted: {sorted(intList)}')
print(f'list(reversed): {list(reversed(intList))}')
print(f'len(list): {len(intList)}')  # int
print(f'max: {max(intList)}') # int
print(f'min: {min(intList)}') # int
print()

#(2) change list
# add elements at the end of list
myList.append(2022)
print(f'list.append(value): {myList}')
myList.extend(['18', '10', '2001'])
print(f'list.extend(list): {myList}')
# insert
myList.insert(2, [2, 'two'])
print(f'list.insert(index, value): {myList}')
# remove elements
myList.pop()
print(f'list.pop(): {myList}')
myList.pop(2)
print(f'myList.pop(index): {myList}')
myList.remove('10') # error or list
print(f'myList.remove(value): {myList}')
del myList[6]
print(f'del list[index]: {myList}')
# sort
intList.sort()
print(f'list.sort(): {intList}')
intList.reverse()
print(f'list.reverse(): {intList}')




