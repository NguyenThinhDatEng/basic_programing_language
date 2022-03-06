'''
Way 01
'''
# def containsDuplicate(nums):
#     if len(nums) == 1:
#         return True
#     nums.sort()
#     print(nums)
#     for i in range(1, len(nums)):
#         if (nums[i] == nums[i - 1]):
#             return True
#     return False

'''
Way 02
'''


def containsDuplicate(nums):
    return len(nums) > len(set(nums))
