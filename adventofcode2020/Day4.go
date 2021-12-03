package main

import (
    "bufio"
    "fmt"
    "log"
	"os"
	"reflect"
	"sort"
)

func readFile(filename string)[]string{
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

func findPoint(data string, ch int32, start int, end int) int{
	for _, c := range data {
		mid := (start+end)/2
		if c==ch{
			end = mid
		}else{
			start =mid+1
		}
		// fmt.Println(start, mid, end)
	}
	return start
}

func findAns(line string) int{
	row := findPoint(line[:7], 'F', 0, 127)
	col := findPoint(line[7:], 'L', 0, 7)
	// fmt.Println(row, col)
	return row*8+col
}

func main() {
	fmt.Println(reflect.TypeOf('F'))
	lines := readFile("input.txt")
	var max int
	var setids []int
	for _, line := range lines {
		ans := findAns(line)
		setids = append(setids, ans)
		if ans>max{
			max = ans
		}
	}
	fmt.Println(max)
	
	sort.Sort(sort.IntSlice(setids))
	// fmt.Println(setids)
	for i, setid := range setids{
		if i==0{
			continue
		}
		if setid-setids[i-1]>1{
			fmt.Println(i, setid)
		}
	}
}