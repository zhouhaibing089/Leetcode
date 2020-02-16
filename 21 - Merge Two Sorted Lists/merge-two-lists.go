package main

func main() {}

// ListNode defines the node in a single-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	// base cases, if either of them is nil
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}

	// determine the head
	var head, tail *ListNode
	if l1.Val <= l2.Val {
		head, tail = l1, l1
		l1 = l1.Next
	} else {
		head, tail = l2, l2
		l2 = l2.Next
	}

	// scan through both lists
	for {
		if l1 == nil {
			tail.Next = l2
			break
		}
		if l2 == nil {
			tail.Next = l1
			break
		}

		if l1.Val <= l2.Val {
			tail.Next = l1
			tail = l1
			l1 = l1.Next
		} else {
			tail.Next = l2
			tail = l2
			l2 = l2.Next
		}
	}

	return head
}
