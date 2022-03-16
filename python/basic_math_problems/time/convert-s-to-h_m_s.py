
def convertor(seconds):
    # the integer part is the number of hours
    h = (seconds // 3600) % 24
    # the remainder is the number of minutes
    m = (seconds % 3600) // 60
    s = (seconds % 3600) % 60
    return [h, m, s]


def main():
    try:
        seconds = int(input('Enter number of seconds: '))
        h, m, s = convertor(seconds)
        print(f'{h}:{m}:{s}')
    except:
        print('Input format error')

if __name__ == '__main__':
    main()