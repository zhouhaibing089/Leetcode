package main

import (
	"fmt"
	"sort"
)

func main() {}

func minNumberOfSemesters(n int, dependencies [][]int, k int) int {
	// courses stores the graph.
	// Keyed by course number, valued by dependencies courses.
	courses := map[int]map[int]bool{}
	prerequisites := map[int]int{}

	for i := 1; i <= n; i++ {
		courses[i] = map[int]bool{}
	}

	for _, dep := range dependencies {
		courses[dep[1]][dep[0]] = true
		prerequisites[dep[0]] = prerequisites[dep[0]] + 1
	}

	var result = 0

	for {
		if len(courses) == 0 {
			return result
		}

		available := []int{}
		for id, deps := range courses {
			if len(deps) > 0 {
				continue
			}
			available = append(available, id)
		}

		// we need to sort it by comparing the prerequiste map
		sort.Slice(available, func(i, j int) bool {
			return prerequisites[available[i]] > prerequisites[available[j]]
		})

		for i := 0; i < k && i < len(available); i++ {
			fmt.Printf("[%d] choosing %d\n", result, available[i])
			delete(courses, available[i])
			for _, deps := range courses {
				delete(deps, available[i])
			}
		}

		result++
	}
}
