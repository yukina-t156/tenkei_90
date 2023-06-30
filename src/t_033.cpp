#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()
#define lb_ind(a, key) lower_bound(all((a)), (key)) - (a).begin();
#define llvec(a,n) vector<ll> (a)((n));

int main() {
   ll H, W;
   cin >> H >> W;
   // 1列or1行の時->全てを点灯させてもOK
   if(H==1||W==1) cout << H*W << endl;
   else cout << ((H+1)/2) * ((W+1)/2) << endl;
}
