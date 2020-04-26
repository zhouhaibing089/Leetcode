package main

func main() {}

func trap(height []int) int {
	if len(height) < 3 {
		return 0
	}
	length := len(height)

	// find the highest middle
	middle := 1
	for i := 2; i < (length - 1); i++ {
		if height[i] > height[middle] {
			middle = i
		}
	}
	// base case: middel is lower than left and right
	if height[middle] < height[0] && height[middle] < height[length-1] {
		var bar = height[0]
		if bar > height[length-1] {
			bar = height[length-1]
		}
		var vol int
		for i := 1; i < (length - 1); i++ {
			vol += (bar - height[i])
		}
		return vol
	}

	return trap(height[0:middle+1]) + trap(height[middle:])
}
