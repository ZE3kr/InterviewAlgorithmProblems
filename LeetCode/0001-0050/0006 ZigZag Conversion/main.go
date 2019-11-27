package main

import (
	"fmt"
)

func main() {
	fmt.Println(convert("PAYPALISHIRING", 4))
}

func convert(s string, numRows int) string {
	if numRows <= 1 {
		return s
	}
	ans := make([]byte, 0, len(s))
	for i := 0; i < cap(ans); i += (numRows - 1) * 2 {
		ans = append(ans, s[i])
	}
	for l := 2; l < numRows; l++ {
		for i := l - 1; i < cap(ans); i += (numRows - 1) * 2 {
			ans = append(ans, s[i])
			if i+(numRows-l)*2 < cap(ans) {
				ans = append(ans, s[i+(numRows-l)*2])
			}
		}
	}
	for i := numRows - 1; i < cap(ans); i += (numRows - 1) * 2 {
		ans = append(ans, s[i])
	}
	return string(ans)
}
