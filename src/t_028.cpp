#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()
#define lb_ind(a, key) lower_bound(all((a)), (key)) - (a).begin();

int main() {
   // 左下から累積和 -> 2方向目の計算の際に答えを集計できる
   /*
                        横に和をとる  縦に和をとる
    ......     00-010     00--00     000000
    ..##..     000000     000000     001100
    ..##.. =>  0010-0  => 001100  => 001100
    ......     000000     000000     000000
   */
  /*
  入力例1~3は通っており解答ソースコードともほとんど一緒なのに何故かWRが取れない
  -> 集計時の範囲落ち？(i=1, j=1にしていたが入力は0も含まれる)
  */
  ll N; cin >> N;
  vector<vector<ll>> z(1001,vector<ll>(1001));
  vector<ll> ans(N+1);
  ll lx, ly, rx, ry;
  rep(i,N){
    cin >> lx >> ly >> rx >> ry;
    z[ly][lx]++;
    z[ry][rx]++;
    z[ly][rx]--;
    z[ry][lx]--;
  }

  // 横の和
  for(int i=0;i<1001;i++){
    for(int j=1;j<1001;j++){
        z[i][j] += z[i][j-1];
    }
  }
  
  // 縦の和
  for(int i=1;i<1001;i++){
    for(int j=0;j<1001;j++){
        z[i][j] += z[i-1][j];
    }
  }
  
  // 枚数が決定したらansに保存
  // 初期値をi=1, j=1にしてた(ここで落ちてた？)
  for(int i=0;i<=1000;i++){
    for(int j=0;j<=1000;j++){
        if(z[i][j]>0) ans[z[i][j]]++;
    }
  }

  for(int i=1;i<=N;i++){
    cout << ans[i] << endl;
  }
}
