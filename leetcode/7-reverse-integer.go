package main

import (
	"fmt"
)

func Abs(x int32) int32 {
	if x < 0 {
		return x * -1
	}
	return x
}

func reverse(x int) int {
	y := int32(x)
	var n int32 = 0
	var temp int32 = 0
	neg := x < 0
	y = int32(Abs(y))
	for y != 0 {
		temp = (n * 10) + y%10
		if int(temp) != (int(n)*10)+int(y)%10 {
			return 0
		}
		n = temp
		y /= 10
	}
	if neg {
		return int(n) * -1
	}
	return int(n)
}
func main() {
	n := reverse(1534236469)
	fmt.Println(n)
}
