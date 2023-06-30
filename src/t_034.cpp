#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()
#define lb_ind(a, key) lower_bound(all((a)), (key)) - (a).begin();
#define llvec(a,n) vector<ll> (a)((n));

int main() {
   ll N, K;
   cin >> N >> K;
   vector<ll> a(N);
   rep(i,N) cin >> a[i];

   /*
   尺取法を使用
   
   iの位置からK種類の限界の右端である位置のカーソルcrまでを計算
        i        cr
        ↓        ↓
   |----[--------)----|
            ||
            \/
    iを進め、含まれる文字数を更新。crを再び更新
         i(+1)     cr
         ↓         ↓
   |-----[---------)--|
   */

  int cr = 0, cnt = 0, answer = 0;
  map<int, int> nums;

  rep(i,N){
    // crを進められるだけ進める -> 見ている範囲は[i,cr)になる(含められないcrでbreakする)
    while(cr<N) {
        // a[cr]の文字がまだ含まれていない時
        if(nums[a[cr]]==0){
            if(cnt==K) break; // すでにK種類ある->a[cr]を含められない時
            cnt ++; // a[cr]を含める時->種類数を増やす
        }
        nums[a[cr]]++; // a[cr]の数を増やす
        cr++; // カーソルを一つ進める
    }
    answer = max(answer, cr-i); // 現在見ている範囲は[i,cr),長さはcr-i
    // i文字目を範囲から取り除く
    if(nums[a[i]]==1) cnt--; // a[i]の文字が一つだけの時->含まれている種類数を減らす
    nums[a[i]]--; // a[i]の数を減らす
  }
  cout << answer << endl;
}
