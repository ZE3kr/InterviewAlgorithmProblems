function ListNode(val) {
	this.val = val;
	this.next = null;
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function reverseList(head) {
	let tmp = head;
	let prev = null;
	while (tmp != null) {
		let next = tmp.next;
		tmp.next = prev;
		prev = tmp;
		tmp = next;
	}

	if(head != null) {
		head.next = null;
	}

	return prev;
}
