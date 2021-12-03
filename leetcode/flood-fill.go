package main

import (
	"fmt"
)

var m, n int
var R = []int{-1, 0, 1, 0}
var C = []int{0, 1, 0, -1}

func findAns(image [][]int, sr int, sc int, newColor int) [][]int {
	color := image[sr][sc]
	x, y := 0, 0

	image[sr][sc] = newColor
	for i := 0; i < 4; i++ {
		x, y = sr+R[i], sc+C[i]
		if color != newColor && x >= 0 && x < m && y >= 0 && y < n && image[x][y] == color {
			findAns(image, x, y, newColor)
		}
	}
	return image
}
func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
	m, n = len(image), len(image[0])
	return findAns(image, sr, sc, newColor)
}
func main() {
	// nums := [][]int{{0, 0, 0}, {0, 0, 0}} // 0, 0, 2
	nums := [][]int{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}} // 1, 1, 2
	// nums := [][]int{{0, 0, 0}, {0, 1, 1}} // 1, 1, 1
	fmt.Println(floodFill(nums, 1, 1, 2))
}
