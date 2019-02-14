#include <bits/stdc++.h>
using namespace std;
using int64 = int64_t;
#define int int64

// dp[i][j] := ibit目まで見てそこまでの値がk未満で(0:ない, 1:ある)時の最大値
int dp[60][2];

signed main(){
	int n,k;
	cin >> n >> k;
	vector< int > a(n);
	for(int i=0; i<n; ++i) cin >> a[i];
	memset(dp, -1, sizeof(dp));

	dp[45][0] = 0;
	for(int bi=44; bi>=0; --bi){
		int on_bit_num = 0;
		for(int ai=0; ai<n; ++ai) {
			if ((a[ai] >> bi) & 1) ++on_bit_num;
		}
 
		int digit = (1LL << bi);
 	  if (dp[bi+1][1] >= 0) {
			dp[bi][1] = max(dp[bi][1], dp[bi+1][1] + digit*max(on_bit_num, n - on_bit_num));
		}
		if (dp[bi+1][0] >= 0) {   
			if ((k >> bi) & 1){
				dp[bi][1] = max(dp[bi][1], dp[bi+1][0] + digit*on_bit_num);
				dp[bi][0] = max(dp[bi][0], dp[bi+1][0] + digit*(n - on_bit_num));
				//cerr << "digit1" << digit << endl;
			} else {
				dp[bi][0] = max(dp[bi][0], dp[bi+1][0] + digit*on_bit_num);
				//cerr << "digit2" << digit << endl;
			}
		}
		/*
		cerr << "bi+1:" <<  dp[bi+1][0] << endl;
		cerr << "bi  :" << bi << endl;
		cerr << "on  :" << on_bit_num << endl;
		cerr << "dp-0:" << dp[bi][0] << endl;
		cerr << "dp-1:" << dp[bi][1] << endl << endl;
		*/
	}   

	int ans = max(dp[0][0], dp[0][1]);
	cout << ans << endl;
	/*
	for(int bi=41;bi>=0;--bi){
		cerr<< dp[bi][0] << " " << dp[bi][1] << endl;
	} 
	*/  
	
  return 0;
}
