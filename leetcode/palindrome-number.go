package main

import (
	"fmt"
)

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	if x == 0 {
		return true
	}
	store := x
	n := 0
	for x != 0 {
		n = (n * 10) + x%10
		x /= 10
	}
	return store == n
}
func main() {
	n := isPalindrome(121)
	fmt.Println(n)
}
