package main

func main() {}

func isMatch(s string, p string) bool {
	type state struct {
		si int
		pi int
	}

	var stack []state = make([]state, len(p))
	var index = -1 // index into the stack

	var si, pi int // index of s, index of p

	var reset = func() {
		// reset to last state
		lastState := stack[index]
		index--
		si = lastState.si + 1
		pi = lastState.pi - 1
	}

	for {
		// both of them have reached to the end
		if si == len(s) && pi == len(p) {
			return true
		}
		// s reaches to end but p doesn't
		if si == len(s) {
			// p can only have `*`(s)
			for pi < len(p) {
				if p[pi] != '*' {
					return false
				}
				pi++
			}
			return true
		}
		// p reaches to end
		if pi == len(p) {
			if index == -1 {
				return false
			}
			reset()
			continue
		}

		// case 1: exact match
		// case 2: `?` matches with any single character
		if s[si] == p[pi] || p[pi] == '?' {
			si++
			pi++
			continue
		}
		// failed to match, we have to rewind
		if p[pi] != '*' {
			if index == -1 {
				return false
			}
			reset()
			continue
		}
		// we've observed a `*`, however we may see continuous `*`, find
		// the last one
		pnext := pi + 1
		// case 1(a): there are no more characters
		if pnext == len(p) {
			return true
		}
		// find the next non-`*` character
		for pnext < len(p) && p[pnext] == '*' {
			pnext++
		}
		// case 1(b): there are no more characters
		if pnext == len(p) {
			return true
		}

		// case 2: the next character matches with s[si]
		if p[pnext] == s[si] || p[pnext] == '?' {
			// push this position into our stack so we can rewind
			index++
			stack[index] = state{
				pi: pnext,
				si: si,
			}

			// continue the loop
			pi = pnext + 1
		}
		si++
	}
}
