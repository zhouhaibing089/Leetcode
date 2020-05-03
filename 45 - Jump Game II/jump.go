package main

func main() {}

func jump(nums []int) int {
	// single element of array
	if len(nums) == 1 {
		return 0
	}

	var values = make([]int, len(nums))

	// start with the last element
	values[len(nums)-1] = 0
	for index := len(nums) - 2; index >= 0; index-- {
		// oooh, shit, we can not step into this
		if nums[index] == 0 {
			values[index] = -1
			continue
		}
		// calculate the minimal step
		var min = len(nums)
		for step := nums[index]; step >= 1; step-- {
			if (index + step) >= len(nums) {
				min = 0
				break
			}
			if values[index+step] == -1 {
				continue
			}
			if min > values[index+step] {
				min = values[index+step]
			}
		}
		values[index] = min + 1
	}

	return values[0]
}

// TODO: greedy algorithms.
