#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()

int main() {
   ll H, W;
   cin >> H >> W;
   vector<ll> col(H);
   vector<ll> row(W);
   vector<vector<ll>> field(H, vector<ll>(W));
   rep(i,H){
    rep(j,W){
        cin >> field[i][j];
        col[i] += field[i][j];
        row[j] += field[i][j];
    }
   }

    rep(i,H){
        rep(j,W){
            cout << col[i]+row[j]-field[i][j];
            if(j!=W-1) cout << " ";
        }
        cout << endl;
   }

}