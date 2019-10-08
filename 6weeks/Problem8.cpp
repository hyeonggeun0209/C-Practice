#include <iostream>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;
	virtual int size() = 0;
};

class IntStack : public AbstractStack {
	int len, capacity, i;
	int *mem;
public:
	IntStack(int capacity = 5) {
		this->capacity = capacity;
		mem = new int[capacity];
		len = 0; i = 0;
	}
	~IntStack() { delete[]mem; }
	virtual bool push(int n) {
		if (len == capacity)
			return false;
		else
			mem[i++] = n; len++;
	}
	virtual bool pop(int& n) {
		if (len == 0) {
			return false;

		}
		else {
			n = mem[--i];
			len--;
		}
	}
	virtual int size() {
		return len;
	}
};

int main() {
	int size, n, p;
	cout << "삽입할 정수의 개수를 입력하시오>> ";
	cin >> size;
	IntStack mstack(size);
	cout << "스택에 삽입할 " << size << "개의 정수를 입력하라>> ";
	for (int i = 0; i < size; i++) {
		cin >> n;
		mstack.push(n);
	}
	cout << "저장된 정수의 개수>> " << mstack.size() << endl;
	cout << "모든 원소를 팝하여 출력>> ";
	while (mstack.size() != 0 ) {
		mstack.pop(p);
		cout << p << ' ';
	}
	cout << endl << "스택의 현재 크기:" << mstack.size() << endl;
}
