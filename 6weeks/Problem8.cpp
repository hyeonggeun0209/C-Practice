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
	cout << "������ ������ ������ �Է��Ͻÿ�>> ";
	cin >> size;
	IntStack mstack(size);
	cout << "���ÿ� ������ " << size << "���� ������ �Է��϶�>> ";
	for (int i = 0; i < size; i++) {
		cin >> n;
		mstack.push(n);
	}
	cout << "����� ������ ����>> " << mstack.size() << endl;
	cout << "��� ���Ҹ� ���Ͽ� ���>> ";
	while (mstack.size() != 0 ) {
		cout << mstack.pop(p) << ' ';
	}
	cout << endl << "������ ���� ũ��:" << mstack.size() << endl;
}