'''
set of {key : value} (item)
key is unique (immutable: string, number, tuple)
a dictionary is equivalent a object (C++, Java)
'''

# 1. Create a dictionary
dict01 = dict(name = 'Nguyen Van Thinh', age = 20, birthDay = '18-10-2001', CPA = 3.19)
print(f'dict01: {dict01}')

# 2. Access items
print(f'value = dict["name"]: {dict01["name"]}')
print()

# 3. check for key

# (1)
key = 'name'
if key in dict01:
    print(f'dict01[{key}] is {dict01[key]}')
else:
    print('No found key')
# (2)
key = 'school'
try:
    print(f'{dict01[key]} exists')
except KeyError:
    print('No Key Found')

# 4. add an new item
print()
dict01['class'] = 'IT01'
print(dict01)
dict01['name'] = 'The Will'
print(dict01)

# 5. Delete item
print()
del dict01['class']
print(f'del dict01["class"]: {dict01}')
dict01.pop('age') # error or value
print(f'dict01.pop("age"): {dict01}')
dict01.popitem() # void
print(f'dict01.popitem(): {dict01}')
print()

# 6. Looping through Dictionary

# loop over keys
for key in dict01:
    print(f'{key}: {dict01[key]}')
print()

# loop over value
for value in dict01.values():
    print(value)
print()

# loop over items
for key, value in dict01.items():
    print(f'{key}: {value}')


    
