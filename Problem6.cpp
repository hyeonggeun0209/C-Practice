#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
public:
	Book(string title, int price);
	~Book();
	Book(const Book& book);
	void set(string title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(string title, int price) {
	this->price = price;
	this->title = title;
}

Book::~Book() {

}

Book::Book(const Book& book) {
	this->price = book.price;
	this->title = title;
}

void Book::set(string title, int price) {
	this->price = price;
	this->title = title;
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}