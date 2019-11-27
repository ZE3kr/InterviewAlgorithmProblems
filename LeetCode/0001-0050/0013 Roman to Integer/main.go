package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(romanToInt("MCMXCIV"))
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

func romanToInt(s string) (ans int) {
	shortCut := map[string]int{"CM": 900, "CD": 400, "XC": 90, "XL": 40, "IX": 9, "IV": 4}
	romanMap := map[byte]int{'M': 1000, 'D': 500, 'C': 100, 'L': 50, 'X': 10, 'V': 5, 'I': 1}
	for roman, num := range shortCut {
		ans += strings.Count(s, roman) * num
		s = strings.Replace(s, roman, "", -1)
	}
	for i := 0; i < len(s); i++ {
		ans += romanMap[s[i]]
	}
	return ans
}
