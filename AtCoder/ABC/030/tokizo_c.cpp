#define debug(x) cerr << #x << ":" << x << endl;

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, x, y;
    cin >> n >> m;
    cin >> x >> y;
    vector< int > A(n);
    vector< int > B(m);
    bool Bf[m];
    for(int i = 0; i < n; i++){
      cin >> A[i];
    }
    for(int i = 0; i < m; i++){
      //b[f]は使ったかどうか
      cin >> B[i]; Bf[i] = true;
    }

    // pos: Aにいるときは0, Bにいるときは1
    int pos = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
 
    // t: 今の時間 / j_s: 今の時間から乗ることができそうなB空港からの便の番号(?) / cnt:往復回数
    long long t = 0ll, j_s = 0ll, cnt = 0ll;
    for(int i = 0; i < n; i++) {

      /*
      debug(A[i]);
      debug(t);
      debug(cnt);
      */
      
      if(i > 0) {
	//1回目以降


	/*
	cout << "check" << endl;
	debug(t);
	debug(y);
	debug(A[i]);
	*/
	
	if(t + y <= A[i] && pos == 1) {
	  // (今の時間 + B->Aの時間) が (A空港から出る便の時間) 以下のとき
	  // (今の時間) を (A空港から出る便の時間) にする
	  t = A[i];
	  pos = 0;
	  // 往復回数++

	  /*
	  cout << "t" << endl; 
	  debug(t);
	  debug(cnt);
	  debug(pos);
	  */
	  
	  cnt++;
	  // 次の便を見る
	  // i++;
	  for(int j = j_s; j < m; j++){
	    if(t + x <= B[j] && pos == 0){
	      pos = 1;
	      /*
	      debug(B[j]);
	      debug(t);
	      debug(pos);
	      */
	      // (今の時間 + A->Bの時間) が (B空港から出る便の時間) 以下のとき
	      //cout << t << " " << B[j] << endl;
	      /*if(i == n - 1){
		// 最終便の時
		cnt++;
		// break;
		}else*/
	      {
		// (今の時間) を (B空港から出る便の時間にする)
		t = B[j];
		j_s = j;
	      }
	      break;
	    }
	  }
	}
      }else{
	// 1回目の便
	for(int j = j_s; j < m; j++){
	  if(A[0] + x <= B[j] && pos == 0){
	    // (A空港の1回目の便 + A->Bまでの時間) が (B空港から出る便の時間) 以下のとき
	    //cout << A[i] << " " << B[j] << endl;
	    // (今の時間) を (B空港から出る便の時間) にする
	    t = B[j];
	    // j_s++;
	    j_s = j;
	    pos = 1;
	    break;
	  }
	}
      }
    }

    if (pos == 1 && t <= B[m - 1]) {
      // 現在空港Bにいて、戻ってこられるとき
      cnt++;
    }
    
    cout << cnt << endl;
    



    return 0;
}
