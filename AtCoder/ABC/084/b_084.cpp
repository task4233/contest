#include <iostream>
#include <string>
using namespace std;
int A;
int B;
string s;
string output = "Yes";
int main()
{
    cin >> A >> B >> s;
    for (int i = 0; i < A; ++i) if (!('0' <= s[i] && s[i] <= '9'))output = "No";
    if (s[A]!='-')output = "No";
    for (int i = A+1; i <= A+B; ++i) if (!('0' <= s[i] && s[i] <= '9'))output = "No";
    cout << output << endl;
    
    return 0;
}
