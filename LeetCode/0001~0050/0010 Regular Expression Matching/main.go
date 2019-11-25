package main

import (
	"fmt"
)

func main() {
	fmt.Println(isMatch("abcdeffffabce", "a.cdef*m*.*e")) // True
	fmt.Println(isMatch("aa", "a*"))                      // True
	fmt.Println(isMatch("ab", ".*"))                      // True
	fmt.Println(isMatch("aab", "c*a*b"))                  // True
	fmt.Println(isMatch("aaa", "a*aa"))                   // True
	fmt.Println(isMatch("aaa", "ab*a*c*a"))               // True
	fmt.Println(isMatch("mississippi", "mis*is*p*."))     // False
	fmt.Println(isMatch("ab", ".*c"))                     // False
	fmt.Println(isMatch("aaa", "aaaa"))                   // False
	fmt.Println(isMatch("aa", "a"))                       // False
	fmt.Println(isMatch("baa", "c*c"))                    // False
}

func isMatch(s string, p string) bool {
	j := 0 //  For S
	lenP := len(p)
	lenS := len(s)
L1:
	for i := 0; i < lenP; {
		//fmt.Println("loop", j, i)
		if j >= lenS {
			if i == lenP {
				return true
			}
			i++
		} else if i < lenP-1 && p[i] == '.' && p[i+1] == '*' {
			if i == lenP-2 {
				//fmt.Println("case .*", j, i)
				i += 3
				return true
			} else {
				//fmt.Println("case .*?", j, i)
				for ; j < lenS; j++ {
					if s[j] == p[i+2] {
						i += 4
						j++
						continue L1
					}
				}
				//fmt.Println("false 1")
				return false
			}
			continue
		} else if i < lenP-1 && p[i+1] == '*' {
			//fmt.Println("case *", j, i)
			if i < lenP-2 {
				k := 0
				minJ := j
				for ; k < lenP-i-2; k++ {
					if p[k+i+2] != p[i] {
						break
					}
				}
				//fmt.Println(k)
				for ; j < lenS; j++ {
					if s[j] != p[i] {
						break
					}
				}
				j -= k
				if j < minJ {
					j = minJ
				}
			} else {
				for ; j < lenS; j++ {
					if s[j] != p[i] {
						break
					}
				}
			}
			i += 2
			continue
		} else if i < lenP && p[i] == '.' {
			//fmt.Println("case .", j, i)
			i++
			j++
			continue
		} else {
			//fmt.Println("case common", j, i)
			if i < lenP && s[j] == p[i] {
				i++
				j++
				continue
			}
		}
		//fmt.Println("false 2")
		return false
	}
	//fmt.Println(j)
	if j >= lenS {
		return true
	}
	//fmt.Println("false 3")
	return false
}
