package main

import "fmt"

var cache map[int][][]int

func main() {
	cache = map[int][][]int{}
	for i := 1; i < 100; i++ {
		if getPermutation(5, i) != getPermutation2(5, i) {
			fmt.Println("die", i, getPermutation(5, i), getPermutation2(5, i))
		}
	}
	for i := 60000; i < 61000; i++ {
		if getPermutation(9, i) != getPermutation2(9, i) {
			fmt.Println("die", i, getPermutation(9, i), getPermutation2(9, i))
		}
	}
}

func getPermutation(n int, k int) string {
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		nums[i] = i + 1
	}
	ans := getPermutationSlice(nums, k)
	var str []byte
	for _, k := range ans {
		str = append(str, uint8(k+'0'))
	}
	return string(str)
}

func getPermutationSlice(n []int, k int) []int {
	if k == 1 || len(n) == 1 || k > factorial(len(n)) {
		return n
	}
	if k == factorial(len(n)) {
		for i := 0; i < len(n)/2; i++ {
			n[i], n[len(n)-1-i] = n[len(n)-1-i], n[i]
		}
		return n
	}
	if k > factorial(len(n)-1) {
		temp := n[(k-1)/factorial(len(n)-1)]
		for i := (k - 1) / factorial(len(n)-1); i > 0; i-- {
			n[i] = n[i-1]
		}
		n[0] = temp
		k %= factorial(len(n) - 1)
		if k == 0 {
			k = factorial(len(n) - 1)
		}
	}
	getPermutationSlice(n[1:], k)

	return n
}

func factorial(n int) int {
	switch n {
	case 0:
		return 1
	case 1:
		return 1
	case 2:
		return 2
	case 3:
		return 6
	case 4:
		return 24
	case 5:
		return 120
	case 6:
		return 720
	case 7:
		return 5040
	case 8:
		return 40320
	default:
		if n > 8 {
			return n * factorial(n-1)
		}
		return 0
	}
}

func getPermutation2(n int, k int) string {
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		nums[i] = i + 1
	}
	var ans []int
	if key, f := cache[n]; f {
		ans = key[k-1]
	} else {
		cache[n] = permute(nums)
		ans = cache[n][k-1]
	}

	var str []byte
	for _, k := range ans {
		str = append(str, uint8(k+'0'))
	}
	return string(str)
}

func permute(nums []int) (ans [][]int) {
	switch len(nums) {
	case 1:
		ans = append(ans, nums)
		return ans
	case 0:
		return
	}
	for i, k := range nums {
		var input []int

		input = append(input, nums[:i]...)
		input = append(input, nums[i+1:]...)
		for _, l := range permute(input) {
			ans = append(ans, append([]int{k}, l...))
		}
	}
	return ans
}
