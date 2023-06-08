#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()


struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++)par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
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