#include<iostream>
#include<ctime>
void n(int n) {
	static int count = 0;
	for (int i = 0; i < n; i++) {
		count++;
	}
}
int main() {
	time_t start, finish;
	double duration;
	start = time(NULL);
	n(1000000000);
	finish = time(NULL);
	duration = (double)(finish - start);
	std::cout << duration << "ÃÊ" << std::endl;
}