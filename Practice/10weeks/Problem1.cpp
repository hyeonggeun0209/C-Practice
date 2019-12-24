#include <iostream>
using namespace std;

template <class T>
bool equalArrays(T a[], T b[], int size) {
	int i = 0;
	while (i != size) {
		if (a[i] == b[i])
			;
		else
			return false;
		i++;
	}
	return true;
}

int main() {
	double x[] = { 1,10,100,5,4 };
	double y[] = { 1,10,100,5,4.0 };


	if (equalArrays(x, y, 5)) cout << "같다";
	else cout << "다르다";
}