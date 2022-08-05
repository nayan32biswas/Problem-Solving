package main

import "fmt"

func twoSum(nums []int, target int) []int {
	mp := map[int]int{}
	for i := 0; i < len(nums); i++ {
		mp[nums[i]] = i
	}
	output := []int{0, 0}
	for i := 0; i < len(nums); i++ {
		if pos, ok := mp[target-nums[i]]; ok && i != pos {
			output[0] = i
			output[1] = pos
			break
		}
	}
	return output
}

func main() {
	nums := []int{2, 5, 5, 11}
	target := 10 // [1, 2]
	fmt.Println(twoSum(nums, target))

}
