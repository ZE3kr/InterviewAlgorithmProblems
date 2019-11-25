/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
	let list = {};
	for (let i = 0; i < nums.length; i++) {
		if(list[nums[i]] === undefined) {
			list[nums[i]] = true;
		} else {
			return true;
		}
	}
	return false;
};
