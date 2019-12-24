#include <iostream>
using namespace std;

class MyIntStack {
	int *p;
	int size;
	int tos;
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s);
	~MyIntStack();
	bool push(int n);
	bool pop(int &n);
};

MyIntStack::MyIntStack() { 
	tos = 0;
}

MyIntStack::MyIntStack(int size) {
	tos = 0;
	this->size = size;
	this->p = new int [this->size];
}

MyIntStack::MyIntStack(const MyIntStack& s) {
	this->size = s.size;
	this->tos = s.tos;
	this->p = new int[this->size];
	for (int i = 0; i < tos; i++) {
		p[i] = s.p[i];
	}
}

MyIntStack::~MyIntStack() {
	if (p)
		delete[] p;
}

bool MyIntStack::push(int n) {
	if (tos == size) {
		return false;
	}
	else {
		*(p + tos) = n;
		tos++;
		return true;
	}
}

bool MyIntStack::pop(int &n) {
	if (tos == 0) {
		return false;
	}
	else {
		--tos;
		n = *(p + tos);
		return true;
	}
}

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 pop한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 pop한 값 " << n << endl;
}
