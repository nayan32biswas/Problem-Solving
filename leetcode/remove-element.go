package main

import (
	"fmt"
)

func removeElement(nums []int, val int) int {
	pos := 0
	count := 0
	length := len(nums)
	if length == 0 {
		return 0
	}
	for i := 0; i < length; i++ {
		if nums[i] != val {
			nums[pos] = nums[i]
			pos++
			count++
		}
	}
	return count
}
func main() {
	nums := []int{0, 1, 2, 2, 3, 0, 4, 2}
	fmt.Println(removeElement(nums, 2))
	fmt.Println(nums)
}
