#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> v;
	while (1) {
		int all = 0;
		cout << "정수를 입력하세요(0을 입력하면 종료)>>";
		cin >> n;
		if (n == 0) return 0;
		v.push_back(n);
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
			all += v[i];
		}
		cout << endl << "평균 = " << (double)all / v.size() << endl;
	}
}