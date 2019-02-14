#include <bits/stdc++.h>
using namespace std;

int main() {
	string base = "WBWBWWBWBWBW";
	string ans[7] = {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
	string s; cin >> s;
	string ret;
	for(int bi=0; bi<base.size(); ++bi) {
		for(int si=0; si<s.size(); ++si) {
			cerr << si << endl;
			cerr << base[(bi+si)%base.size()] << s[si] << endl;
			if (base[(bi+si)%base.size()] != s[si]) break;
			if (si == s.size()-1) {
				switch(bi){
				case 0:ret = ans[0];break;
				case 2:ret = ans[1];break;
				case 4:ret = ans[2];break;
				case 5:ret = ans[3];break;
				case 7:ret = ans[4];break;
				case 9:ret = ans[5];break;
				case 11:ret = ans[6];break;
				}
				cout << ret << endl;
				return 0;
			}
		}
	}
	
	
  return 0;
}
