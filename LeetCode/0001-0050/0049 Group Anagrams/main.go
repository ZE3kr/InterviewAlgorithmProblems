package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(groupAnagrams([]string{"eat", "tea", "tan", "ate", "nat", "bat"}))
}

func groupAnagrams(strs []string) (ans [][]string) {
	str := make(map[string][]string)
	for _, s := range strs {
		st := []byte(s)
		sort.Slice(st, func(i, j int) bool {
			return st[i] < st[j]
		})
		str[string(st)] = append(str[string(st)], s)
	}
	for _, k := range str {
		ans = append(ans, k)
	}
	return
}
