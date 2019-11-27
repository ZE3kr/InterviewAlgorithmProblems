package main

import (
	"fmt"
)

func main() {
	fmt.Println(generateParenthesis(3))
}

func generateParenthesis(n int) (ans []string) {
	if n == 0 {
		return
	}
	ans = append(ans, "(")
	for i := 1; i < 2*n; i++ {
		length := len(ans)
		for _, k := range ans {
			all := 0
			unClosed := 0
			for _, c := range k {
				if c == '(' {
					all++
					unClosed++
				} else {
					unClosed--
				}
			}
			if all < n {
				ans = append(ans, k+"(")
			}
			if unClosed > 0 {
				ans = append(ans, k+")")
			}
		}
		ans = ans[length:]
	}

	return ans
}
