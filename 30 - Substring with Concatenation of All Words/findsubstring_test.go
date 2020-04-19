package main

import "testing"

func TestFindSubstring(t *testing.T) {
	t.Logf("%v", findSubstring("wordgoodgoodgoodbestword",
		[]string{"word", "good", "best", "good"},
	))
}
