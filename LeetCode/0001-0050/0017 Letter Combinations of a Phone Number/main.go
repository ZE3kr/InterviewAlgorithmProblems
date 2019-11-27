package main

import (
	"fmt"
)

func main() {
	fmt.Println(letterCombinations("234"))
}

func letterCombinations(digits string) (ans []string) {
	if len(digits) == 0 {
		return
	}
	keyMap := map[byte]string{
		'2': "abc",
		'3': "def",
		'4': "ghi",
		'5': "jkl",
		'6': "mno",
		'7': "pqrs",
		'8': "tuv",
		'9': "wxyz",
	}
	for _, k := range keyMap[digits[0]] {
		ans = append(ans, string(k))
	}
	for i := 1; i < len(digits); i++ {
		lenth := len(ans)
		for _, k := range ans {
			for _, j := range keyMap[digits[i]] {
				ans = append(ans, k+string(j))
			}
		}
		ans = ans[lenth:]
	}
	return ans
}
