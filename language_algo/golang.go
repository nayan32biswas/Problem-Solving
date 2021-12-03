package main

import "fmt"

func find(arr []int, mid int) int {
	return arr[mid]
}
func binary_search_lower(arr []int, key int) int {
	mid := 0
	start := 0
	End := len(arr) - 1
	for End-start > 1 {
		mid = (start + End) / 2
		if find(arr, mid) < key {
			start = mid
		} else {
			End = mid
		}
	}
	if find(arr, End) <= key {
		return End
	}
	return start
}
func binary_search_upper(arr []int, key int) int {
	mid := 0
	start := 0
	End := len(arr) - 1
	for End-start > 1 {
		mid = (start + End) / 2
		if find(arr, mid) > key {
			End = mid
		} else {
			start = mid
		}
	}
	if find(arr, start) >= key {
		return start
	}
	return End
}

func main() {
	nums := []int{1, 4, 6, 6, 6, 7, 7, 8, 8} // (6, 2: pos), (7, 5: pos), (8, 7:pos)
	num := 7
	fmt.Println(binary_search_lower(nums, num))
	fmt.Println(binary_search_upper(nums, num))
}
