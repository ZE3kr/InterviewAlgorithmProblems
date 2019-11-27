package main

import (
	"fmt"
)

func main() {
	fmt.Println(countAndSay(5))
}

func countAndSay(n int) string {
	if n <= 1 {
		return "1"
	}
	next := []byte(countAndSay(n - 1))
	last := next[0]
	repeat := 1
	var ans []byte
	for _, k := range next[1:] {
		if k != last {
			ans = append(ans, '0'+byte(repeat), last)
			repeat = 1
			last = k
		} else {
			repeat++
		}
	}
	ans = append(ans, '0'+byte(repeat), next[len(next)-1])
	return string(ans)
}
