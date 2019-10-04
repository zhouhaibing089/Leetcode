package main

func main() {}

func search(nums []int, target int) int {
	n := len(nums)
	if n == 0 {
		return -1
	}
	m := n / 2
	if nums[m] == target {
		return m
	}
	if m == 0 {
		return -1
	}
	// right side is ordered
	if nums[m] <= nums[n-1] {
		if nums[m] < target && nums[n-1] >= target {
			// must be at right
			if index := binarySearch(nums[m:], target); index != -1 {
				return m + index
			}
			return -1
		}

		return search(nums[0:m], target)
	}

	// left side is ordered
	if nums[m] > target {
		if nums[0] <= target {
			// must be at left
			return binarySearch(nums[0:m], target)
		}
	}
	if index := search(nums[m:], target); index != -1 {
		return m + index
	}
	return -1
}

func binarySearch(nums []int, target int) int {
	m := len(nums) / 2
	if nums[m] == target {
		return m
	}
	if m == 0 {
		return -1
	}
	if nums[m] < target {
		if index := binarySearch(nums[m:], target); index != -1 {
			return m + index
		}
		return -1
	}
	return binarySearch(nums[0:m], target)
}
