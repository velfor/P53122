#include <iostream>
using namespace std;

class Cat {
	char sex;
	string name;
	double weight;
	int age;

public:
	Cat() {
		sex = ' ';
		name = "";
		weight = 0.0;
		age = 0;
	}
	Cat(char fsex, string fname, double fweight, int fage) {
		sex = fsex;
		name = fname;
		weight = fweight;
		age = fage;
	}
	char getSex() { return sex; }
	void setWeight(double fweight) { weight = fweight; }
	string getName() { return name; }
	double getWeight() { return weight; }
	double getAge() { return age; }
	void print() {
		cout << "Name:" << name << endl;
		cout<< "Sex: " << sex << endl;
		cout << "Age: " << age << endl;
		cout << "Weight: " << weight << endl;
	}
};

class Banan {

};
int main() {
	Cat barsik;
	Cat vaska('m', "Vaska", 5.3, 4);
	cout << vaska.getSex() << endl;
	vaska.setWeight(6.1);
	vaska.print();
	//������� ����� ������. 2 ���� - ���� � ���. 2 ������������, 2 ������ get 2 ������ set, ����� print.
	//������� 2 ������� ������ ������.
	//��������� ��� 2 �������.
	return 0;
}
