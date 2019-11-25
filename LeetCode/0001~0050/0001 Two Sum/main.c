#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target);

int main() {
	int a[6] = {1, 2, 3, 4, 5, 6};
	int *ans;
	ans = twoSum(a, 6, 5);
	printf("%d %d", ans[0], ans[1]);
}

int *twoSum(int *nums, int numsSize, int target) {
	int *result = malloc(2 * sizeof(int));
	int i, j;
	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				result[0] = i;
				result[1] = j;
				return result;
			}
		}
	}
	return result;
}
