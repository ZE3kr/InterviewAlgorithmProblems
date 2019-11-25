/*
 * @see https://oeis.org/A000108
 */

function numTrees(n) {
	let cache = {};
	return calcNumTrees(n, cache)
}

function calcNumTrees(n, cache) {
	if( n <= 1 ) {
		return 1;
	}
	if( cache[n] !== undefined ) {
		return cache[n];
	}
	let ans = 0;
	for (let i = 0; i < n; i++) {
		ans += calcNumTrees(i, cache) * calcNumTrees(n - 1 - i, cache);
	}
	cache[n] = ans;
	return ans;
}
