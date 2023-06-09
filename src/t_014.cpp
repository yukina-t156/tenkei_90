#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()

int main() {
   ll N; cin >> N;
   vector<ll> A(N);
   vector<ll> B(N);
   rep(i,N) cin >> A[i];
   rep(i,N) cin >> B[i];
   // ソートする
   sort(all(A));
   sort(all(B));
   ll s = 0;
   rep(i,N){
      // A,Bで結んでクロスするところがある->短縮できる
      // 結んだ時に交点ができないように
      // ソート順にマッチングすれば良い
      s += abs(B[i]-A[i]);
   }
   cout << s << endl;
}