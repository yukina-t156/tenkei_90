#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()

int main() {
   ll N;
   cin >> N;
   vector<ll> A(N);
   rep(i,N) cin >> A[i];
   sort(all(A));
   ll Q;
   cin >> Q;
   ll b;
   rep(i,Q){
    cin >> b;
    // にぶたんしてb以上になるAの最小indexを返す
    auto ind = lower_bound(all(A),b) - A.begin();
    ll m;
    // 最低値より低い時
    if(ind==0){
        m = A[0]-b;
    }else if(ind==N){ // 最高値より高い時
        m = b-A[N-1];
    }else{
        // bより小さいところと大きいところのどちらが不満値が小さいか
        m = min(A[ind]-b, b-A[ind-1]);
    }
    cout << m << endl;
   }
}