package main

func main() {}

func isNumber(s string) bool {
	// [spaces][sign][number][.][number][e][sign][number][spaces]
	//    0      1      2    3/4   5     6   7      8       10
	var state = 0

	for _, r := range s {
		// spaces
		if r == ' ' {
			if state == 0 || state == 10 {
				continue
			}
			if state == 1 || state == 3 || state == 6 || state == 7 {
				return false
			}
			if state == 2 || state == 4 || state == 5 || state == 8 {
				state = 10
				continue
			}
		}
		// sign
		if r == '+' || r == '-' {
			if state == 0 || state == 6 {
				state++
				continue
			}
			if state == 1 || state == 2 || state == 3 || state == 4 || state == 5 || state == 7 || state == 8 || state == 10 {
				return false
			}
		}
		// numbers
		if r >= '0' && r <= '9' {
			if state == 0 || state == 1 {
				state = 2
				continue
			}
			if state == 6 || state == 7 {
				state = 8
				continue
			}
			if state == 3 || state == 4 {
				state = 5
				continue
			}
			if state == 2 || state == 5 || state == 8 {
				continue
			}
			if state == 10 {
				return false
			}
		}
		if r == '.' {
			if state == 0 || state == 1 {
				state = 3
				continue
			}
			if state == 2 {
				state = 4
				continue
			}
			if state == 3 || state == 4 || state == 5 || state == 6 || state == 7 || state == 8 || state == 10 {
				return false
			}
		}
		if r == 'e' {
			if state == 2 || state == 4 || state == 5 {
				state = 6
				continue
			}
			if state == 0 || state == 1 || state == 3 || state == 6 || state == 7 || state == 8 || state == 10 {
				return false
			}
		}
		return false
	}
	return state == 2 || state == 4 || state == 5 || state == 8 || state == 10
}
