package main

func main() {}

func solveNQueens(n int) [][]string {
	result := [][]string{}

	board := make([][]byte, n)
	// initialize an empty board
	for i := 0; i < n; i++ {
		row := make([]byte, n)
		for j := 0; j < n; j++ {
			row[j] = '.'
		}
		board[i] = row
	}

	// see whether we are able to fill out the board
	var stack = make([]int, n) // the position where we can rewind
	var row = 0                // the row we are processing
	var init = 0               // the initial position to check
	for {
		var ok bool
		for i := init; i < n; i++ {
			// can we put 'Q' at board[row][i]
			// case 1: same column?
			for r := 0; r < row; r++ {
				if board[r][i] == 'Q' {
					goto NEXTCOLUMN
				}
			}
			// case 2: left diagonal
			for r := 0; r < row; r++ {
				col := i - (row - r)
				if col < 0 {
					continue
				}
				if board[r][col] == 'Q' {
					goto NEXTCOLUMN
				}
			}
			// case 3: right diagonal
			for r := 0; r < row; r++ {
				col := i + (row - r)
				if col >= n {
					continue
				}
				if board[r][col] == 'Q' {
					goto NEXTCOLUMN
				}
			}
			// we are legally to put 'Q' at this place
			board[row][i] = 'Q'
			stack[row] = i
			ok = true
			break
		NEXTCOLUMN:
		}
		// we've placed a 'Q' successfully
		if ok && row < (n-1) {
			row++
			init = 0
			continue
		}
		// we've observed one successful attempt
		if ok {
			rows := make([]string, n)
			for i, row := range board {
				rows[i] = string(row)
			}
			result = append(result, rows)

			// reset the last row
			board[row][stack[row]] = '.'
		}
		// we are not able to put 'Q' at the first row, quit
		if row == 0 {
			break
		}

		// rewind back and try the next possible column
		col := stack[row-1]
		board[row-1][col] = '.'

		row--
		init = col + 1
	}

	return result
}
