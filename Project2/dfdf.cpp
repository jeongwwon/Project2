#include<iostream>
#include<fstream>
int main() {
	char a;
	std::ifstream ifs("jeongwon");
	while (ifs.get(a)) {
		std::cout << a;
	}
	
}