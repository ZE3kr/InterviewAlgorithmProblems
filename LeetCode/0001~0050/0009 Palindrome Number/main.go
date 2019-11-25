package main

import (
	"fmt"
	"strconv"
)

func main() {
	fmt.Println(isPalindrome(0))
}

func isPalindrome(x int) bool {
	str := strconv.FormatInt(int64(x), 10)
	for i := 0; i < len(str)/2; i++ {
		if str[i] != str[len(str)-1-i] {
			return false
		}
	}
	return true
}
