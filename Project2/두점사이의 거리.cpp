#include<iostream>
#include<vector>
#include<cmath>
void display(int n) {
	std::cout <<"�ִ� �Ÿ��� ��:" << n << std::endl;
}
int main() {
	int max;
	int n;
	static int max1=0;
	std::cin >> n;
	std::vector<double> x(n),y(n);
	for (int i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
	}
	std::cout << "���������� �Ÿ�" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j<n ; j++) {
			max = sqrt((x[j] - x[i])*(x[j] - x[i]) + (y[j] - y[i])* (y[j] - y[i]));
			std::cout <<i<<"��° ��ǥ��"<<j<<"��° ��ǥ�� �Ÿ�:" <<max<< std::endl;
			if (max1 <= max) {
				max1 = max;
			}
			std::cout << std::endl;
		}
	}
	display(max1);
}