package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strconv"
)

// Common

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

func string_to_ints(line string) []int {
	re := regexp.MustCompile("[0-9]+")
	string_list := re.FindAllString(line, -1)
	arr := make([]int, len(string_list))
	for i := 0; i < len(string_list); i++ {
		arr[i], _ = strconv.Atoi(string_list[i])
	}
	return arr
}

func Min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func findAns(arrival int, buses []int) int {
	min := arrival
	id := 0
	for i := 0; i < len(buses); i++ {
		temp := buses[i] - (arrival % buses[i])
		// fmt.Println(buses[i], temp)
		if temp < min {
			id = buses[i]
			min = temp
		}
	}
	fmt.Println(id, min)
	return min * id
}

func main() {
	input := readFile("input.txt")
	arrival, _ := strconv.Atoi(input[0])
	buses := string_to_ints(input[1])
	fmt.Println(findAns(arrival, buses))
}
