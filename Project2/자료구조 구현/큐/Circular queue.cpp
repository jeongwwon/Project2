#include<iostream>
class circularqueue {
private:
	int queue[100] = { 0, };
	int front;
	int rear;
	int maxqueuesize;
public:
	circularqueue(int) ;
	void is_empty();
	void is_full();
	void enqueue(int item);
	void dequeue();
	void showqueue();
};

circularqueue::circularqueue(int maxqueuesize):maxqueuesize(maxqueuesize) {
	rear = 0;
	front = 0;
	}

void circularqueue::is_empty() {
	if (front%maxqueuesize == rear%maxqueuesize) {
		std::cout << "큐가 비었습니다." << std::endl;
	}
}
void circularqueue::is_full() {
	if (front%maxqueuesize == (rear + 1) % maxqueuesize) {
		std::cout << "큐가 꽉찼습니다." << std::endl;
	}
}
void circularqueue::enqueue(int item) {
	if (front%maxqueuesize == (rear + 1) % maxqueuesize) {
		is_full();
	}
	else {
		rear = ++rear % maxqueuesize;
		queue[rear] = item;
		std::cout << rear << "번째에 " << item << "이 enqueue 되었습니다." << '\n';
	}
}
void circularqueue::dequeue() {
	if (front%maxqueuesize == rear%maxqueuesize) {
		is_empty();
	}
	else {
		std::cout << front % maxqueuesize << "번째에" << queue[front % maxqueuesize] << "이 dequeue 되었습니다." << '\n';
		front=front++%maxqueuesize;
	}
}

void circularqueue::showqueue() {
	if (front%maxqueuesize == rear%maxqueuesize) {
		is_empty();
	}
	else if(0<(rear%maxqueuesize)-(front%maxqueuesize)){
		std::cout << "현재 데이터는" << std::endl;
		for (int i = 0; i < (rear%maxqueuesize) - (front % maxqueuesize); i++) {
			std::cout << queue[((front % maxqueuesize) + i) %maxqueuesize] << std::endl;
		}
	}
	else if ((rear%maxqueuesize) - (front%maxqueuesize) < 0) {
		std::cout << "현재 데이터는" << std::endl;
		for (int i = 0; i < (rear % maxqueuesize) - (front % maxqueuesize)+maxqueuesize; i++) {
			std::cout << queue[(front + i) % maxqueuesize] << std::endl;
		}
	}
	std::cout << "front:" << front << "rear:" << rear << std::endl;
}
int main() {
	int maxqueuesize = 0;
	std::cout << "회전큐의 크기를 입력하세요." << std::endl;
	std::cin >> maxqueuesize;
	circularqueue cq(maxqueuesize);
	int choice = 0;
	int item = 0;
	std::cout << "\n 원하는 작업을 선택하세요\n" << "(1)dequeue (2)enqueue (3)showqueue (4)종료:\n";
	std::cin >> choice;
	while (choice != 4) {
		switch (choice) {
		case 1:cq.dequeue();
			break;
		case 2:
			std::cout << "삽입할 수를 입력하세요:\n";
			std::cin >> item;
			cq.enqueue(item);
			break;
		case 3:
			cq.showqueue();
			break;
		}
		/*std::cout << "\n원하는 작업을 입력하세요 \n" << "(1)dequeue (2)enqueue (3)showqueue (4)종료:\n";
		std::cin >> choice;*/
	}
}