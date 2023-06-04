#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()

int N;
// 正しい括弧列の判定
bool is_correct(string s){
    stack<char> st;
    for(char c: s){
        if(c=='('){
            st.push(c);
        }else{
            if(st.empty()) return false;
            else st.pop();
        }
    }
    return st.empty(); // (が残っていたらfalseが返る
}

// 01文字列から()へ
string to_parenstring(int n){
    string ret = "";
    for(int i=N-1;i>=0;i--){
        if((1<<i)&n) ret.push_back(')');
        else ret.push_back('(');
    }
    return ret;
}

// ヒント：bit全探索
int main() {
   cin >> N;
   for(int flg=0;flg<(1<<N);flg++){
    // 0:( 1:)
    // 必ず生成される括弧列は辞書順
    string s = to_parenstring(flg);
    if(is_correct(s)) cout << s << endl;
   }
}
