#include <iostream>
using namespace std;
int main() {
	//правила записи имен переменных (идентификаторов)
	//содержит только латинские буквы, цифры и знак подчеркивания
	//начинается с буквы
	//heroHP
	//monster_attack
	//a1
	//Begin8. Даны два числа a и b.Найти их среднее арифметическое :
	//(a + b) / 2.
	/*int a, b;
	cin >> a >> b;
	double average = (a + b) / 2.0;// int делить int - результат int
	cout << average << endl;*/
	//Begin9.Даны два неотрицательных числа a и b.
	//Найти их среднее геометрическое, то есть квадратный корень 
	//из их произведения : √a·b.
	/*int a, b;
	cin >> a >> b;
	double gAvg = sqrt(a*b);
	cout << gAvg << endl;*/
	//Begin10.Даны два ненулевых числа. Найти сумму, разность, 
	//произведение и частное их квадратов.
	int a, b;
	cin >> a >> b;
	int res = a * a + b * b;
	cout << res << endl;
	res = a * a - b * b;
	cout << res << endl;
	res = a * a * b * b;
	cout << res << endl;
	double res1 = (double)(a*a) / (b*b);
	cout << res1 << endl;
	//abs(a) - модуль а
	cout << res << " " << res1 << endl;
	// p = a;
	// a = b;
	// b = p;
}