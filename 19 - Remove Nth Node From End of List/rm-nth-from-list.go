package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {

}

// removeNthFromEnd essentially constructs three pointers:
//
//       p    l    r
//       |    |    |
//  1 -> 2 -> 3 -> 4 -> 5
//
// where:
//   p: the parent of left
//   l: the left of scanning window
//   r: the right of scanning window
// (r - l + 1) = n is the size of window.
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	var parent *ListNode

	// initialize left and right
	left, right := head, head
	for i := 1; i < n; i++ {
		right = right.Next
	}

	for {
		// right is already the last one
		if right.Next == nil {
			// left is head
			if parent == nil {
				return left.Next
			}
			// remove left
			parent.Next = left.Next
			return head
		}

		// move the window towards right
		parent = left
		left = left.Next
		right = right.Next
	}
}
