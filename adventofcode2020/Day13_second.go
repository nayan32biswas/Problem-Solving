package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type pair struct {
	value int
	inc   int
}

var MAX = 0
var SIZE = 0
var less_start = 0

func readFile(filename string) []string {
	file, _ := os.Open(filename)
	defer file.Close()
	var lines []string
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		lines = append(lines, line)
	}
	return lines
}

func extract(line string) []pair {
	pos := 0
	var arr []pair
	string_list := strings.Split(line, ",")
	for i := 0; i < len(string_list); i++ {
		if string_list[i] != "x" {
			temp, _ := strconv.Atoi(string_list[i])
			arr = append(arr, pair{value: temp, inc: i})
			if temp > MAX {
				pos = len(arr) - 1
				MAX = temp
			}
		}
	}
	SIZE = len(arr)
	less_start = arr[pos].inc
	for i := 0; i < len(arr)-1; i++ {
		arr[i].inc = arr[i+1].inc - 1
	}
	fmt.Println(arr, less_start)
	return arr
}

func range_check(value int, lo int, hi int) bool {
	// fmt.Println(value, lo, hi)
	if lo == hi {
		return lo%value == 0
	}
	if lo%value == 0 || hi%value == 0 || value/lo != value/hi {
		return true
	}
	return false
}

func check(buses []pair, start int) bool {
	if start%buses[0].value != 0 {
		return false
	}
	// fmt.Println(start)
	for i := 1; i < SIZE; i++ {
		if !range_check(buses[i].value, start+buses[i-1].inc+1, start+buses[i].inc) {
			return false
		}
	}
	return true
}

func findAns(buses []pair) int {
	ans := 0
	for i := MAX; i <= MAX*10; i += MAX {
		if check(buses, i-less_start) {
			ans = i - less_start
			break
		}
	}
	return ans
}

func main() {
	input := readFile("input.txt")
	buses := extract(input[1])
	fmt.Println(findAns(buses))
}

// 1068781
// 1868643
