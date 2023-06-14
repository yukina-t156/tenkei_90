#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()
#define lb_ind(a, key) lower_bound(all((a)), (key)) - (a).begin();
#define llvec(a,n) vector<ll> (a)((n));

int main() {
   ll a, b, c;
   cin >> a >> b >> c;
   // a,b,c >= 1より、a<c^bかどうかを見れば良い
   // ※pow(c,b)は誤差でWAになる可能性がある
   ll pow_cb = 1;
   rep(i,b) pow_cb*=c;
   if(a<pow_cb) cout << "Yes" << endl;
   else cout << "No" << endl;
}