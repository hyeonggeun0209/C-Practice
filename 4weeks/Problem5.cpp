#include <iostream>
#include <string>
using namespace std;

class Buffer {
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { text += next; }
	void printf() { cout << this->text << endl; }
};

Buffer& append(Buffer& c, string s) {
	c.add(s);
	return c;
}

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys");
	temp.printf();
	buf.printf();
}
