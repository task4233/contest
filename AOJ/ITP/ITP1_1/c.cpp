#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int area = a * b;
    int perimeter = 2 * (a + b);
    cout << area << " " << perimeter << endl;
    return 0;
}