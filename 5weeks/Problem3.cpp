#include <iostream>
#include <string>
using namespace std;

class Board {
public:
	static int size;
	static string str[];
	static void add(string s) {
		str[size] = s;
		size++;
	}

	static void printf() {
		cout << "************* �Խ����Դϴ�. *************" << endl;
		for (int i = 0; i < size; i++) {
			cout << i << ": " << str[i] << endl;
		}
		cout << endl;
	}

};

int Board::size = 0;
string Board::str[5] = { " " };

int main() {
	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿��� �ּ���.");
	Board::printf();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���");
	Board::printf();
} 