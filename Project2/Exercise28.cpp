#include<iostream>
#define MAX_ROWS 50
#define MAX_COLS 50
class SquareMatrix {
private:
	int matrix[MAX_ROWS][MAX_COLS];
	int size;
public:
	SquareMatrix():size(MAX_ROWS){};
	void MakeEmpty(int n);
	void StoreValue(int i, int j, int value);
	void Add(SquareMatrix* b);
	void Subtract(SquareMatrix* b);
	void Copy(SquareMatrix* b);
	void display();
};

void SquareMatrix::MakeEmpty(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
		}
	}
}
void SquareMatrix::StoreValue(int i, int j, int value) {
	matrix[i][j] = value;
}
void SquareMatrix::Add(SquareMatrix* b) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = matrix[i][j] + b->matrix[i][j];
			b->matrix[i][j] = matrix[i][j];
		}
	}
}
void SquareMatrix::Subtract(SquareMatrix* b) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = matrix[i][j] - b->matrix[i][j];
		}
	}
}
void SquareMatrix::Copy(SquareMatrix* b){
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			b->matrix[i][j] = matrix[i][j];
		}
	}
}
void SquareMatrix::display() {
	for (int i = 0; i < size; i++) {
		std::cout << "현재 행:" << i << std::endl;
		for (int j = 0; j < size; j++) {
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}
/*Exercise28 시험계획:for 문을 통해 각 클래스에 대한 객체 a,b를 생성후 StoreValue함수를 사용하여 원하는 값을 대입시킨뒤 
Add,Subtract 함수를 사용하여 display 함수를 통해 각각의 객체에 대해 연산이 제대로 이루어졌는지 확인한다.*/
int main() {
	SquareMatrix a;
	a.MakeEmpty(50);
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
				a.StoreValue(i, j, 10);
			}
		}
	SquareMatrix b;
	b.MakeEmpty(50);
	for (int i= 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			b.StoreValue(i, j, 5);
		}
	}
	a.Add(&b);
	a.Subtract(&b);
	b.display();
}