package main

import "fmt"

func main() {
	for _, s := range generateParenthesis(4) {
		fmt.Println(s)
	}
}

// generateParenthesis generates all the well-formed parentheses combinations.
// n = 1: () push -> pop
// n = 2: ()() (()) push -> pop -> push -> pop push -> push -> pop -> pop
// n = 3: ()()() (()()) ()(()) ((())) (())()
func generateParenthesis(n int) []string {
	var results []string             // results
	var b []byte = make([]byte, n*2) // string builder
	var p int                        // number of open parentheses
	var c int                        // count of left parentheses

	// choices marks the locations where we have alternative choices
	var choices []int = make([]int, n)
	var indexes []int = make([]int, n)
	var ci int // index in choices
	for i := 0; i < n; i++ {
		choices[i] = -1
	}

	for {
		if c < n {
			if p > 0 {
				choices[ci] = (c-p)*2 + p
				indexes[ci] = c
				ci++
			}
			p++
			c++
			b[(c-p)*2+p-1] = '('
			continue
		}
		b[(c-p)*2+p] = ')'
		p--
		if p > 0 {
			continue
		}
		results = append(results, string(b))

		// look at choices
		for i := n - 1; i >= 0; i-- {
			if choices[i] != -1 {
				ci = i
				break
			}
		}
		if choices[0] == -1 {
			break
		}

		// change to pop at location ci
		b[choices[ci]] = ')'
		c = indexes[ci]
		p = 2*c - 1 - choices[ci]
		choices[ci] = -1
	}

	return results
}
