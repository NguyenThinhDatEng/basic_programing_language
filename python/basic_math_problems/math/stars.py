import time

try:
    n = int(input('Enter number of rows: '))
except:
    print('Wrong format')

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == 1 or i == n or j == 1 or j == n:
            print(' * ', end='')
        else:
            print('   ', end='')
    print()
print()

time.sleep(1)

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == n or j == n or i + j == n + 1 or j + i == n + 2:
            print(' * ', end='')
        else:
            print('   ', end='')
    print()
print()

m = 0
while m % 2 == 0:
    try:
        m = int(input('Enter number of rows (is an odd number): '))
    except:
        print('Wrong format')

time.sleep(1)
print()

halfOf_m = m // 2
for i in range(1, m + 1):
    for j in range(1, m + 1):
        if i == j or i == halfOf_m + 1 or (j == 1 and i <= halfOf_m) or (j == m and i > halfOf_m):
            print(' * ', end='')
        else:
            print('   ', end='')
    print()