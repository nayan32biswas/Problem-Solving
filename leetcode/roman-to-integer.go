package main

import (
	"fmt"
)

func romanToInt(s string) int {
	num := 0
	var store = map[rune]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}
	for idx, value := range s {
		if idx > 0 && store[value] > store[rune(s[idx-1])] {
			// fmt.Println(store[rune(s[idx-1])])
			num -= (store[rune(s[idx-1])] * 2)
		}
		num += store[value]

	}
	return num
}
func main() {
	n := romanToInt("MCMXCIV")
	fmt.Println(n)
}
