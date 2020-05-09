package main

import "testing"

func TestIsNumber(t *testing.T) {
	var tests = []struct {
		s string
		b bool
	}{
		{
			s: "0",
			b: true,
		},
		{
			s: " 0.1",
			b: true,
		},
		{
			s: "abc",
			b: false,
		},
		{
			s: "1 a",
			b: false,
		},
		{
			s: "2e10",
			b: true,
		},
		{
			s: " -90e3",
			b: true,
		},
		{
			s: " 1e",
			b: false,
		},
		{
			s: "e3",
			b: false,
		},
		{
			s: " 6e-1",
			b: true,
		},
		{
			s: " 99e2.5",
			b: false,
		},
		{
			s: "53.5e93",
			b: true,
		},
		{
			s: " --6",
			b: false,
		},
		{
			s: "-+3",
			b: false,
		},
		{
			s: "95a54e53",
			b: false,
		},
		{
			s: "01",
			b: true,
		},
		{
			s: "3.",
			b: true,
		},
		{
			s: ".",
			b: false,
		},
		{
			s: "3. ",
			b: true,
		},
		{
			s: "+.8",
			b: true,
		},
		{
			s: "46.e3",
			b: true,
		},
	}

	for i, test := range tests {
		b := isNumber(test.s)
		if b != test.b {
			t.Errorf("%d, expect %t, but see %t", i, test.b, b)
		}
	}
}
