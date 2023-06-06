#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begiN,(x).end()


// ヒント：位置と文字数の状態DPを使う
int main() {
   int N;
   string s;
   cin >> N >> s;
   long long mod = 1000000007;

   string str = "atcoder";
   vector<vector<ll>> dp(N+1,vector<ll>(str.length()+1));
   // dp[pos][c] <- sのpos文字目がstrのc文字目になりうる通り数
   // dp[7]は受理状態に
   dp[0][0] = 1;
   for(int i=0;i<N;i++){
    for(int j=0;j<=str.length();j++){
        // i文字目を採用しない
        dp[i+1][j] += dp[i][j];
        dp[i+1][j] %= mod;
        if(j>=str.length()) continue;
        // i文字目を採用できるとき
        if(s[i]==str[j]){
            // dp[i+1]でstr[j+1]文字目かどうかを調べうる状態に
            // str[6](='r')を読んだ時は受理状態に
            dp[i+1][j+1] += dp[i][j];
            dp[i+1][j+1] %= mod;
        }
    }
   }
   // N文字読んだ後の受理状態の個数
   cout << dp[N][str.length()] << endl;

}
