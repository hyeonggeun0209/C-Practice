#include <iostream>
using namespace std;

template <class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	int *state = new int[sizeSrc]; retSize = sizeSrc;
	for (int i = 0; i < sizeSrc; i++) {
		state[i] = 1;
	}
	for (int i = 0; i < sizeSrc; i++) {
		for (int j = 0; j < sizeMinus; j++) {
			if (src[i] == minus[j]) {
				state[i] = 0;
				retSize--;
			}
		}
	}
	T *ptr = new T[retSize];
	int s = 0;
	for (int i = 0; i < sizeSrc; i++) {
		if (state[i] == 1) {
			ptr[s] = src[i];
			s++;
		}
	}
	return ptr;
}

int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[] = { 2,4,6,8,10 };
	int size;
	int *p = remove(a, 10, b, 5, size);
	for (int i = 0; i < size; i++) {
		cout << p[i] << ' ';
	}
}