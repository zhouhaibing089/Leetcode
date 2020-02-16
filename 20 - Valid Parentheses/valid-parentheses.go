package main

func main() {
	isValid("()[]{}")
}

func isValid(s string) bool {
	// using a stack, and p points to the current element
	var stack []rune = make([]rune, len(s))
	var p int

	for _, c := range s {
		// push to stack
		if c == '(' || c == '{' || c == '[' {
			stack[p] = c
			p++
			continue
		}
		// otherwise pop stack
		if p == 0 {
			return false
		}
		if c == ')' && stack[p-1] != '(' {
			return false
		}
		if c == ']' && stack[p-1] != '[' {
			return false
		}
		if c == '}' && stack[p-1] != '{' {
			return false
		}
		p--
	}

	return p == 0
}
