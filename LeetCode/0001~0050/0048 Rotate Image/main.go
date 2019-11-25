package main

import (
	"fmt"
)

func main() {
	a := [][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
	rotate(a)
	fmt.Println(a)
}

func rotate(matrix [][]int) {
	for m := 0; m < 3; m++ {
		n := len(matrix)
		newMatrix := make([][]int, n)

		for i := 0; i < n; i++ {
			newMatrix[i] = make([]int, n)
		}

		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				newMatrix[i][j] = matrix[j][i]
			}
		}

		for i := 0; i < n/2; i++ {
			newMatrix[i], newMatrix[n-1-i] = newMatrix[n-1-i], newMatrix[i]
		}

		copy(matrix, newMatrix)
	}
}
