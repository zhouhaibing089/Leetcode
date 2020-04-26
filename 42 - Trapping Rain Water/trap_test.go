package main

import (
	"fmt"
	"testing"
)

func TestTrap(t *testing.T) {
	var tests = []struct {
		height []int
		vol    int
	}{
		{
			height: []int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1},
			vol:    6,
		},
		{
			height: []int{5, 4, 1, 2},
			vol:    1,
		},
		{
			height: []int{5, 2, 1, 2, 1, 5},
			vol:    14,
		},
	}
	for i, test := range tests {
		fmt.Println()
		vol := trap(test.height)
		if vol != test.vol {
			t.Errorf("[%d]: expect %d, but get %d", i, test.vol, vol)
		}
	}
}
