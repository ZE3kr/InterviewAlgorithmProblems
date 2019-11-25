#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char *s);

int main() {
	printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
	printf("%d\n", lengthOfLongestSubstring("bbbbb"));
	printf("%d\n", lengthOfLongestSubstring("pwwkew"));
	printf("%d\n", lengthOfLongestSubstring(""));
}

int lengthOfLongestSubstring(char *s) {
	int start = 0, length = 0, end = 0, longest = 0;
	int wordPlace[256] = {};

	while (s[end] != '\0') {
		if (wordPlace[s[end]] != 0) {
			if (wordPlace[s[end]] >= start) {
				start = wordPlace[s[end]];
			}
		}
		wordPlace[s[end]] = end + 1;
		length = end - start + 1;
		if (length > longest) {
			longest = length;
		}
		end++;
	}
	return longest;
}
