#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()
#define lb_ind(a, key) lower_bound(all((a)), (key)) - (a).begin();
#define llvec(a,n) vector<ll> (a)((n));

ll a[11][11];
ll N;

ll calc_time(vector<ll> &arr){
    // 区画i -> arr[i]が走る
    // timeはa[arr[i]][i]
    ll time = 0;
    for(int i=0;i<N;i++){
        time += a[arr[i]][i];
    }
    return time;
}

int main() {
   // 制約が小さい(N<=10) => 全探索？
   // 10!なのでいけそう
   cin >> N;
   rep(i, N){
    rep(j,N){
        cin >> a[i][j];
    }
   }

   ll M;
   cin >> M;

   map<pair<ll, ll>, bool> funaka;
   ll X, Y;
   rep(i,M){
    cin >> X >> Y;
    if(X>Y) swap(X,Y); // 小->大に
    funaka[{X-1,Y-1}] = true;
   }

   ll ans = 15000;
   bool flg = false;
   vector<ll> arr(N);
   rep(i, N) arr[i]=i;
   do {
    // arrの時に,
    // 1. 走れるかどうか
    // 2. コストはいくつか
    // を計算する
    bool is_funaka = false;
    for(int i=0;i<N-1;i++){
        pair<ll,ll> p = {
            min(arr[i],arr[i+1]),max(arr[i],arr[i+1])};
        if(funaka[p]){
            is_funaka = true;
            break;
        }
    }
    if(!is_funaka){
        ll cal = calc_time(arr);
        ans = min(cal, ans);
        flg = true;
        }
    
   } while (next_permutation(all(arr)));
   if(flg) cout << ans << endl;
   else cout << -1 << endl;
}