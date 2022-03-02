import random

def game():
    # introduction
    print('\nWelcome to Scissor-Rock-Paper game')
    print('[S] = Scissor    [R] = Rock   [P] = Paper    [Q] = Quit\n')
    
    # variables
    signList = ['S', 'R', 'P', 'Q']
    selectedList = ['Scissor', 'Rock', 'Paper']
    counter = 1
    pointOfUser = pointOfComputer = 0

    # Run game
    while 1:
        # input
        print('{} User: {}     Computer: {}'.format(" " * 30, pointOfUser, pointOfComputer))
        print(' ' * 22 + '-' * 40)
        print('Game #{}'.format(counter))
        player_choice = input('Enter your choice: ')
        player_choice = player_choice.upper()

        # check input
        if (signList.count(player_choice) == 0):
            print('Your input is invalid. Please only enter characters in list: [S, R, P, Q]')
            continue

        if (player_choice == 'Q'):
            print('Thanks for joining. Have you a good day!')
            break
        
        # generate a random selection for the computer
        random_index = random.randint(0, 2)
        computer_choice = signList[random_index]
        # show result
        manWins = True
        print(f'You selected {selectedList[signList.index(player_choice)]}. The computer selected {selectedList[random_index]}')
        if (computer_choice == player_choice):
            print("It's a draw.")
        elif player_choice == 'S':
            if (computer_choice == 'P'):
                print(f'You won. Scissor cuts Paper')
                pointOfUser += 1
            else:
                print(f'The computer won. Rock beats Scissor')
                pointOfComputer += 1
        elif player_choice == 'R':
            if (computer_choice == 'S'):
                print(f'You won. Rock beats Scissor')
                pointOfUser += 1
            else:
                print(f'The computer won. Paper covers Rock')
                pointOfComputer += 1
        else:
            if (computer_choice == 'R'):
                print(f'You won. Paper covers Rock')
                pointOfUser += 1
            else:
                print(f'The computer won. Scissor cuts Paper')
                pointOfComputer += 1
        counter += 1


def main():
   game()

if __name__ == '__main__':
   main()