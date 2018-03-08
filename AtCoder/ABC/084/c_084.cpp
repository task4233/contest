#include <iostream>
using namespace std;
int N;
int main()
{
    cin >> N;
    int C[N-1], S[N-1], F[N-1];
    for (int i = 0; i < N-1; ++i) cin >> C[i] >> S[i] >> F[i];
    for (int i = 0; i < N-1; ++i) {
        int s;
        s = 0;
        for (int j = i; j < N-1; ++j) s = (s<S[j]?S[j]:s%F[j]!=0?s = s+F[j]-s%F[j]:s) + C[j];
        cout << s << endl;
    }
    cout << 0 << endl;
    return 0;
}
