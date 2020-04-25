package main

func main() {}

func firstMissingPositive(nums []int) int {
	if len(nums) == 0 {
		return 1
	}
	var index = 0
	var value int
	var tmp int
	for {
		if index >= len(nums) {
			break
		}
		value = nums[index]
		if value <= 0 || value > len(nums) || value == (index+1) {
			index++
			continue
		}
		// the value we would like to swap
		tmp = nums[value-1]
		if tmp == value {
			index++
			continue
		}
		nums[value-1] = value
		nums[index] = tmp
	}

	for i := 0; i < len(nums); i++ {
		if nums[i] != (i + 1) {
			return i + 1
		}
	}

	return len(nums) + 1
}
