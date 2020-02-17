package main

import "fmt"

func main() {
	for _, s := range generateParenthesis(4) {
		fmt.Println(s)
	}
}

// generateParenthesis generates all the well-formed parentheses combinations.
func generateParenthesis(n int) []string {
	var results []string             // results
	var b []byte = make([]byte, n*2) // string builder

	var open int  // number of open left parentheses
	var count int // number of total left parentheses
	var stack [][2]int = make([][2]int, n)
	var p int = -1

	for {
		// closed = count -open
		// position = closed * 2 + open
		position := (count-open)*2 + open
		// we can still push `(`, then do it.
		if count < n {
			// we can close if there is open parentheses, push the
			// state into stack and we'll come back.
			if open > 0 {
				p++
				stack[p] = [2]int{count, open}
			}
			b[position] = '('
			// since we added left parentheses, the number of open/total
			// parentheses are both increased by one.
			open++
			count++
			continue
		}
		// all the left parentheses are used up, we need to close them
		// all now.
		b[position] = ')'
		open--
		if open > 0 {
			continue
		}
		// now open is 0 and count is n, so we have a result.
		results = append(results, string(b))

		// if there is no history state which we can change, it means we
		// have done all the work.
		if p < 0 {
			break
		}

		// pop up a history state, and change it to right parenthese, aka
		// decrease the open number.
		count, open = stack[p][0], stack[p][1]
		position = (count-open)*2 + open
		// change to pop at location ci
		b[position] = ')'
		open--

		p--
	}

	return results
}
