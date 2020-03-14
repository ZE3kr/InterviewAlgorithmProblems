/*** Big Mod ***/

unsigned long long mod(string a, unsigned long long b) {
	unsigned long long d = 0;
	for (unsigned long long i = 0; i < a.size(); i++)
		d = (d * 10 + (a[i] - '0')) % b;
	return d;
}

/*** Big Mod End ***/
