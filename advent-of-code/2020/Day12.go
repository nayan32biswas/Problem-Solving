package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"math"
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

// Common End

// Assign
var state = make(map[rune]int)
var dir_key = make(map[rune]int)
var dir_change = []rune{'E', 'S', 'W', 'N'}


var north = rune('N')
var south = rune('S')
var east = rune('E')
var west = rune('W')
var left = rune('L')
var right = rune('R')
var forward = rune('F')
// Assign End

func change_direction(direction rune, action rune, degrees int) rune{
	pos := degrees/90
	if(action==left){
		if(pos==1){
			pos = 3
		}else if(pos==3){
			pos = 1
		}
	}
	pos += dir_key[direction]
	return dir_change[pos%4]
}

func move_ferry(direction rune, action rune, step int){
	if(action==forward){
		state[direction] += step
	}else{
		state[action] += step
	}
}

func abs(num int) int{
	return int(math.Abs(float64(num)))
}

func get_first_ans(arr []string) int {

	state['E'] = 0
	state['S'] = 0
	state['W'] = 0
	state['N'] = 0

	dir_key['E'] = 0
	dir_key['S'] = 1
	dir_key['W'] = 2
	dir_key['N'] = 3

	direction := rune('E')

	for _, data := range arr{
		// fmt.Printf("%c ",data[0])
		action := rune(data[0])
		step, _ := strconv.Atoi(data[1:])
		if(action==left || action==right){
			// prev := direction
			direction = change_direction(direction, action, step)
			// fmt.Printf("%d -> (%c to %c) : %c %d\n",i, prev, direction, action, step)
		} else{
			move_ferry(direction, action, step)
		}
	}
	// fmt.Println(state)
	return abs(state[east]-state[west])+abs(state[north]-state[south])
}

func main() {
	input := readFile("input.txt")
	fmt.Println(get_first_ans(input))
}
