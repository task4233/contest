#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;

	int q;
	cin >> q;
	while (q--)
	{
		int num;
		cin >> num;
		switch (num)
		{
		case 0:
			cin >> num;
			v.push_back(num);
			break;
		case 1:
			cin >> num;
			cout << v.at(num) << endl;
			break;
		case 2:
			v.pop_back();
		}
	}
	return 0;
}
