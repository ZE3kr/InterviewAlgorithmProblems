package main

import "fmt"

func main() {
	fmt.Println(myPow(1.1, 22))
}

func myPow(x float64, n int) float64 {
	switch {
	case n < 0:
		return 1 / myPow(x, -n)
	case n == 0:
		if x == 0 {
			panic("Can't calculate 0 ^ 0")
		}
		return 1
	case n == 1:
		return x
	default:
		z := n / 2
		half := myPow(x, z)
		return half * half * myPow(x, n%2)
	}
}
