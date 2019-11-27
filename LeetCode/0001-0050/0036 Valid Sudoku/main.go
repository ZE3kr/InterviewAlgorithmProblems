package main

import (
	"fmt"
)

func main() {
	fmt.Println(isValidSudoku([][]byte{{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}))
}

func isValidSudoku(board [][]byte) bool {
	for i := 0; i < 9; i++ {
		var check1 [9]bool
		var check2 [9]bool
		for j := 0; j < 9; j++ {
			if board[i][j] >= '0' && board[i][j] <= '9' {
				if check1[board[i][j]-'1'] {
					//fmt.Println("false1")
					return false
				}
				check1[board[i][j]-'1'] = true
			}
			if board[j][i] >= '0' && board[j][i] <= '9' {
				if check2[board[j][i]-'1'] {
					//fmt.Println("false2")
					return false
				}
				check2[board[j][i]-'1'] = true
			}
		}
	}
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			var check [9]bool
			for k := 0; k < 3; k++ {
				for l := 0; l < 3; l++ {
					if board[3*i+k][3*j+l] >= '0' && board[3*i+k][3*j+l] <= '9' {
						if check[board[3*i+k][3*j+l]-'1'] {
							//fmt.Println("false3")
							return false
						}
						check[board[3*i+k][3*j+l]-'1'] = true
					}
				}
			}
		}
	}
	return true
}
