#include <iostream>
using namespace std;

template <class T>
bool search(T val, T a[], int size) {
	int i = 0;
	while (i != size) {
		if (val == a[i])
			return true;
		else
			;
		i++;
	}
	return false;
}

int main() {
	int x[] = { 1, 10, 1000, 5, 4 };

	if (search(100, x, 5)) cout << "100�� �迭 x�� ���ԵǾ� �ִ�";
	else cout << "100�� �迭 x�� ���ԵǾ� ���� �ʴ�";
}