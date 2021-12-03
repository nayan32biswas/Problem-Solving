package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func readFile(filename string) []int {
	file, err := os.Open(filename)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	var int_list []int
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		value, _ := strconv.Atoi(line)
		int_list = append(int_list, value)
	}
	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}
	return int_list
}

func check_okay(sort_list []int, value int) bool {
	for i := 0; i < len(sort_list); i++ {
		for j := i + 1; j < len(sort_list); j++ {
			if sort_list[i]+sort_list[j] == value {
				return true
			}
		}
	}
	return false
}

func find_ans_first(data_list []int, start_at int) int {
	sort_list := make([]int, start_at)
	copy(sort_list, data_list[:start_at])
	for i := start_at; i < len(data_list); i++ {
		if !check_okay(sort_list, data_list[i]) {
			return data_list[i]
		}
		ad := data_list[i]
		sort_list = sort_list[1:]
		sort_list = append(sort_list, ad)

	}
	return -1
}

func Min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func Max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func find_ans_second(data_list []int, invalid int) int {
	sum := data_list[0] + data_list[1]
	total_size := len(data_list)
	i := 0
	j := 1
	for j < total_size {
		if sum == invalid && j-i > 0 {
			min := 15690279
			max := 0
			for k := i; k <= j; k++ {
				min = Min(min, data_list[k])
				max = Max(max, data_list[k])
			}
			return min + max
		}
		if j < total_size-1 && sum+data_list[j+1] <= invalid {
			j++
			sum += data_list[j]
		} else {
			sum -= data_list[i]
			i++
		}
		// fmt.Println(sum, i, j)
	}
	return -1
}

func main() {
	data_list := readFile("input.txt")
	// fmt.Println(find_ans_first(data_list, 25))
	fmt.Println(find_ans_second(data_list, 15690279))
	// fmt.Println(find_ans_second(data_list, 127))

}

// 35 20 15 25 47     40 62 55 65 95
