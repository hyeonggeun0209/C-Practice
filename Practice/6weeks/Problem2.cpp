#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() {
		return radius;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return 3.14*radius*radius;
	}
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle() : Circle() {

	}
	NamedCircle(int radius, string name) : Circle(radius) {
		this->name = name;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
};

int main() {
	cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���." << endl;
	NamedCircle pizza[5];
	string name;
	int radius;
	int max;
	int j = 0;

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ">> ";
		cin >> radius >> name;
		pizza[i].setRadius(radius);
		pizza[i].setName(name);
	}

	max = pizza[0].getArea();
	for (int i = 0; i < 5; i++) {
		if (max < pizza[i].getArea()) {
			max = pizza[i].getArea();
			j = i;
		}
	}
	cout << "���� ������ ū ���ڴ� " << pizza[j].getName() << "�Դϴ�.";
}