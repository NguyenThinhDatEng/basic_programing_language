# draw the multiplication table
i = 1
while i < 11:
    j = 2
    line = ''
    while j < 10:
        line += f'{j}* {i:>2} = {i * j}' + '\t'
        j += 1
    print(line)
    i += 1
