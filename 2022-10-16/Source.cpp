#include <iostream>
using namespace std;
int main() {
	int sum = 0;
	int a;
	cin >> a;
	for (int i = 1; i <= a; i = i + 1) {
		sum = sum + i;
	}
	cout << sum << endl;
}