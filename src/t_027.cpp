#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()
#define lb_ind(a, key) lower_bound(all((a)), (key)) - (a).begin();
#define llvec(a,n) vector<ll> (a)((n));

int main() {
    ll N;
    cin >> N;
   map<string, bool> list;
   rep(i,N){
    string S;
    cin >> S;
    if(!list[S]){
        list[S]=true;
        cout << i+1 << endl;
    }
   }
}