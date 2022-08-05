package main

import (
	"fmt"
)

func removeDuplicates(nums []int) int {
	pos := 1
	count := 1
	length := len(nums)
	if length == 0 {
		return 0
	}
	previous_value := nums[0]
	for i := 1; i < length; i++ {
		if nums[i] != previous_value {
			nums[pos] = nums[i]
			pos++
			count++
			previous_value = nums[i]
		}
	}
	return count
}
func main() {
	nums := []int{1, 1, 2}
	fmt.Println(removeDuplicates(nums))
	fmt.Println(nums)
}
