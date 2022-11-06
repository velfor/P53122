#include <iostream>
#include <ctime>
using namespace std;
int main() {
	//Заполнить массив случайными числами от -10 до 10. Подсчиать кол-во положительных 
	const int n = 10;
	int mas[n];
	//заполнение случайными числами
	srand(time(nullptr));
	for (int i = 0; i < n; i++) {
		mas[i] = rand() % 51 - 25; // % 51 дает диапазон от 0 до 50
		cout << mas[i] << ' ';
	}
	cout << endl;
	//считаем положительные
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] > 0) k++;
	}
	cout << k << endl;
}