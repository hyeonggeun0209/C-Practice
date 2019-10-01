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
		cout << "************* 게시판입니다. *************" << endl;
		for (int i = 0; i < size; i++) {
			cout << i << ": " << str[i] << endl;
		}
		cout << endl;
	}

};

int Board::size = 0;
string Board::str[5] = { " " };

int main() {
	Board::add("중간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요.");
	Board::printf();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요");
	Board::printf();
} 