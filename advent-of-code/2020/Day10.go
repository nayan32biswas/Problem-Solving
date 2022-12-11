package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"sort"
	"math"
)


// Common

func readFile(filename string) []int {
	file, _ := os.Open(filename)
	defer file.Close()
	var lines []int
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		value, _ := strconv.Atoi(line)
		lines = append(lines, value)
	}
	return lines
}

func get_first_ans(arr []int) int {
	one := 1
	three := 1
	for i:=1; i<len(arr); i++{
		change := arr[i]-arr[i-1]
		if(change==1){
			one++
		}else if(change == 3){
			three++
		}
	}
	return one*three
}

func get_second_ans(arr []int) int64 {
	temp := 0
	total := 0
	arr = append(arr, arr[len(arr)-1]+3)
	for i:=1; i<len(arr); i++{
		change := arr[i]-arr[i-1]
		if(change==1){
			temp++
		}else if(change == 3){
			if(temp>=1){
				fmt.Printf("%d, ", temp)
				total += temp-1
			}
			temp = 0
		}
	}
	fmt.Println(total)
	// TODO unsolved
	return int64(math.Pow(2, float64(total)))
}

func main() {
	input := readFile("input.txt")
	sort.Ints(input)
	// fmt.Println(get_first_ans(input))
	fmt.Println(get_second_ans(input))
}
