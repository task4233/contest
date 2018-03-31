#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
#define debug(x) cerr << #x << ":" << x << endl;

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    int ans = -1e9;
    /*
    ここに15行目の内容を書いてはいけない
    もし序盤にaokiのmaxが出たとき、それ以降のtakahashiのmaxは更新されない
    →「最も左側にある要素に丸をつける」の指示がない場合ここに15行目の内容を書いても良い（気がする）
    iが更新される毎にaokiのmaxとtakahashiのmaxを最低に初期化しておく
    要するに区間ごとの左端詰めのaoki点取り合戦
    */
    int a = -1e9, t = -1e9;   //なんでここで初期化するんだ？
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j);
            else{
                int tmp_a = 0, tmp_t = 0;
                for(int k = min(i, j); k <= max(i, j); k++){
                    if((k - min(i, j)) % 2) tmp_a += A[k];
                    else tmp_t += A[k];
                }
                if(a < tmp_a){   //"<="はダメ ← 「そのような要素が複数あるならばそれらのうち最も左側にある要素に丸を付ける。」　
                    a = tmp_a;
                    t = tmp_t;
                }
		debug(i);
		debug(j);
		debug(a);
		debug(t);
		debug(tmp_a);
		debug(tmp_t);
            }
        }
        ans = max(ans, t);
	debug(ans);
    }

    cout << ans << endl;

    return 0;
}
