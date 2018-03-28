#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    long long ans = 0;
    if(s.size() > 1){
        int cnt = 0;
        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] == s[s.size() - i - 1]){
                ans += 50;
                cnt++;
            }else{
                ans += 48;
            }
        }
        if(s.size() & 1){
            if(cnt == s.size() / 2);
            else ans += 25;
        }
    }
    cout << ans << endl;

    return 0;
}
