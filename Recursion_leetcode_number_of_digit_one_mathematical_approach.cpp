/*USING DP*/
/*----------------------------------------------------------------
/* Count of 1s till some no. n
0 - 10 -----> 1 ===> f(9)
0 - 100 ----> 10+10 = 20 ===> f(99) = 10f(9) + 10
0 - 1000 ---> 100+100+100 = 300 ===> f(999) = 10f(99) + 100
0 - 10000 --> 1000+1000+1000+1000 = 4000 & so on.....i.e Nth term has N-1 0s following it

Eg: 2407

at 1000s place (0 - 2000) ---> 1000(1000 to 1999 tk no. of 1 = 1000) + 2300(0 to 999 tk 300) ===> 1600
at 100s place (2000 - 2400) ---> 100 + 420 ===> 180
at 10s place (for 0) count = 0
at 1st place (2400 - 2407) ===> 1

i.e total no. of 1 till 2407 is ===> 1600+180+1 = 1781

Eg: 149

at 100s place (0 - 100) ---> 20(0 to 100 tk no. of 1 = 20) + 50(100 to 49 tk 50) ===> 70
at 10s place (100 - 140) ---> 10 + 4*1 ===> 14
at 1s place (140 - 149) ===> 1

i.e total no. of 1 till 149 is ===> 70+14+1 = 85

*/
/*
class Solution {
public:
//n,cnt of 1 in current string,x
int dp[11][11][2];

int fn(string &num, int n, bool x, int cnt){
    if(n==0) return cnt;
    if(dp[n][cnt][x] != -1) return dp[n][cnt][x];
    int ans=0;
    //decided the upper bound based on last digit
   int ub = x ? (num[num.length()-n]-'0') : 9;
    for(int dig=0;dig<=ub;dig++){
        int new_cnt = cnt;
        if(dig == 1) new_cnt++;
        ans += fn(num, n-1,  x&(dig==ub),  new_cnt);
    }
    return dp[n][cnt][x] = ans;
}
int countDigitOne(int n) {
    string num = to_string(n);
    memset(dp,-1,sizeof(dp));
    return fn(num, num.length(), 1, 0);
}
};*

/*USING MATHEMATICAL APPROACH*/
class Solution
{
public:
    int countDigitOne(int n)
    {
        int c = 0;
        for (long long i = 1; i <= n; i *= 10)
        {
            long long div = i * 10;
            c += (n / div) * i + min(max(n % div - i + 1, 0LL), i);
        }
        return c;
    }
};