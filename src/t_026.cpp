#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()
#define lb_ind(a, key) lower_bound(all((a)), (key)) - (a).begin();
#define llvec(a,n) vector<ll> (a)((n));



int col[100001]; // 色分け
vector<vector<int>> v(100001, vector<int>(0));
// 深さ優先探索(解答スライド参照)
void dfs(int pos, int cur){
    col[pos] = cur;         // posの位置のcolをcur(0 or 1)に色分け
    for(int next: v[pos]){
        if(col[next]==-1){ // まだ塗られていない場合
            dfs(next, (cur+1)%2);
        }
    }
}

int main() {
   ll N;
   cin >> N;
   vector<ll> ans(N+1);

   for(int i=1;i<=N;i++){
    col[i]=-1;
   }

   rep(i,N-1){
    ll A, B;
    cin >> A >> B;
    v[A].push_back(B);
    v[B].push_back(A);
   }

   // 深さ優先探索で色分け
   dfs(1, 0);

   // 0がN/2以上あるかどうか
   int cnt_0 = 0;
   for(int i=1;i<=N;i++){
    if(col[i]==0)cnt_0++;
   }

   int cnt = 0;
   int color= 1; // どの色のノードを出力するか
   bool flg;     // 出力のスペース用

   if(cnt_0>=N/2) color=0; // colorが0のノードがN/2個以上ある時
   
   for(int i=1;i<=N;i++){
    // colorが一致するノードのみ出力
    if(col[i]==color){
        if(flg) cout << " ";
        cout << i;
        flg = true;
        cnt ++;
    }
    if(cnt>=N/2) break; // N/2個でいい
   }
   cout << endl;

}