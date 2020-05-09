package main

import "testing"

func TestFullJustify(t *testing.T) {
	var tests = []struct {
		in    []string
		width int
		out   []string
	}{
		{
			in: []string{
				"Science",
				"is",
				"what",
				"we",
				"understand",
				"well",
				"enough",
				"to",
				"explain",
				"to",
				"a",
				"computer.",
				"Art",
				"is",
				"everything",
				"else",
				"we",
				"do",
			},
			width: 20,
			out: []string{
				"Science  is  what we",
				"understand      well",
				"enough to explain to",
				"a  computer.  Art is",
				"everything  else  we",
				"do                  ",
			},
		},
		{
			in:    []string{"a"},
			width: 2,
			out:   []string{"a "},
		},
	}

	for i, test := range tests {
		out := fullJustify(test.in, test.width)
		if len(out) != len(test.out) {
			t.Errorf("%d: expect %v, but see %v", i, test.out, out)
			continue
		}
		for j, w := range out {
			if w != test.out[j] {
				t.Errorf("%d: expect %v, but see %v", i, test.out, out)
				break
			}
		}
	}
}
