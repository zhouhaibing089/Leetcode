package main

func main() {

}

// ListNode is the definition for singly-linked list
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeKLists(lists []*ListNode) *ListNode {
	// base cases
	if len(lists) == 0 {
		return nil
	}
	if len(lists) == 1 {
		return lists[0]
	}

	var left, right *ListNode
	if len(lists) > 2 {
		// divide and conqur.
		left = mergeKLists(lists[0 : len(lists)/2])
		right = mergeKLists(lists[len(lists)/2:])
	} else {
		left = lists[0]
		right = lists[1]
	}

	// now we only need to merge left and right
	if left == nil {
		return right
	}
	if right == nil {
		return left
	}
	var head, tail *ListNode
	if left.Val < right.Val {
		head = left
		tail = left
		left = left.Next
	} else {
		head = right
		tail = right
		right = right.Next
	}

	for {
		if left == nil {
			tail.Next = right
			break
		}
		if right == nil {
			tail.Next = left
			break
		}
		if left.Val < right.Val {
			tail.Next = left
			tail = left
			left = left.Next
		} else {
			tail.Next = right
			tail = right
			right = right.Next
		}
	}

	return head
}
