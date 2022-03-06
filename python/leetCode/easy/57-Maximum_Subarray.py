'''
Way 01
sum + a[i] < 0 => sum = 0
sum + a[i] >= 0 => sum += a[i]
'''
# def maxSubArray(nums):
#     sum = 0
#     largest_sum = nums[0]
#     for i in range(len(nums)):
#         if (sum + nums[i] < 0):
#             sum = 0
#             largest_sum = max(largest_sum, nums[i])
#         else:
#             sum += nums[i]
#             largest_sum = max(largest_sum, sum)
#     return largest_sum

'''
Way 02
'''
def maxSubArray(nums):
    if not nums:
        return 0
    
    curSum = maxSum = nums[0]
    for i in nums[1:]:
        curSum = max(i, i + curSum)
        maxSum = max(maxSum, curSum)
    
    return maxSum

print(maxSubArray([-1, -2, 3]))
