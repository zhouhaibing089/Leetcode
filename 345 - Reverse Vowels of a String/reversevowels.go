package main

import "fmt"

func main() {
	fmt.Println(reverseVowels("hello"))
}

func reverseVowels(s string) string {
	bs := []byte(s)
	m := map[byte]bool{
		'a': true,
		'A': true,
		'e': true,
		'E': true,
		'i': true,
		'I': true,
		'o': true,
		'O': true,
		'u': true,
		'U': true,
	}
	i, j := 0, len(bs)-1
	for i < j {
		if m[bs[i]] && m[bs[j]] {
			bs[i], bs[j] = bs[j], bs[i]
			i++
			j--
		}
		if !m[bs[i]] {
			i++
		}
		if !m[bs[j]] {
			j--
		}
	}
	return string(bs)
}
