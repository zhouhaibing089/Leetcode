package main

import "testing"

func TestIsMatch(t *testing.T) {
	var tests = []struct {
		s     string
		p     string
		match bool
	}{
		{
			s:     "aa",
			p:     "a",
			match: false,
		},
		{
			s:     "aa",
			p:     "*",
			match: true,
		},
		{
			s:     "cb",
			p:     "?a",
			match: false,
		},
		{
			s:     "adceb",
			p:     "*a*b",
			match: true,
		},
		{
			s:     "acdcb",
			p:     "a*c?b",
			match: false,
		},
		{
			s:     "",
			p:     "*",
			match: true,
		},
		{
			s:     "c",
			p:     "*?*",
			match: true,
		},
	}

	for i, test := range tests {
		match := isMatch(test.s, test.p)
		if match != test.match {
			t.Errorf("%d: expect %t, but saw %t", i, test.match, match)
		}
	}
}
