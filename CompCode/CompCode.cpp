#include <iostream>

class ABC {
private:
	int b{ 2 };
public:
	friend void abcs(int);
};

void abcs(int a)
{
	std::cout << "yae \n" << ABC().b;
}
int main()
{
	auto a{ ABC() };
	abcs(2);
	std::cout << "Hello World!\n";
}