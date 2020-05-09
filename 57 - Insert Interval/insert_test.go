package main

import "testing"

func TestInsert(t *testing.T) {
	var tests = []struct {
		in  [][]int
		new []int
		out [][]int
	}{
		{
			in:  [][]int{[]int{1, 5}},
			new: []int{2, 3},
			out: [][]int{[]int{1, 5}},
		},
	}

	for i, test := range tests {
		out := insert(test.in, test.new)
		if len(out) != len(test.out) {
			t.Errorf("%d: expect %v, but see %v", i, test.out, out)
		}
		for j, v := range out {
			if v[0] != test.out[j][0] || v[1] != test.out[j][1] {
				t.Errorf("%d: expect %v, but see %v", i, test.out, out)
				break
			}
		}
	}
}
