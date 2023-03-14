#include<iostream>
#include<fstream>

int main() {
	char a;
	std::ifstream ifs("jeongwon.txt");
	//std::ifstream ifs("jeongwon");
	ifs.open("jeongwon");
	while (ifs) {
		ifs >> a;
		std::cout << a;
	}
}