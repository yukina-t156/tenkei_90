#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()
#define lb_ind(a, key) lower_bound(all((a)), (key)) - (a).begin();
#define llvec(a,n) vector<ll> (a)((n));

int main() {
   ll A, B, C;
   cin >> A >> B >> C;

   // A, B, Cの最大公約数を求める。
   // このgが立方体の一辺になる。
   ll g = gcd(A, gcd(B, C));
   
   // 答えを計算する
   ll ans = 0;
   // 各辺で幾つできるか -> できる数の-1回分切る必要がある
   // ※最大公約数より、A,B,Cは必ずgで割り切れる
   ans += A/g-1;
   ans += B/g-1;
   ans += C/g-1;
   cout << ans << endl;
   return 0;
}
