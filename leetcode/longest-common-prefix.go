package main

import (
	"fmt"
)

func longestCommonPrefix(strs []string) string {
	var ans string
	finish := true
	strs_len := len(strs)
	for idx := 0; idx < len(strs[0]); idx++ {
		finish = false
		temp_char := strs[0][idx]
		for i := 1; i < strs_len; i++ {
			// fmt.Println(len(strs[i]), idx, i)
			if len(strs[i]) <= idx || strs[i][idx] != temp_char {
				finish = true
				break
			}
		}
		if finish {
			break
		}
		ans += string(temp_char)
	}
	return ans
}
func main() {
	strs := []string{"dog", "racecar", "car"}
	n := longestCommonPrefix(strs)
	fmt.Println(n)
}
