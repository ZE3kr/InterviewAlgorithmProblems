package main

import "fmt"

func main() {
	fmt.Println(longestPalindrome("babad"))
}

func longestPalindrome(s string) (palindromicString string) {
	for length := len(s); length > 0; length-- {
	L1:
		for start := 0; start <= len(s)-length; start++ {
			for i := 0; i < length/2; i++ {
				if s[start+i] != s[start+length-1-i] {
					continue L1
				}
			}
			return s[start : start+length]
		}
	}
	return ""
}
