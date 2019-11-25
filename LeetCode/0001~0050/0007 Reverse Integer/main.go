package main

import "fmt"

func main() {
	fmt.Println(reverse(3718654))
}

func reverse(x int) (y int) {
	if x < 0 {
		return -reverse(-x)
	}
	if x == 0 {
		return 0
	}

	mod(&x, &y, 1000000000)
	mod(&x, &y, 100000000)
	mod(&x, &y, 10000000)
	mod(&x, &y, 1000000)
	mod(&x, &y, 100000)
	mod(&x, &y, 10000)
	mod(&x, &y, 1000)
	mod(&x, &y, 100)
	mod(&x, &y, 10)
	mod(&x, &y, 1)
	for y%10 == 0 {
		y /= 10
	}
	if y > 2147483647 {
		return 0
	}
	return y
}

func mod(x *int, y *int, digit int) {
	if *x >= digit {
		*y += (1000000000 / digit) * (*x / digit)
		*x = *x % digit
	}
}
