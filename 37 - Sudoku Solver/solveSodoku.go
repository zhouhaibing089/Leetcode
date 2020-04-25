package main

func main() {}

// This solution uses DFS. This traverses every possible values for each cell.
func solveSudoku(board [][]byte) {
	var possibleValues = func(i, j int) []byte {
		m := make(map[byte]bool, 9)
		// scan rows
		for k := 0; k < 9; k++ {
			if board[i][k] == '.' {
				continue
			}
			m[board[i][k]] = true
		}
		// scan columns
		for k := 0; k < 9; k++ {
			if board[k][j] == '.' {
				continue
			}
			m[board[k][j]] = true
		}
		// scan grid
		gridRow, gridCol := i-i%3, j-j%3
		for kr := gridRow; kr < (gridRow + 3); kr++ {
			for kc := gridCol; kc < (gridCol + 3); kc++ {
				if board[kr][kc] == '.' {
					continue
				}
				m[board[kr][kc]] = true
			}
		}

		values := []byte{}
		for k := 1; k <= 9; k++ {
			if m[byte('0'+k)] {
				continue
			}
			values = append(values, byte(k+'0'))
		}
		return values
	}

	type action struct {
		row    int
		col    int
		values []byte
		index  int
	}
	var actions = make([]action, 81)
	var p int = -1

loop:
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[i][j] != '.' {
				continue
			}
			// find all the possible values
			values := possibleValues(i, j)
			if len(values) > 0 {
				// select the first value probed
				board[i][j] = values[0]
				p++
				actions[p] = action{
					row:    i,
					col:    j,
					values: values,
					index:  0, // the index of selected value
				}
				continue
			}

			for {
				action := actions[p]
				// all the choices have been tried out
				if (action.index + 1) == len(action.values) {
					board[action.row][action.col] = '.'
					p--
					continue
				}
				// we are gonna to try its second value
				index := action.index + 1
				board[action.row][action.col] = action.values[index]

				actions[p].index = index
				break
			}
			goto loop
		}
	}
}

// This is an enhanced version of above. Instead of using DFS blindly, we can try
// to be a little bit smarter. We can try DFS from the cell with minimal branches.
func solveSudoku2(board [][]byte) {
	var possibleValues = func(i, j int) []byte {
		m := make(map[byte]bool, 9)
		// scan rows
		for k := 0; k < 9; k++ {
			if board[i][k] == '.' {
				continue
			}
			m[board[i][k]] = true
		}
		// scan columns
		for k := 0; k < 9; k++ {
			if board[k][j] == '.' {
				continue
			}
			m[board[k][j]] = true
		}
		// scan grid
		gridRow, gridCol := i-i%3, j-j%3
		for kr := gridRow; kr < (gridRow + 3); kr++ {
			for kc := gridCol; kc < (gridCol + 3); kc++ {
				if board[kr][kc] == '.' {
					continue
				}
				m[board[kr][kc]] = true
			}
		}

		values := []byte{}
		for k := 1; k <= 9; k++ {
			if m[byte('0'+k)] {
				continue
			}
			values = append(values, byte(k+'0'))
		}
		return values
	}

	type action struct {
		row    int
		col    int
		values []byte
		index  int
	}
	var actions = make([]action, 81)
	var p int = -1

loop:
	minChoices := 10 // tracks the minimal choices observed
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[i][j] != '.' {
				continue
			}
			// find all the possible values
			values := possibleValues(i, j)
			if len(values) > 0 {
				// not our best choice
				if len(values) > minChoices {
					continue
				}
				minChoices = len(values)
				actions[p+1] = action{
					row:    i,
					col:    j,
					values: values,
					index:  0, // the index of selected value
				}
				continue
			}

			for {
				action := actions[p]
				// all the choices have been tried out, rollback.
				if (action.index + 1) == len(action.values) {
					board[action.row][action.col] = '.'
					p--
					continue
				}
				// we are gonna to try its next value
				index := action.index + 1
				board[action.row][action.col] = action.values[index]

				actions[p].index = index
				break
			}
			goto loop
		}
	}

	// Commit our best choice
	if minChoices < 10 {
		p++
		action := actions[p]
		board[action.row][action.col] = action.values[action.index]

		goto loop
	}
}
