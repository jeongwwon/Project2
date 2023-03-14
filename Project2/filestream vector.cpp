#include<iostream>
#include<fstream>
#include<vector>
void print_vector(const std::vector<int>& a) {
	std::cout << "{";
	int len = a.size();
	if (len > 0) {
		for (int i = 0; i < len; i++) {
			std::cout << a[i] << ',';
		}
		//std::cout << a[len - 1];
	}
	std::cout << "}\n";
}

void save_vector(const std::string& filename, const std::vector<int>& a) {
	std::ofstream out(filename);
	if (out.good()) {
		int n = a.size();
		for (int i = 0; i < n; i++) {
			out << a[i] << " ";
			out << '\n';
		}
	}
	else std::cout << "fail!" << std::endl;
}
void load_vector(const std::string& filename, std::vector<int>& a) {
	std::ifstream in(filename);
	if (in.good()) {
		a.clear();
		int value;
		while (in >> value) {
			a.push_back(value);
		}

	}
	else std::cout << "fail!" << std::endl;
}
int main() {
	std::vector<int> list;
	bool done = false;
	char command;
	while (!done) {
		std::cout << "i)nsert<item> p)rint  " << "s)ave <filename> " << "L)oad <filename>" << "E)rase Q)uit:";
		std::cin >> command;
		int value;
		std::string filename;
		switch (command) {
		case 'I':
		case 'i':
			std::cin >> value;
			list.push_back(value);
			break;
		case 'P':
		case 'p':
			print_vector(list);
			break;
		case 'S':
		case 's':
			std::cin >> filename;
			save_vector(filename, list);
			break;
		case 'L':
		case 'l':
			std::cin >> filename;
			load_vector(filename, list);
		case 'E':
		case 'e':
			list.clear(); 
			break;
		case 'Q':
		case 'q':
			done = true;
			break;
		}
	}
}