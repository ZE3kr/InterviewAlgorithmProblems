package main

import "fmt"

func main() {
	fmt.Println(longestCommonPrefix([]string{"test", "hee"}))
}

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	if len(strs) == 1 {
		return strs[0]
	}
	minLength := len(strs[0])
	for _, str := range strs {
		if len([]byte(str)) < minLength {
			minLength = len([]byte(str))
		}
	}
	if minLength == 0 {
		return ""
	}
	var tempByte uint8
	length := -1
L1:
	for i := 0; i < minLength; i++ {
		tempByte = []byte(strs[0])[i]
		for _, str := range strs {
			if []byte(str)[i] != tempByte {
				break L1
			}
		}
		length = i
	}
	return strs[1][:length+1]
}
