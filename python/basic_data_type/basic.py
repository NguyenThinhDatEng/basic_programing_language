# type
var = None
# Sign
var = 1E5  # 10^5
# Operator
var = 2**3  # 8
var = 2 / 3  # 0,66667
var = 2 // 3  # 0
# function
type(100)
round(10.123, 2)
bin(8)
hex(128)

# while condition: or for expression:
# else:
try:
    n = int(input('Enter the number of positive integers: '))
    i = 0
    sum = 0
    while n > 0:
        try:
            val = int(input(f'val{i + 1} = '))
            i += 1
            sum += val
            n -= 1
        except:
            print('Wrong Format')
        if (val == 0):
            print('Wrong Rules')
            break
    else:
        print('Average = ', sum / i)
except:
    print('Wrong Format')

