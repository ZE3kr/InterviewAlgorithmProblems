package main

import (
	"fmt"
)

func main() {
	fmt.Println(lengthOfLastWord("Hello World "))
}

func lengthOfLastWord(s string) int {
	b := []byte(s)
	i := len(s) - 1
	length := len(s)
	for ; i >= 0 && b[i] == ' '; i-- {
		length--
	}
	for ; i >= 0 && b[i] != ' '; i-- {
	}
	return length - i - 1
}
