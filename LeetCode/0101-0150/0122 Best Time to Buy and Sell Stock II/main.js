/**
 * @param {number[]} prices
 * @return {number}
 */
function maxProfit(prices) {
	let profit = 0;
	for (let i = 0; i < prices.length-1; i++) {
		if(prices[i] < prices[i+1]) {
			profit += prices[i+1] - prices[i];
		}
	}
	return profit;
}
