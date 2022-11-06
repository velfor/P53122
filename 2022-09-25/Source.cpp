#include <iostream>
using namespace std;
int main() {
	//Boolean2. Дано целое число A. Проверить истинность 
	//высказывания : «Число A является нечетным».
	/*int a;
	bool r;
	cin >> a;
	r = a % 2 != 0;
	cout << boolalpha << r << endl;*/
	//Boolean3. Дано целое число A. Проверить истинность 
	//высказывания : «Число A является четным».
	/*int a;
	bool r;
	cin >> a;
	r = a % 2 == 0;
	cout << boolalpha << r << endl;*/
	//Boolean4. Даны два целых числа : A, B. Проверить истинность 
	//высказывания : «Справедливы неравенства A > 2 и B ≤ 3».
	/*int a, b;
	bool r;
	cin >> a >> b;
	r = a > 2 && b <= 3;
	cout << boolalpha << r;*/
	//Boolean5. Даны два целых числа : A, B. Проверить истинность 
	//высказывания : «Справедливы неравенства A ≥ 0 или B < −2».
	/*int a, b;
	bool r;
	cin >> a >> b;
	r = a >= 0 || b < -2;
	cout << boolalpha << r;*/
	//Boolean6. Даны три целых числа : A, B, C. Проверить истинность
	//высказывания : «Справедливо двойное неравенство A < B < C».

	int a, b, c;
	cin >> a >> b >> c;
	bool r = a < b && b < c;
	cout << boolalpha << r << endl;
	//A < B < C или С < B < А
	
	// a % 2 != 0
}