
def convertor(hours, minutes, seconds):
    return hours * 3600 + minutes * 60 + seconds


def main():
    try:
        hours = int(input('Enter number of hours: '))
        minutes = int(input('Enter number of minutes: '))
        seconds = int(input('Enter number of seconds: '))
        print(convertor(hours, minutes, seconds))
    except:
        print('Input format error')

if __name__ == '__main__':
    main()