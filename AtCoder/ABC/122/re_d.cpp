#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;

int dp[575][7][7][7];

int main() {
	int n;cin>>n;

	dp[3][0][2][1] = -1;
	dp[3][0][1][2] = -1;
	dp[3][2][0][1] = -1;
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			for(int k=0;k<4;++k){
				++dp[3][i][j][k];
			}
		}
	} 

	auto check = [&](int j,int k,int l, int m){
								 if(j==0 && k==2 && l==1) return false;
								 if(j==0 && k==1 && l==2) return false;
								 if(j==2 && k==0 && l==1) return false;
								 if(j==0 && l==2 && m==1) return false;
								 if(k==0 && l==2 && m==1) return false;
								 if(k==0 && l==1 && m==2) return false;
								 if(k==2 && l==0 && m==1) return false;
								 if(j==0 && k==2 && m==1) return false;
								 return true;
							 };
	
	for(int i=0;i<n;++i){
		for(int j=0;j<4;++j){
			for(int k=0;k<4;++k){
				for(int l=0;l<4;++l){
					for(int m=0;m<4;++m){
						if(check(j,k,l,m)) (dp[i+1][k][l][m] += dp[i][j][k][l]) %= MOD;
					}
				}
			}
		}
	}

	int ans=0;
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			for(int k=0;k<4;++k){
				(ans += dp[n][i][j][k]) %= MOD;
			}
		}
	}
	cout << ans << endl;
 
  return 0;
}
