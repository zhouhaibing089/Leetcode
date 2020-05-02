package main

import (
	"testing"
)

func TestJump(t *testing.T) {
	var tests = []struct {
		nums  []int
		jumps int
	}{
		{
			nums:  []int{2, 3, 1, 1, 4},
			jumps: 2,
		},
	}

	for i, test := range tests {
		jumps := jump(test.nums)
		if jumps != test.jumps {
			t.Errorf("%d: expect %d, but see %d", i, test.jumps, jumps)
		}
	}
}
