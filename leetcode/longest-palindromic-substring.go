package main

import "fmt"

func longestPalindrome(str string) string {
	start := 0
	maxLength := 1
	length := len(str)
	var low, high int
	for i := 1; i < length; i++ {
		low = i - 1
		high = i
		for low >= 0 && high < length && str[low] == str[high] {
			low--
			high++
		}

		low++
		high--
		if str[low] == str[high] && high-low+1 > maxLength {
			start = low
			maxLength = high - low + 1
		}
		low = i - 1
		high = i + 1
		for low >= 0 && high < length && str[low] == str[high] {
			low--
			high++
		}

		low++
		high--
		if str[low] == str[high] && high-low+1 > maxLength {
			start = low
			maxLength = high - low + 1
		}
	}
	return str[start : start+maxLength]
}
func main() {
	fmt.Println(longestPalindrome("abc"))
}
