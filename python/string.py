# 1. Backslash \
# if you want to continue in the next line
from dataclasses import replace

print("I am Nguyen Van Thinh. I am studying at \
Ha Noi University of Science and Technology")
print()

# 2. Special sign
str = "0123456789"
print(f"str: {str}")
# Slicing
# : is called slicing
# has the format [start : end : step]
print(f"str[-1]: {str[-1]}")
print(f"str[-2]: {str[-2]}")
print()
# get substring following index i to j
print(f"str[:5]: {str[:5]}")  # 0 -> j - 1
print(f"str[5:]: {str[5:]}")  # i -> n
print(f"str[4:6]: {str[4:6]}")  # i -> j - 1
print()

# reverse string
print(f"s[::-1]: {str[::-1]}")
print()

# 3. Iterating
# check c exist in string?
if '123' in str:
    print("123 exists in str")
print()

# 4. Function

# str.isalnum(): bool
# str.join(iterable): string
list = {"thinhitnguyenvan", "toithienamxinnghe", "thinh.nv194178"}
print(f"list: {list}")
str = ' | '.join(list)
print(f"join by ' | ' : {str}")
print()

# str.strip(string): string
str = "   abc   "
print(f"   abc   .strip(): {str.strip()}")
str = "abcab"
print(f"abcab.strip(): {str.strip('ab')}")
print()

# str.split(string): list
str = "t.h.i.n.h.nv"
print(f"str: {str}")
list = str.split('.')
print(f"str.split('.'): {list}")

# str.replace(source, dest): string
s = str.replace('.', ' + ')
print(f"str.replace('.', ' + '): {s}")

# str.startswith(string): bool
print(f"str.startswith('t'): {str.startswith('t')}")
# str.endswith(string): bool
print(f"str.endswith('t'): {str.endswith('t')}")

# str.index(string): error or int
print(f"str.index('.'): {str.index('.')}")

# str.find(string): int (>= -1)
print(f"str.find('a'): {str.find('a')}")

# str.upper(): string -> capitalize all characters of the string
print(f"str.upper(): {str.upper()}")
# str.lower(): string -> lowercase all characters of the string
print(f"str.lower(): {str.lower()}")
# str.title(): string -> capitalize the characters at the beginning of each word
print(f"str.title(): {str.title()}")
# str.capitalize(): string  -> capitalize first character, lowercase all remaining characters
print(f"str.capitalize(): {str.capitalize()}")

# str.count(string): int
print(f"str.count('.'): {str.count('.')}")
print()

# 5. String formatting (3 types)
name = "NVT"
age = 20
height = 164.949
s1 = 'I am %s, %d years old. My height is %.2f cm' % (name, age, height)
s2 = 'I am {}, {} years old. My height is {:.2f} cm'.format(name, age, height)
s3 = f'I am {name}, {age} years old. My height is {height:.2f} cm'
print(s1)
print(s2)
print(s3)



