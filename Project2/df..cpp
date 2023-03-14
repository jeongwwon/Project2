#include<iostream>
#include<fstream>

int main() {
	char a;
	std::ifstream ifs("jeongwon");
	ifs >> a;
	ifs >> a;
	ifs >> a;
	ifs >> a;
	ifs >> a;
	std::cout << a;
	
}