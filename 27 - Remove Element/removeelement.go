package main

func main() {}

func removeElement(nums []int, val int) int {
	var p int = 0
	for _, num := range nums {
		if num == val {
			continue
		}
		nums[p] = num
		p++
	}

	return p
}
