#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> v;
	while (1) {
		int all = 0;
		cout << "������ �Է��ϼ���(0�� �Է��ϸ� ����)>>";
		cin >> n;
		if (n == 0) return 0;
		v.push_back(n);
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
			all += v[i];
		}
		cout << endl << "��� = " << (double)all / v.size() << endl;
	}
}