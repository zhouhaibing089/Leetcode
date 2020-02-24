package main

func main() {}

func removeDuplicates(nums []int) int {
	if len(nums) <= 1 {
		return len(nums)
	}

	var p = 1
	for _, num := range nums[1:] {
		// this is a duplicate
		if num == nums[p-1] {
			continue
		}
		nums[p] = num
		p++
	}

	return p
}
