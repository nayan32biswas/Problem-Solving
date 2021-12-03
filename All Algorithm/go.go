package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"reflect"
	"regexp"
	"sort"
	"strconv"
)

type pair struct {
	i int
	j int
}

func readFile(filename string) []string {
	file, err := os.Open(filename)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	var lines []string
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		lines = append(lines, line)
	}
	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}
	return lines
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

func string_to_ints(line string) []int {
	re := regexp.MustCompile("[0-9]+")
	string_list := re.FindAllString(line, -1)
	arr := make([]int, len(string_list))
	for i := 0; i < len(string_list); i++ {
		arr[i], _ = strconv.Atoi(string_list[i])
	}
	return arr
}
func type_conv() {
	fmt.Println(reflect.TypeOf('F'))
}

func sorting() {
	setids := []int{3, 1, 5, 7, 12}
	sort.Sort(sort.IntSlice(setids))
	fmt.Println(setids)
}

func main() {
	sorting()
}
