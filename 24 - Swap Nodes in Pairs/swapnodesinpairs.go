package main

func main() {}

// ListNode is the definition for single linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	// swap the first pair
	head, tail := head.Next, head
	tail.Next = head.Next
	head.Next = tail

	for {
		if tail.Next == nil || tail.Next.Next == nil {
			break
		}
		first, second := tail.Next, tail.Next.Next
		first.Next = second.Next
		second.Next = first
		tail.Next = second

		tail = first
	}

	return head
}
