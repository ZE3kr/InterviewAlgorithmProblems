function ListNode(val) {
	this.val = val;
	this.next = null;
}

function reverseBetween(head, m, n) {
	if( m === n ) {
		return head;
	}
	let tmp = head;
	let prev = null;
	let begin = null;
	let end = null;
	let before = null;
	let after = null;
	let iter = 0;
	while (tmp != null) {
		let next = tmp.next;
		iter++;

		switch (iter) {
			case m:
				before = prev;
				begin = tmp;
				break;
			case n:
				end = tmp;
				break;
			case n+1:
				after = tmp;
		}

		if(iter > m && iter <= n) {
			tmp.next = prev;
		}

		prev = tmp;
		tmp = next;
	}

	begin.next = after;
	if( before != null ) {
		before.next = end;
		return head;
	}

	return end;
}
