/*** Palindrome ***/

bool isPalindrome(char input[]){
	size_t length = strlen(input);
	for(size_t i=0; i<length/2; i++){
		if(input[i]!=input[length-1-i]){
			return false;
		}
	}
	return true;
}

/*** Palindrome End ***/
