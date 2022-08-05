package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	ans := ListNode{}
	listPointer := &ans
	sum := 0
	for l1 != nil && l2 != nil {
		sum += l1.Val + l2.Val
		l1, l2 = l1.Next, l2.Next
		listPointer.Next = &ListNode{Val: sum % 10}
		listPointer = listPointer.Next
		sum /= 10
	}
	for l1 != nil {
		sum += l1.Val
		l1 = l1.Next
		listPointer.Next = &ListNode{Val: sum % 10}
		listPointer = listPointer.Next
		sum /= 10
	}
	for l2 != nil {
		sum += l2.Val
		l2 = l2.Next
		listPointer.Next = &ListNode{Val: sum % 10}
		listPointer = listPointer.Next
		sum /= 10
	}
	for sum > 0 {
		listPointer.Next = &ListNode{Val: sum % 10}
		listPointer = listPointer.Next
		sum /= 10
	}
	return ans.Next
}
func main() {
	l1 := ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4, Next: &ListNode{Val: 9, Next: &ListNode{Val: 9, Next: &ListNode{Val: 9, Next: nil}}}}}}
	l2 := ListNode{Val: 9, Next: &ListNode{Val: 9, Next: &ListNode{Val: 9, Next: &ListNode{Val: 9, Next: nil}}}}
	ans := addTwoNumbers(&l1, &l2)
	for ans != nil {
		fmt.Print(ans.Val, ", ")
		ans = ans.Next
	}
}
