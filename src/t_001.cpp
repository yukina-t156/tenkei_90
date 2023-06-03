#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()


int a[100001];
int N, L, K;
// hint: 答えで二分探索

bool can_separate(int ans){
    // K回分割し、全てのピースがans(cm)より大きくなるように分けられるかどうか
    int i=1, cnt=0;
    int piece_len = 0;
    while(i<=N && cnt<K){
        // 前の切れ目から次の切れ目までの長さを足す
        piece_len += (a[i]-a[i-1]);
        // ans(cm)以上になる時
        if(piece_len>=ans){
            cnt ++; // その切れ目を選ぶ
            // ピースの長さをリセット
            piece_len = 0;
        }
        i++;
    }
    if(L-a[i-1]<ans) return false; // while内で最後に切った切れ目~末尾がans以上か
    return (cnt>=K); // 切れ目がK個(今回は無いが以上)の時：true;
}
int main() {
    cin >> N >> L >> K;
    a[0]=0;
    rep(i, N) cin >> a[i+1];
    // 二分探索
    int left = 0, right = L; // [left, right)
    // 探索範囲が1になるまで
    while(right-left>1){
        int middle = (left+right)/2;
        if(can_separate(middle)) {
            // 答えはmiddle以上
            left = middle;
        }else{
            // middleは答えに含まれない
            right = middle;
        }
    }
    cout << left << endl;
}