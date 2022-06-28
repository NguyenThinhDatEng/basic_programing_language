import numpy as np

a = np.array([0, 1, 2, 3])  # create 1 dim array
print(type(a))
print(a.shape)

a = np.array([[1, 2, 3], [4, 5, 6]])    # create 2 dim array
print(a.shape)

a = np.zeros(2)  # creat an array with all of elements are 0
b = np.ones(2)  # creat an array with all of elements are 1
c = np.full(2, 7)  # creat an array with all of elements are 7
print(a, b, c)
d = np.eye(3)  # create identity matrix
print(d)
e = np.random.random((2, 2))  # create an array, the elements are random
print(e)

# 