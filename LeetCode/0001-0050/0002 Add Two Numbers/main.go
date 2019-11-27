package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	fmt.Println(&ListNode{1}, &ListNode{2})
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var l3 ListNode
	var add int
	l3.Val = l1.Val + l2.Val
	if l3.Val > 9 {
		add = 1
		l3.Val -= 10
	} else {
		add = 0
	}
	var next **ListNode
	next = &l3.Next
	for {
		if l1.Next == nil && l2.Next == nil {
			if add == 1 {
				var l4 ListNode
				l4.Val = add
				*next = &l4
			}
			break
		}
		var l4 ListNode
		if l1.Next != nil {
			l1 = l1.Next
		} else {
			l1 = &ListNode{0, nil}
		}
		if l2.Next != nil {
			l2 = l2.Next
		} else {
			l2 = &ListNode{0, nil}
		}
		l4.Val = l1.Val + l2.Val + add
		if l4.Val > 9 {
			add = 1
			l4.Val -= 10
		} else {
			add = 0
		}
		*next = &l4
		next = &l4.Next
	}
	return &l3
}
