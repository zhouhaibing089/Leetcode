package main

func main() {}

func longestValidParentheses(s string) int {
	var stack = make([]int, len(s))
	var closes = make([]int, len(s))
	var max = 0

	var p = -1
	for i, r := range s {
		closes[i] = -1

		if r == '(' {
			p++
			stack[p] = i
			continue
		}
		// no opennings at all
		if p < 0 {
			continue
		}
		// tracks the position which s[i] closes
		closes[i] = stack[p]

		// now we need to traverse through its previous record.
		var current = i - closes[i] + 1
		var prev = closes[i] - 1
		for prev > 0 {
			if s[prev] == '(' || closes[prev] == -1 {
				break
			}

			current = prev - closes[prev] + 1 + current
			prev = closes[prev] - 1
		}
		if current > max {
			max = current
		}

		p--
	}

	return max
}
