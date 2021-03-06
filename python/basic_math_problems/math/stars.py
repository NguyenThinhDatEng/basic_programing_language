import time

try:
    n = int(input('Enter number of rows: '))
except:
    print('Wrong format')
print()

count = 1

print('Figure 1')
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == 1 or i == n or j == 1 or j == n:
            print(' * ', end='')
        else:
            print('   ', end='')
    print()
print()

time.sleep(1)

print('Figure 2')
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == n or j == n or i + j > n:
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

print('Figure 3')
halfOf_m = m // 2
for i in range(1, m + 1):
    for j in range(1, m + 1):
        if i == j or i == halfOf_m + 1 or (j == 1 and i <= halfOf_m) or (j == m and i > halfOf_m):
            print(' * ', end='')
        else:
            print('   ', end='')
    print()
print()

time.sleep(1)

print('Figure 4')
for i in range(1, m + 1):
    for j in range(1, m + 1):
        if i <= halfOf_m + 1 and j > halfOf_m:
                if (j - i <= halfOf_m):
                    print(' * ', end='')
        elif (i > halfOf_m and j <= halfOf_m + 1):
                if i + j <= m + 1:
                    print(' * ', end='') 
        else:
            print('   ', end='')
    print()
print()

time.sleep(1)

print('Figure 5')
for i in range(1, m + 1):
    for j in range(1, m + 1):
        if i == halfOf_m + 1 or (j == halfOf_m + 1 and i <= halfOf_m) or (j == 1 and i > halfOf_m) or (j - i == halfOf_m):
            print(' * ', end='')
        elif i > halfOf_m and j + i == m + 1:
                print(' * ', end='')
        else:
            print('   ', end='')
    print()
print()

time.sleep(0.5)

print('Figure 6')
for i in range(1, m + 1):
    for j in range(1, m + 1):
        if i <= halfOf_m and j > halfOf_m:
                if (i + j <= m + 1):
                    print(' * ', end='')
        elif i > halfOf_m and j <= halfOf_m + 1 and i + j >= m + 1:
                print(' * ', end='') 
        else:
            print('   ', end='')
    print()
print()

time.sleep(0.5)

print('Figure 7')
for i in range(1, m + 1):
    for j in range(1, m + 1):
        if j == halfOf_m + 1 or (i == 1 and j > halfOf_m + 1) or (i == m and j <= halfOf_m) or (i + j == m + 1):
            print(' * ', end='')
        else:
            print('   ', end='')
    print()
print()