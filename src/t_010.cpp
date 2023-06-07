#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()

int main() {
   ll N;cin >> N;
   vector<ll> first_sum(N+1);
   vector<ll> second_sum(N+1);
   rep(i,N){
    int C; cin >> C;
    if(C==1) cin >> first_sum[i+1];
    else cin >> second_sum[i+1];
   }
   // 累積和を取る
   rep(i,N){
    first_sum[i+1]+=first_sum[i];
    second_sum[i+1]+=second_sum[i];
   }
   // クエリの処理
   ll Q;
   cin >> Q;
   rep(i,Q){
    ll L, R;
    cin >> L >> R;
    // Rまでの和(R含む)-Lまでの和(L含まない)=LからRまでの和
    cout << first_sum[R]-first_sum[L-1] << " " << second_sum[R]-second_sum[L-1] << endl;
   }
}