int cache[20] = {0};

int countDigitOne(int n){
    //printf("!");
    int init = n;
    int is9 = 1;
    int digit = 0;
    if(n < 1){
        return 0;
    }
    if(n < 10) {
        return 1;
    }
    int base = 1;
    while( n >= 10 ) {
        is9 = is9 && (n%10 == 9);
        n /= 10;
        base *= 10;
        ++digit;
    }
    is9 = is9 && (n == 9);
    if(is9){
        if(cache[digit]){
            //printf("-");
            return cache[digit];
        }
    }
    
    int ans;
    if(n > 1) {
        ans = (n) * countDigitOne(base-1) + base + countDigitOne(init - n * base);
    } else {
        ans = (n) * countDigitOne(base-1) - n * base + init + 1 + countDigitOne(init - n * base);
    }
    if(is9){
        cache[digit] = ans;
    }
    return ans;
}

