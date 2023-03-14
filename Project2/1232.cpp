#include<iostream>
#include<fstream>


int main() {
	char a;
	char b[10];
	int count=0;
	std::ofstream ofs("jeongwon");
	ofs << "jeongwon";
	ofs.close();
	std::ifstream ifs("jeongwon");
	while (ifs.get(a)) {
		b[count] = a;
		count++;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << "현재 인덱스:" << i << "값:" << b[i] << std::endl;
		if (b[i] == NULL) {
			std::cout << "예스" << std::endl;
		}
	}
}
