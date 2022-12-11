package main

import (
	"bufio"
	"fmt"
	"os"
)

type new_type [][]rune

// Common

type pair struct {
	i int
	j int
}

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

var empty = rune('L')
var occupied = rune('#')
var ROW, COL int

var X = []int{-1, -1, -1, 0, 0, 1, 1, 1}
var Y = []int{-1, 0, 1, -1, 1, -1, 0, 1}

// Common End

func convert(lines []string) [][]rune {
	var state [][]rune
	for _, line := range lines {
		state = append(state, []rune(line))
	}
	return state
}

func count_empty(state [][]rune) int {
	coun := 0
	for i := 0; i < len(state); i++ {
		for j := 0; j < len(state[i]); j++ {
			if state[i][j] == occupied {
				coun++
			}
		}
	}
	return coun
}

func check_okay(x int, y int) bool {
	return 0 <= x && x < ROW && 0 <= y && y < COL
}

func is_occupied(state [][]rune, x int, y int, xinc int, yinc int) bool {
	x += xinc
	y += yinc
	for check_okay(x, y) {
		if state[x][y] == occupied {
			return true
		}
		if state[x][y] == empty {
			return false
		}
		x += xinc
		y += yinc
	}
	return false
}

func replace_each_point_second(state [][]rune, x int, y int) bool {
	coun := 0
	max := 5
	for i := 0; i < 8; i++ {
		if is_occupied(state, x, y, X[i], Y[i]) {
			coun++
		}
		if coun >= max {
			break
		}
	}
	if state[x][y] == empty && coun == 0 {
		return true
	}
	if state[x][y] == occupied && coun >= max {
		return true
	}
	return false
}

func replace_each_point_first(state [][]rune, x int, y int) bool {
	coun := 0
	max := 4
	var t_x, t_y int
	for i := 0; i < 8; i++ {
		t_x = x + X[i]
		t_y = y + Y[i]
		if check_okay(t_x, t_y) && state[t_x][t_y] == occupied {
			coun++
		}
		if coun >= max {
			break
		}
	}
	if state[x][y] == empty && coun == 0 {
		return true
	}
	if state[x][y] == occupied && coun >= max {
		return true
	}
	return false
}

func replace_state(state [][]rune) bool {
	is_replace := false
	var toggle []pair
	for i := 0; i < len(state); i++ {
		for j := 0; j < len(state[i]); j++ {
			if replace_each_point_second(state, i, j) {
				toggle = append(toggle, pair{i: i, j: j})
			}
		}
	}
	for _, p := range toggle {
		if state[p.i][p.j] == empty {
			state[p.i][p.j] = occupied
			is_replace = true
		} else if state[p.i][p.j] == occupied {
			state[p.i][p.j] = empty
			is_replace = true

		}
	}
	return is_replace
}
func print(state [][]rune) {
	for _, line := range state {
		for _, c := range line {
			fmt.Printf("%c", c)
		}
		fmt.Println()
	}
	fmt.Println()
}

func check(state [][]rune) int {
	for replace_state(state) == true {
	}
	// replace_state(state)
	// replace_state(state)
	// replace_state(state)
	// print(state)
	return count_empty(state)
}

func main() {
	input := readFile("input.txt")
	state := convert(input)
	ROW = len(state)
	COL = len(state[0])
	fmt.Println(check(state))
}
