#include <iostream>
#include <ctime>
using namespace std;
int main() {
	//��������� ������ ���������� ������� �� -10 �� 10. ��������� ���-�� ������������� 
	const int n = 10;
	int mas[n];
	//���������� ���������� �������
	srand(time(nullptr));
	for (int i = 0; i < n; i++) {
		mas[i] = rand() % 51 - 25; // % 51 ���� �������� �� 0 �� 50
		cout << mas[i] << ' ';
	}
	cout << endl;
	//������� �������������
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] > 0) k++;
	}
	cout << k << endl;
}