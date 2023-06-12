#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()

int main() {
   int N; cin >> N;
   vector<int> coins(3);
   rep(i,3){
    cin >> coins[i];
   }
   sort(coins.rbegin(),coins.rend()); // 降順ソート
   int ans = 10000;
   // 大きい順に調べる
   for(int i=N/coins[0];i>=0;i--){
      for(int j=(N-(coins[0]*i))/coins[1];j>=0;j--){
         // coins[2]を使って残りの額がちょうど払える場合
         if((N-(coins[0]*i)-(coins[1]*j))%coins[2]==0){
            // 最小値を更新
            ans = min(ans, (i+j+(N-(coins[0]*i)-(coins[1]*j))/coins[2]));
         }
      }
   }
   cout << ans << endl;
}