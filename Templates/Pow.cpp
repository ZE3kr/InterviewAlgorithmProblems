/*** Pow ***/

template <class T> T myPow(T x, unsigned n) {
	if (n == 1) {
		return x;
	}
	unsigned z = n / 2;
	T half = myPow(x, z);
	if (n % 2) {
		return half * half * x;
	} else {
		return half * half;
	}
}

template <class T> T myPowMod(T x, unsigned n, unsigned mod) {
	if (n == 1) {
		return x%mod;
	}
	unsigned z = n / 2;
	T half = myPowMod(x, z, mod)%mod;
	if (n % 2) {
		return (half * half * x)%mod;
	} else {
		return (half * half)%mod;
	}
}

/*** Pow End ***/
