try:
    # calculate S(x, n)
    x = int(input('Enter a number float: '))
    n = int(input('Enter the number of positive integers: '))
    i = 1
    x_power_of_i = x
    factorial = 1
    rs = 0
    while i <= n:
        if (i > 1):
            x_power_of_i *= x
        factorial *= i
        rs += x_power_of_i / factorial
        print(x)
        i += 1
    else:
        print('S =', rs)
except:
    print('Wrong Format')