package main

func main() {}

func fullJustify(words []string, maxWidth int) []string {
	var nspaces = func(n int) string {
		var b []byte = make([]byte, n)
		for i := 0; i < n; i++ {
			b[i] = ' '
		}
		return string(b)
	}

	var res []string
	var queue []string
	var width int
	for _, word := range words {
		if width+1+len(word) <= maxWidth {
			queue = append(queue, word)
			if width == 0 {
				width = len(word)
			} else {
				width = width + 1 + len(word)
			}
			continue
		}
		// if width is 0, it means there is no element in queue
		if width == 0 {
			res = append(res, word+nspaces(maxWidth-len(word)))
			continue
		}

		// case1: single word
		if len(queue) == 1 {
			res = append(res, queue[0]+nspaces(maxWidth-width))

			queue = []string{word}
			width = len(word)
			continue
		}
		// case2: multiple words
		var diff = maxWidth - width
		var quotient = diff / (len(queue) - 1)
		var remainder = diff % (len(queue) - 1)

		var entry string = queue[0]
		for j := 1; j < len(queue); j++ {
			var spaces = 1 + quotient
			if remainder > 0 {
				spaces++
				remainder--
			}
			entry = entry + nspaces(spaces) + queue[j]
		}
		res = append(res, entry)

		queue = []string{word}
		width = len(word)
	}

	// here it comes with the last line
	if len(queue) > 0 {
		var entry string = queue[0]
		for j := 1; j < len(queue); j++ {
			entry = entry + " " + queue[j]
		}
		entry += nspaces(maxWidth - width)

		res = append(res, entry)
	}

	return res
}
