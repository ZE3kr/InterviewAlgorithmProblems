func maxSubArray(arr []int) int {
	currSum := 0
	maxSum := arr[0]

	for _, v := range arr {
		if currSum > 0 {
			currSum += v
		} else {
			currSum = v
		}
		if maxSum < currSum {
			maxSum = currSum
		}
	}
	return maxSum
}
