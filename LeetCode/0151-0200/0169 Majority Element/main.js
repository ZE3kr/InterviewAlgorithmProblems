/**
 * @param {number[]} nums
 * @return {number}
 */
function majorityElement(nums) {
	let list = {};
	for (let i = 0; i < nums.length; i++) {
		if(list[nums[i]] === undefined) {
			list[nums[i]] = 1;
		} else {
			list[nums[i]]++;
		}
		if(list[nums[i]] > nums.length/2) {
			return nums[i];
		}
	}
}
