def twoSum(nums, target):
    # create a new list is sorted nums list 
    sortedNums = sorted(nums)
    # binary search
    def binarySearch(left, right, x):
        if left > right:
            return -1
        mid = (left + right) // 2
        if (sortedNums[mid] == x):
            return mid
        if (sortedNums[mid] < x):
            return binarySearch(mid + 1, right, x)
        return binarySearch(left, mid - 1, x)
    # algorithm
    val1 = val2 = -1 # value need to be found
    n = len(nums) - 1 # last index
    for index, value in enumerate(sortedNums):
        indexRs = binarySearch(index, n, target - value)
        if (indexRs > -1):
            val1 = sortedNums[index]
            val2 = sortedNums[indexRs]
            break
    rs = [] # result
    count = 2
    # find val1, val2 in nums to get index of val1, val2
    for index, value in enumerate(nums):
        if (val1 != 2E9 and value == val1):
            val1 = 2E9
            rs.append(index)
            count -= 1
        else:
            if (val2 != 2E9 and value == val2):
                val2 = 2E9
                rs.append(index)
                count -= 1
        if (count == 0):
            break
    return rs
        

if __name__ == '__main__':
    myList = [3, 2, 3]
    print(twoSum(myList, 9))