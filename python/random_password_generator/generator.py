import string
'''
ascii_letters: string
digits: string
punctuation: string
'''

import random
'''
random.shuffle(mutableSequence): void
random.choices(list, k = int): list
'''

LETTERS = string.ascii_letters
NUMBERS = string.digits
PUNCTUATION = string.punctuation    # /ˌpʌŋktʃuˈeɪʃn/

def password_generator(length):
    printable = f'{LETTERS}{NUMBERS}{PUNCTUATION}'
    # convert to list
    printable = list(printable)
    # shuffle the characters in printable
    random.shuffle(printable)
    # random selection
    random_password = random.choices(printable, k = length)
    # convert to string
    password = ''.join(random_password)
    return password

def password_length():
    length = input("How long do you want your password: ")
    return int(length)

def main():
    length = password_length()
    password = password_generator(length)
    print(password)

if __name__ == '__main__':
    main()