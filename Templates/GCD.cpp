/*** GCD ***/

int gcd(int a, int b) {
	if (!b) {
		return a;
	}
	return gcd(b, a % b);
}

ll gcd(ll a, ll b) {
	if (!b) {
		return a;
	}
	return gcd(b, a % b);
}

ull gcd(ull a, ull b) {
	if (!b) {
		return a;
	}
	return gcd(b, a % b);
}

/*** GCD End ***/
