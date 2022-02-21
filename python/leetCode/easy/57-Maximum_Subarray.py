# sum + a[i] < 0 => sum = 0
# sum + a[i] >= 0 => sum += a[i]
def maxSubArray(nums):
    sum = 0
    largest_sum = nums[0]
    for i in range(len(nums)):
        if (sum + nums[i] < 0):
            sum = 0
            largest_sum = max(largest_sum, nums[i])
        else:
            sum += nums[i]
            largest_sum = max(largest_sum, sum)
    return largest_sum

