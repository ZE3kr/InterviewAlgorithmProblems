#include <stdio.h>

char *longestPalindrome(char *s);

int main() {
	printf("%s\n",longestPalindrome("babad"));
	printf("%s\n",longestPalindrome("cbbd"));
	return 0;
}

char *longestPalindrome(char *s) {
	int len, length, start, i;
	for (i = 0; s[i] != '\0'; i++);
	len = i;

	for (length = len; length > 0; length--) {
		for (start = 0; start <= len - length; start++) {
			for (i = 0; i < length / 2; i++) {
				if (s[start + i] != s[start + length - 1 - i]) {
					goto L1;
				}
			}
			static char ans[1001];
			int j;
			for (j=0; j<length; j++){
				ans[j] = s[start+j];
			}
			ans[length] = '\0';
			return ans;
			L1:;
		}
	}
	static char ans[2] = "";
	return ans;
}
