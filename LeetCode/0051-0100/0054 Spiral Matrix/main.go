package main

import (
	"fmt"
)

func main() {
	fmt.Println(spiralOrder(
		[][]int{
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9},
		}))
}

func spiralOrder(matrix [][]int) (ans []int) {
	rows := len(matrix)
	if rows == 0 {
		return
	}
	cols := len(matrix[0])
	if cols == 0 {
		return
	}
	visited := make([][]bool, rows)
	ans = make([]int, rows*cols)
	for i := 0; i < rows; i++ {
		visited[i] = make([]bool, cols)
	}
	i, j := 0, 0
	// 0 right, 1 down, 2 left, 3 up
	move := 0
	for t := 0; t < rows*cols; t++ {
		var availableMove [4]bool
		ans[t] = matrix[i][j]
		visited[i][j] = true

		if j < cols-1 && !visited[i][j+1] {
			availableMove[0] = true
		}
		if i < rows-1 && !visited[i+1][j] {
			availableMove[1] = true
		}
		if j > 0 && !visited[i][j-1] {
			availableMove[2] = true
		}
		if i > 0 && !visited[i-1][j] {
			availableMove[3] = true
		}

		k := 0
		for !availableMove[move] {
			if k > 3 {
				return ans
			}
			move = (move + 1) % 4
			k++
		}

		switch move {
		case 0:
			j++
		case 1:
			i++
		case 2:
			j--
		case 3:
			i--
		}
	}
	return ans
}
