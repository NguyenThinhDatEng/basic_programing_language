'''
Lambda - Ham an danh
lambda <arguments>: expression
'''

'''
custom sorting using lambda func as key parameter
'''
from functools import reduce


coordinates = [(-1, 3), (7, 9), (4, 2), (1, 0), (0, 10), (-2, 2), (-4, -5)]

# sort by x
print(sorted(coordinates))
# sort by y
print('\n', sorted(coordinates, key=lambda point: point[1]))
# sort by abs(x)
print('\n', sorted(coordinates, key=lambda point: abs(point[0])))

'''
map(func, seq): map
'''
words = ['bananas', 'a strawberry', 'an apple']
# Example: capitalize the first letter of each word
newWords = list(map(lambda word: word.title(), words))
print('\n', newWords)

'''
filter(func, seq): filter
lambda <args>: a condition
'''
# example: filter words containing the character e
filteredWords = list(filter(lambda word: word.find('e') > -1, words))
print('\n', filteredWords)

'''
reduce(func, seq)
func take 2 args
'''
numbers = [-1, 0, -8, 9, 1, 2, 3]
# Ex: calculate the sum of numbers
print('\n', reduce(lambda a,b: a+b, numbers))
# Ex: look for the max of list
print('\n', reduce(lambda a, b: max(a, b), numbers))

def main():
   pass

if __name__ == '__main__':
   main()