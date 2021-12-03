package main

import "fmt"

func myAtoi(s string) int {
	pos := 0
	length := len(s)
	if length == 0 {
		return 0
	}
	var c byte
	neg := false
	num := 0
	max := 2147483648

	for pos < length && s[pos] == ' ' {
		pos++
	}
	if pos < length && (s[pos] == '-' || s[pos] == '+') {
		neg = s[pos] == '-'
		pos++
		if pos < length && (s[pos] < '0' || s[pos] > '9') {
			return 0
		}
	}
	for pos < length {
		c = s[pos]
		if s[pos] < '0' || s[pos] > '9' {
			break
		}
		num = (num * 10) + int(c) - '0'
		if num >= max {
			break
		}
		pos++
	}

	if num >= max {
		num = max
		if !neg {
			num--
		}
	}

	if neg && num > 0 {
		return int(int32(num * -1))
	}
	return int(int32(num))
}

func main() {
	fmt.Println(myAtoi("9223372036854775808"))
}
