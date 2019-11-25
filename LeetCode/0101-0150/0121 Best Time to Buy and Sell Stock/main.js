/**
 * @param {number[]} prices
 * @return {number}
 */
function maxProfit(prices) {
	let min = Infinity;
	let profit = 0;
	for (let i = 0; i < prices.length; i++) {
		if(prices[i] < min) {
			min = prices[i];
		}
		if(prices[i] - min > profit) {
			profit = prices[i] - min;
		}
	}
	return profit;
}
