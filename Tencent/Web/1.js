// 准备好了说下
// OK 了，能看到吗
// ok

/*四选3，做到 4.06
收到， 我在 IDE 里写
嗯嗯，时不时贴出来。我看看你的思路
*/
/**
 *
 * 第一题：实现 multiply
 * 要求：
 * multiply(1,2).result == 2
 * multiply(1,2)(3).result == 6
 * multiply(1,2)(3,4).result == 24
 * multiply(1,2)(3,4)(5).result == 120
 */
var multiply = function (a, b) {
	var multiply = function (c, d) {
		if(typeof d === 'undefined'){
			return {'result': a * b * c};
		}
		var e1 = 1;
		var multiply = function (e) {
			if(typeof e !== 'undefined'){
				e1 = e;
			}
			return {'result': a * b * c * d * e};
		};
		multiply.result = a * b * c * d * e1;
		return multiply;
	};

	multiply.result = a * b;

	return multiply;
};

// 第一题希望是，可以传无限参数，以及说调用任意次数的。
// 即 multiply(1,2,3,4,5,6,7,...)(...)(...)(...)(...)(...).result 都是可以的

// ok

function multiplyHelper(arguments, base) {
	let result = 1;
	for (let i = 0; i < arguments.length; i++){
		result *= arguments[i];
	}

	var multiply = function () {
		return multiplyHelper(arguments, result * base);
	};

	multiply.result = result * base;

	return multiply;
}

function multiply() {
	return multiplyHelper(arguments, 1);
}

/**
 * Skipped
 * 第二题：实现一个 superBaby:
 * 要求:
 * 输入：
 * superBaby("tom")
 * 输出:
 * I am tom
 *
 * 输入：
 * superBaby("tom").sleep(10).eat("apple").sleep(4).eat("cake")
 * 输出:
 * I am tom
 * (等待10秒)
 * Eating apple
 * (等待4秒)
 * Eating cake
 *
 * 输入：
 * superBaby("tom").eat("banana").sleepFirst(5).eat("apple")
 * 输出:
 * (等待5秒后)
 * I am tom
 * Eating banana
 * Eating apple
 */
function superBaby() {

}




/**
 * 第三题：给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 示例 1:
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。 偷窃到的最高金额 = 1 + 3 = 4 。
 * 示例 2:
 * 输入: [2,7,9,3,1]
 * 输出: 12
 * 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 */

// Dynamic Programming (Recursive + Cache)
// Complexity O(n)
function robHelper(houses, index, cache) {
	if (index >= houses.length) {
		return 0;
	}
	if (typeof cache[index] !== 'undefined') {
		return cache[index];
	}
	let a = houses[index] + robHelper(houses, index + 2, cache);
	let b = houses[index] + robHelper(houses, index + 3, cache);
	let c = houses[index + 1] + robHelper(houses, index + 3, cache);
	let d = houses[index + 1] + robHelper(houses, index + 4, cache);

	let r = a > b ? a : b;
	r = c > r ? c : r;
	r = d > r ? d : r;
	cache[index] = r;
	return r;
}

function rob(houses) {
	let cache = [];
	let a = robHelper(houses, 0, cache);
	let b = robHelper(houses, 1, cache);

	return a > b ? a : b;
}

/**
 * 第四题：微信负责企业文化的 HR 经常会举办各种活动，去年微信年会的时候， HR 赵组织了一堆的程序员玩起了集卡游戏。
 * 游戏规则非常有意思，每个人会被分配一张卡片，卡片上会有一个整数，每个人需要找到两位同伴（即三个人成组），组成一个小组去领取奖品，要求是这个小组中所有的人的数字相加起来的结果为 0 。
 * 此时 HR 赵，拿出了一个随机数组了，需要你吧所有可以分组的答案输出出来。


 * 举个例子：
 * 例如生成的数组是 [ -100, -200, 0, 300, 0, 4，96, 96]，
 * 那么答案是：
 * [
 *  [-200, -100, 300],
 *  [-100, 4, 96]
 * ]

 * 需要注意的是 活动要求组队中大家是平等的，没有先后顺序，答案不可以重复，例如 [-100, 4, 96], [4, 96, -100] 会被认同为同一个答案,因为所包含的数字是一样的
 * 要求：答案不能出错，运行速度尽量的快。
 */

/**
 * 计算组合情况
 * @param nums 随机数组
 * @return array 可以分组在一起的情况
 */
// 给多 15 min 看最后一题能不能做出来，做到 4.20
// 这边加了你微信，我们微信电话聊吧。座机聊，没有手打字
// 3sum
// Complexity: O(n ^ 2)

// TODO: skip 0, 0, 0; to integer
function gameAnswer(nums) {
	let rawAnswer = [];
	for (let i = 0; i < nums.length; i++){
		let two = twoSum(nums, -nums[i], i);
		for (let j = 0; j < two.length; j++){
			rawAnswer.push([two[j], -nums[i] - two[j], nums[i]]);
		}
	}

	let answerDict = {};
	for (let i = 0; i < rawAnswer.length; i++){
		rawAnswer[i].sort();
		answerDict[rawAnswer[i].join('_')] = true;
	}

	let answer = [];
	for (let key in answerDict){
		answer.push(key.split('_'));
	}

	return answer;
}

function twoSum(nums, target, skip) {
	let twoSumDict = {};
	let answer = [];
	for (let i = 0; i < nums.length; i++){
		twoSumDict[nums[i].toString()] = i;
	}
	for (let i = 0; i < nums.length; i++){
		if(typeof twoSumDict[(target - nums[i]).toString()] !== 'undefined' && twoSumDict[i] > i && i !== skip && twoSumDict[i] !== skip) {
			answer.push(nums[i]);
		}
	}
	return answer;
}
