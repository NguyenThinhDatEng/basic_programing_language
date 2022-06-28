# 1. Define
myList = [1, 'one', True, None, ['Nguyen Thinh', 'SnakeTZZO', 'The Will']]
print('list[-1]: {}'.format(myList[-1]))

# 2. Python's built in enumerate function
for index, element in enumerate(myList, start = 1):
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
strList = ['banana', 'apple', 'grape', 'logan', 'watermelon']
print(f'strList: {strList}')
print(f'len(list): {len(strList)}')  # int
print(f'min: {min(strList)}') # int
print(f'max: {max(strList)}') # int
print(f'sorted(list): {sorted(strList)}') # list
print(f'list(reversed): {list(reversed(strList))}')
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
myList.pop()    # return the last of list
print(f'list.pop(): {myList}')
myList.pop(2)
print(f'myList.pop(index): {myList}')
myList.remove('10') # error or list
print(f'myList.remove(value): {myList}')
del myList[6]
print(f'del list[index]: {myList}')
# sort
strList.sort()
print(f'list.sort(): {strList}')
strList.sort(reverse = True)
print(f'list.sort(reverse = True): {strList}')
strList.reverse()
print(f'list.reverse(): {strList}')

# 5. slicing
nums = list(range(5))   # generate a list of elements 0 -> 4
print(nums)
print(nums[2:4])
print(nums[2:])
print(nums[:2])
print(nums[:])
print(nums[:-1])
nums[2:4] = ['two', 'three']
print(nums)