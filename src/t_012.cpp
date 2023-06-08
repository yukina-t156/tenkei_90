#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()

// ref: https://qiita.com/ofutonton/items/c17dfd33fc542c222396
struct UnionFind {
   vector<int> par;
   UnionFind(int N) : par(N) {
   for(int i = 0; i < N; i++) par[i] = i;
   }

   int root(int x) {
       if (par[x] == x) return x;
       return par[x] = root(par[x]);
   }
   void unite(int x, int y) {
   int rx = root(x);
   int ry = root(y);
   if (rx == ry) return;
   par[rx] = ry;
   }

   bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
   }
};

ll H, W;

// Union-Findで使用しているindexに変換する
ll to_index(ll y, ll x){
    return (y)*W+(x);
}

int main() {
   // UnionFindで赤マスで繋がっているところをグループ化
   // 同じ木ならクエリ2はYes
   cin >> H >> W;

   UnionFind uf (H*W);
   vector<vector<bool>> field(H,vector<bool>(W)); // マス目が塗られているか

   ll Q;
   cin >> Q;
   rep(i,Q){
    int t;
    cin >> t;
    // クエリ1
    if(t==1){
        //
        ll r, c;
        cin >> r >> c;
        r--; c--;
        field[r][c] = true;
        // 隣接しているマス目で赤く塗られているものがあれば連結
        if(r>0){ // ↑
            if(field[r-1][c]) uf.unite(to_index(r,c),to_index(r-1,c));
        }
        if(r<H-1){ // ↓
            if(field[r+1][c]) uf.unite(to_index(r,c),to_index(r+1,c));
        }
        if(c>0){ // ←
            if(field[r][c-1]) uf.unite(to_index(r,c),to_index(r,c-1));
        }
        if(c<W-1){ // →
            if(field[r][c+1]) uf.unite(to_index(r,c),to_index(r,c+1));
        }
    }else{ // クエリ2
        ll ra, ca, rb, cb;
        cin >> ra >> ca >> rb >> cb;
        ra--;ca--;rb--;cb--;
        // 開始と終了が塗られている、かつ同じ根に属している
        if(field[ra][ca]&&field[rb][cb]&&
        uf.same(to_index(ra,ca), to_index(rb,cb))){
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
        
    }
   }
}