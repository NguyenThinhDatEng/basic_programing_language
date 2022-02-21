def containsDuplicate(nums):
    if len(nums) == 1:
        return True
    nums.sort()
    print(nums)
    for i in range(1, len(nums)):
        if (nums[i] == nums[i - 1]):
            return True
    return False

def main():
    print(containsDuplicate([1, 2, 3, 1]))

if __name__ == '__main__':
    main()
