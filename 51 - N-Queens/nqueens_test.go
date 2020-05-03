package main

import (
	"fmt"
	"testing"
)

func TestSolveNQueen(t *testing.T) {
	for i, board := range solveNQueens(5) {
		fmt.Printf("solution %d:\n", i+1)
		for _, row := range board {
			fmt.Println(row)
		}
	}
}
