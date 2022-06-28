from base64 import b16encode
import numpy as np
# array, matrix, tensor
# shape, reshape, min, max, sum, len
# random, arange, ones, zeros, eye, full
# dot

a = np.array([0, 1, 2, 3])  # create 1 dim array
print('type(a)  ', type(a))
print('shape    ', a.shape)
print('dtype    ', a.dtype, '\n')

a = np.array([[1, 2, 3], [4, 5, 6]])    # create 2 dim array
print('shape    ', a.shape)
print('a[1, 2]  ', a[1, 2])

# create an array
a = np.zeros(2)  # all of elements are 0
b = np.ones(2)  # all of elements are 1
c = np.full(2, 7)  # all of elements are 7
d = np.arange(7)  # the elements are arraged from 0 to 6
print(a, b, c)
d = np.eye(3)  # create identity matrix
print(d)

np.random.seed(10)  # each number ~ a permanent array
e = np.random.random((2, 2))  # create an array, the elements are random
print(e)

a = np.array([  # create 3 dim array (tensor)
    [
        [1, 2, 3],
        [4, 5, 6]
    ],
    [
        [7, 8, 9],
        [1, 2, 3]
    ]
])
print('shape    ', a.shape, '\n')

b = np.array([1, 2, 3, 4, 5, 6])
# pass a tuple (number of rows, -1) || (number of rows, number of columns)
print(b, 'after reshape\n', b.reshape(2, -1))

# comparison
print('\n', b > 3)
print(b[b > 3])

# *, /
a = np.array([[1, 2], [2, 3]])
b = np.array([[3, 4], [4, 5]])
print("\na * b\n", a * b) # Element-wise multiplication matrix
print("a / b\n", a / b)
print("a.dot(b)\n", a.dot(b))
