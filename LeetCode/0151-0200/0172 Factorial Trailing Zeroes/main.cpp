// https://mp.weixin.qq.com/s/N72jpQVo4kqMCQxPfMhfMw

int trailingZeroes(int n){
    int ans = 0;
    unsigned long tmp = 5;
    while (tmp <= n) {
        ans += n/tmp;
        tmp *= 5;
    }
    return ans;
}

