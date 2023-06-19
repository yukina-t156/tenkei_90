#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()
#define lb_ind(a, key) lower_bound(all((a)), (key)) - (a).begin();
#define llvec(a,n) vector<ll> (a)((n));

int main() {
    bool ans = false;
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> B(N);
    ll dif = 0;
    rep(i,N) cin >> A[i];
    rep(i,N){
        cin >> B[i];
        dif += abs(A[i]-B[i]);
    }
    // 回数が足りない時
    if(dif>K) ans = false;
    else{
    // 回数が余る時
        K -= dif; // 余剰分
        ans = (K%2==0); // +1して-1する=>元に戻せる
    }
    
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

}