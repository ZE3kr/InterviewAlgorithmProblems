/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
	let list = {};
	for (let i = 0; i < nums.length; i++) {
		if(list[nums[i]] === undefined) {
			list[nums[i]] = 1;
		} else {
			list[nums[i]]++;
		}
	}
	for(let i in list) {
		if(list.hasOwnProperty(i) && list[i] === 1) {
			return Number(i);
		}
	}
};
