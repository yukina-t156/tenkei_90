#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()

int main() {
   // 一番長い距離を求め、その両端を繋げばよさそう
   // 一番長い距離をどうやって求める？ -> DFS or BFS
   // 1から一番遠いところを起点にしてみる？
   ll N;
   cin >> N;
   vector<vector<ll>> road(N+1);
   ll A, B;
   rep(i,N){
    cin >> A >> B;
    road[A].push_back(B);
    road[B].push_back(A);
   }
   // 1から一番遠い場所を求める
   stack<pair<ll,ll>> st; // {index, distance}
   map<ll, bool> done;
   st.push({1,0});
   pair<ll,ll> far_from_1 = {1, 0};
   while(!st.empty()){
    pair<ll,ll> t = st.top();
    st.pop();
    if(t.second>far_from_1.second) far_from_1 = t;
    if(!done[t.first]){
        for(ll n:road[t.first])st.push({n, (t.second+1)});
    }
    done[t.first] = true;
   }
//   cout << "far from 1:" << far_from_1.first << "(dist:" << far_from_1.second << ")" << endl;

   // far_from_1から一番遠い点を求める
   map<ll, bool> done2;
   st.push({far_from_1.first,0});
   pair<ll,ll> far = {far_from_1.first, 0};
   while(!st.empty()){
    pair<ll,ll> t = st.top();
    st.pop();
    if(t.second>far.second) far = t;
    if(!done2[t.first]){
        for(ll n:road[t.first])st.push({n, (t.second+1)});
    }
    done2[t.first] = true;
   }
//   cout << "far from x:" << far.first << "(dist:" << far.second << ")" << endl;
   cout << far.second+1 << endl;
}