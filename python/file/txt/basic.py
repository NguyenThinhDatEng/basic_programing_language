'''
    open(file)
    ...
    close() ~ operating system
'''
# help(open) -> function
# read file
file = open('test.txt') # file is an iterable
'''
    mode = 
    r  -> only read - Default (file have to exist)
    r+ -> read and write      (file have to exist)
    w  -> delete the content of current file + write
    w+ -> w and r+
    a  -> write
    a+ -> write and read
'''
content = file.read() # if argument is empty or <0 => read all of lines in this file

file.seek(0) # move the pointer to the head of file
content = file.read(3)

file.seek(4)
content = file.read(1000)

file.seek(0)
content = file.readline()

file.seek(0)
content = file.readlines()
# constructor receive iterable
content = list(file)

print(content)

file.close()

# write file
# Each time using write. The file pointer will be placed immediately after the last character written.
# mode = 'w'
file = open('writeTest.txt', mode = 'w')

file.write('First line')
file.write('\n\n')
file.write('Second line')
file.write('\n\n')

file.close()

# mode = 'a'
file = open('writeTest.txt', mode = 'a')

file.write('Third line')

file.close()

'''
with expression [as variable]:
    with-block
=> At the end of with-block. File will be closed
'''
# way 01
with open('test.txt') as file:
    data = file.read()

# way 02
with (file := open('test.txt')):
    data = file.read()

print(data)