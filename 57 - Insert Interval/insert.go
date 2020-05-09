package main

func main() {}

func insert(intervals [][]int, newInterval []int) [][]int {
	var res = [][]int{}

	// state:
	// 0) before insertion
	// 1) in the middle of insertion
	// 2) after insertion
	var state int

	// the interval we would like to insert
	var start, end int

	for _, interval := range intervals {
		// in the left?
		if interval[0] > newInterval[1] {
			if state == 0 {
				res = append(res, newInterval)
				state = 2
			}
			if state == 1 {
				res = append(res, []int{start, end})
				state = 2
			}
			res = append(res, interval)
			continue
		}
		// in the right?
		if interval[1] < newInterval[0] {
			res = append(res, interval)
			continue
		}

		// interval[0] < newInterval[1] && interval[1] > newInterval[0]
		if state == 0 {
			if interval[0] < newInterval[0] {
				start = interval[0]
			} else {
				start = newInterval[0]
			}
			state = 1
		}
		if state == 1 {
			if interval[1] > newInterval[1] {
				end = interval[1]
			} else {
				end = newInterval[1]
			}
		}
	}
	if state == 0 {
		res = append(res, newInterval)
	}
	if state == 1 {
		res = append(res, []int{start, end})
	}

	return res
}
