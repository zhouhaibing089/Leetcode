package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Printf("%v\n", findSubstring("wordgoodgoodgoodbestword",
		[]string{"word", "good", "best", "word"},
	))
}

func findSubstring(s string, words []string) []int {
	wordToIndices := map[int][]int{}
	wordIndices := map[string]int{}
	indexToWords := map[int][]int{}
	n := len(words)
	if n <= 0 {
		return []int{}
	}

	for i, word := range words {
		if _, ok := wordIndices[word]; !ok {
			wordIndices[word] = i
		}
		// we already scanned this word, no need to update it again
		if indices, ok := wordToIndices[wordIndices[word]]; ok {
			for _, index := range indices {
				indexToWords[index] = append(indexToWords[index], i)
			}
			wordToIndices[i] = indices
			continue
		}
		offset := 0
		for {
			index := strings.Index(s[offset:], word)
			if index == -1 && offset == 0 {
				return []int{}
			}
			if index == -1 {
				break
			}
			// wordToIndices maps the word to a list of indices
			if _, ok := wordToIndices[i]; !ok {
				wordToIndices[i] = []int{}
			}
			wordToIndices[i] = append(wordToIndices[i], index+offset)

			// indexToWords maps the index to a list of words
			if _, ok := indexToWords[index+offset]; !ok {
				indexToWords[index+offset] = []int{}
			}
			indexToWords[index+offset] = append(indexToWords[index+offset], i)

			offset = offset + index + 1
		}
	}

	// visisted tracks whether the word has been visisted
	visisted := map[int]bool{}
	step := len(words[0])
	results := []int{}
	for i := 0; i < len(s); i++ {
		// Does this index point to any words?
		words, ok := indexToWords[i]
		if !ok {
			// reset to start point
			i = i - len(visisted)*step
			// clear the visisted history
			visisted = map[int]bool{}
			continue
		}
		success := false
		for _, word := range words {
			if visisted[word] {
				continue
			}
			visisted[word] = true
			success = true
			break
		}
		if success && len(visisted) != n {
			i = i + step - 1
			continue
		}
		if success {
			// reset to start point
			i = i - (n-1)*step
			// save the result
			results = append(results, i)
		} else {
			// we cann't find the next word, we have to rewind back
			// reset to start point
			i = i - len(visisted)*step
		}

		// clear the visisted history
		visisted = map[int]bool{}
	}

	return results
}
