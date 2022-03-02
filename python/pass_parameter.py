# required parameters and default parameters
def printNumber(a, b=18, c=10, d=2001):
    print(a, b, c, d)

# Variable-length parameters (*args: list, **kwargs: dict)

# If you mark a parameter with one asterisk (*),
# you can pass any number of positional arguments to your function (Typically called *args)
# If you mark a parameter with two asterisks (**),
# you can pass any number of keyword arguments to this function (Typically called **kwargs).
def printArgs(var, *args, **kwargs):
    print(var)

    for value in args:
        print(value)

    for key, value in kwargs.items():
        print(f'{key}: {value}')


def main():

    # positional args
    printNumber(2, 0, 1)
    # keyword args
    printNumber(d=0, a=2001, c=18, b=10)

    print()
    printArgs(100, 'Hello', 'Hi', "What's up", name='Will', age=20)

if __name__ == '__main__':
    main()