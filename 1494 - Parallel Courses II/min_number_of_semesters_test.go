package main

import "testing"

func TestMinNumberOfSemesters(t *testing.T) {
	var tests = []struct {
		n            int
		dependencies [][]int
		k            int
		result       int
	}{
		{
			n: 8,
			dependencies: [][]int{
				{1, 6},
				{2, 7},
				{8, 7},
				{2, 5},
				{3, 4},
			},
			k:      3,
			result: 3,
		},
		{
			n: 9,
			dependencies: [][]int{
				{4, 8},
				{3, 6},
				{6, 8},
				{7, 6},
				{4, 2},
				{4, 1},
				{4, 7},
				{3, 7},
				{5, 2},
				{5, 9},
				{3, 4},
				{6, 9},
				{5, 7},
			},
			k:      2,
			result: 5,
		},
		{
			n: 6,
			dependencies: [][]int{
				{2, 5},
				{1, 5},
				{3, 5},
				{3, 4},
				{3, 6},
			},
			k:      2,
			result: 3,
		},
		{
			n: 9,
			dependencies: [][]int{
				{1, 4},
				{1, 5},
				{3, 5},
				{3, 6},
				{2, 6},
				{2, 7},
				{8, 4},
				{8, 5},
				{9, 6},
				{9, 7},
			},
			k:      3,
			result: 3,
		},
		{
			n: 10,
			dependencies: [][]int{
				{1, 5},
				{1, 6},
				{1, 7},
				{2, 5},
				{2, 6},
				{2, 7},
				{9, 10},
				{10, 5},
				{10, 6},
				{10, 7},
				{10, 8},
				{3, 5},
				{3, 6},
				{4, 5},
				{4, 6},
			},
			k:      2,
			result: 5, // 1, 2 --> 4, 9 --> 3, 10 --> 8, 6 --> 5, 7
		},
	}

	for i, test := range tests {
		result := minNumberOfSemesters(test.n, test.dependencies, test.k)
		if result != test.result {
			t.Errorf("%d: expect %d, but get %d", i, test.result, result)
		}
	}
}
