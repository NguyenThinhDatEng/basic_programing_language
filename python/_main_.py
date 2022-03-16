from datetime import datetime
from re import M

def today():
    today = int(datetime.now().strftime('%w'))
    switchter = {
        0: 'Sunday',
        1: 'Monday',
        2: 'Tuesday',
        3: 'Wednesday',
        4: 'Thursday',
        5: 'Friday',
        6: 'Saturday',
    }
    print('Today is', switchter.get(today))

def year():
    print('Year is {}'.format(datetime.now().strftime('%Y')))


def main():
    today()
    year()
    print("Welcome to my program")

if __name__ == '__main__':
    main()
