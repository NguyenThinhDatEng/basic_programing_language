from random import randrange

nextGame = True
while nextGame:
    print("Lucky number is in the range [1, 100]\nYou have 7 times to guess\nLet's guess now")
    # start game
    count = 1
    lucky_number = randrange(1,101)
    # guess
    while count <= 7:
        if count == 1:
            number = int(input('1st: '))
        elif count == 2:
            number = int(input('2nd: '))
        elif count == 3:
            number = int(input('3rd: '))
        else:
            number = int(input(f'{count}th: '))
        if number == lucky_number:
            print('Congrats, you guessed right. You are winner')
            break
        elif number < lucky_number:
            print('You should guess a bigger number. Good luck')
        else:
            print('You should guess a smaller number. Good luck')
        count += 1
    else:
        print('Sorry, You lost\nGAME OVER!')
    # end game
    reply = input('Do you want to play again?[Y/N]\n')
    if str(reply.lower()) == 'y':
        nextGame = True
    else:
        print('See you')
        nextGame = False



    