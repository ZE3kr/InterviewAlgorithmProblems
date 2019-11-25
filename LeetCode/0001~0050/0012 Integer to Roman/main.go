package main

import (
	"fmt"
	"strconv"
)

func main() {
	fmt.Println(intToRoman(0))
}

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

func intToRoman(num int) (ans string) {
	str := strconv.FormatInt(int64(num), 10)
	for i := 0; i < len(str); i++ {
		switch len(str) - i {
		case 4:
			switch str[i] {
			case '3':
				ans += "MMM"
			case '2':
				ans += "MM"
			case '1':
				ans += "M"
			}
		case 3:
			switch str[i] {
			case '9':
				ans += "CM"
			case '8':
				ans += "DCCC"
			case '7':
				ans += "DCC"
			case '6':
				ans += "DC"
			case '5':
				ans += "D"
			case '4':
				ans += "CD"
			case '3':
				ans += "CCC"
			case '2':
				ans += "CC"
			case '1':
				ans += "C"
			}
		case 2:
			switch str[i] {
			case '9':
				ans += "XC"
			case '8':
				ans += "LXXX"
			case '7':
				ans += "LXX"
			case '6':
				ans += "LX"
			case '5':
				ans += "L"
			case '4':
				ans += "XL"
			case '3':
				ans += "XXX"
			case '2':
				ans += "XX"
			case '1':
				ans += "X"
			}
		case 1:
			switch str[i] {
			case '9':
				ans += "IX"
			case '8':
				ans += "VIII"
			case '7':
				ans += "VII"
			case '6':
				ans += "VI"
			case '5':
				ans += "V"
			case '4':
				ans += "IV"
			case '3':
				ans += "III"
			case '2':
				ans += "II"
			case '1':
				ans += "I"
			}
		}
	}
	return ans
}
