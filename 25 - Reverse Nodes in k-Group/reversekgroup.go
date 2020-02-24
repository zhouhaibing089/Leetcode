package main

import "fmt"

func main() {
	// five := &ListNode{Val: 5}
	// four := &ListNode{Val: 4, Next: five}
	three := &ListNode{Val: 3, Next: nil}
	two := &ListNode{Val: 2, Next: three}
	one := &ListNode{Val: 1, Next: two}

	print(reverseKGroup(one, 4))
}

func print(l *ListNode) {
	if l == nil {
		fmt.Println()
		return
	}
	fmt.Printf("%d", l.Val)
	if l.Next != nil {
		fmt.Printf(" -> ")
	}
	print(l.Next)
}

// ListNode is the definition for single linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	if k == 1 || head == nil {
		return head
	}

	// end is the the last node in previous group
	var end, tmp, answer, final *ListNode
	var full bool
	begin, current, next := head, head, head.Next
	for {
		full = true
		for i := 1; i < k; i++ {
			if next == nil {
				full = false
				break
			}

			tmp = next.Next

			// reverse the pointer
			next.Next = current

			// reset current and next
			current = next
			next = tmp
		}

		if full {
			begin.Next = nil

			if end == nil {
				answer = current
			} else {
				end.Next = current
			}
			end = begin

			// exit if there is no more group
			if next == nil {
				return answer
			}

			begin, current, next = next, next, next.Next
			continue
		}

		// if it is not full, we need to revert
		final, next = current, current.Next
		for {
			if current == begin {
				break
			}

			tmp = next.Next
			next.Next = current
			current = next
			next = tmp
		}
		final.Next = nil

		if end == nil {
			return current
		}
		end.Next = current

		return answer
	}
}
