/*** Fliter Prime ***/

bool isPrimes[100000000];
int primes[5761455];
void filterPrime(int n) {
	int count = 0;
	for (int i = 2; i <= n; ++i) {
		isPrimes[i] = true;
	}
	isPrimes[2] = true;
	for (int j = 2; j <= n; ++j) {
		if (isPrimes[j]) {
			for (int m = 2; j * m <= n; ++m) {
				isPrimes[j * m] = false;
			}
		}
	}
	for (int k = 2; k <= n; ++k) {
		if (isPrimes[k]) {
			primes[count] = k;
			count++;
		}
	}
}

/*** Fliter Prime End ***/

/*** Timing Data ***/
/*** 1e6 21ms, 78498 primes ***/
/*** 5e6 114ms, 348513 primes ***/
/*** 1e7 274ms, 664579 primes ***/
/*** 2e7 543ms, 1270607 primes ***/
/*** 5e7 1540ms, 3001134 primes ***/
/*** 1e8 3192ms, 5761455 primes ***/
