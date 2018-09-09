#include <bits/stdc++.h>                                               
using namespace std;

int main() {                                                           
	string x;                                                            
	int ans;
	while (true) {                                                       
		cin >> x;
		std::stringstream ss{x};
		std::string buf;
		while (std::getline(ss, buf, '')) {
			sp.push_back(buf);
		}
		for (auto &a : sp) {
			cout << a << endl;
		}
		int sm = 0, tmp;                                                   
		for (int i = 0; i < sp.size(); ++i) {                              
			if (i % 2 == 0) {                                                
				tmp = stoi(sp[i]);                                     
			} else {                                                         
				switch(atoi(sp[i].c_str())) {                                  
				case '+':                                                      
					ans += tmp;                                                  
					break;                                                       
				case '-':                                                      
					ans -= tmp;                                                  
					break;                                                       
				case '*':                                                      
					ans *= tmp;                                                  
					break;                                                       
				case '/':                                                      
					ans /= tmp;                                                  
					break;                                                       
				}                                                              
			}                                                                
		}                                                                  
		cout << ans << endl;                                               
	}                                                                    
}

