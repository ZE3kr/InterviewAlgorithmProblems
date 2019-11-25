package main

import "fmt"

func main() {
	fmt.Println(lengthOfLongestSubstring("abcabcbb"))
}

func lengthOfLongestSubstring(s string) (longest int) {
	start := 0
	length := 0
	wordPlace := make(map[byte]int)
	for end := 0; end <= len(s)-1; end++ {
		if place, ok := wordPlace[s[end]]; ok {
			if place >= start {
				start = place + 1
			}
		}
		wordPlace[s[end]] = end
		length = end - start + 1
		if length > longest {
			longest = length
		}
	}
	return longest
}
