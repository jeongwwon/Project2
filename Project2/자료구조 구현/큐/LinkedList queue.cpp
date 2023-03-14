#include<iostream>

class node {
public:
	node* next;
	int data;
};

class list {
public:
	node* front, * rear;
	int data;
	int count;

	list() {
		front = NULL;
		rear = NULL;
		count = 0;
	};
	void is_empty();
	void push(int data);
	bool insert(int index, int data);
	void dequeue();
	void print();
};

void list::is_empty() {
	if (front == NULL) {
		std::cout << "큐가 비었습니다" << std::endl;
	}
}
void list::push(int data) {
	node* temp = new node;
	temp->data = data;
	temp->next = nullptr;
	if (front == NULL) {
		rear = temp;
		front = temp;
	}
	else {
		rear->next = temp; //  *(rear).next=temp
		rear = temp;
	}
	count++;
}
bool list::insert(int index, int data) {
	if (index > count) {
		std::cout << "잘못된 index 번호 입니다" << std::endl;
		return 0;
	}
	if (front == NULL) {
		std::cout << "데이터가 존재하지 않습니다" << std::endl;
		return 0;
	}
	else {
		node* newnode = new node;
		node* temp = front;
		newnode->data = data;
		newnode->next = NULL;
			for (int i = 0; i < index - 1; i++) {   //1  0 1 2
				temp = temp->next; // *(rear).next
			}
			if (temp->next != NULL) {
				newnode->next = temp->next;
			}
			temp->next = newnode;
			std::cout << "인덱스:" << index << "에 데이터:" << data << "가 추가되었습니다." << std::endl;
			count++;
			return 1;
		}
	}

	void list::dequeue() {
		if (rear == front) {
			std::cout << "큐가 비었습니다." << std::endl;
		}
		else {
			front = front->next;
		}
	}
	void list::print() {
		if (front == rear) {
			std::cout << "데이터가 비었습니다" << std::endl;
		}
		for (node* temp = front; temp != NULL; temp = temp->next) {
			std::cout << temp->data << ' ';
		}
	}
	int main() {
		list q;
		std::cout << "\n 원하는 작업을 선택하시오.\n" << "(1)dequeue (2)enqueue (3)insert (4)print (5)terminate" << std::endl;
		int choice;
		int data;
		std::cin >> choice;
		while (choice != 5) {
			switch (choice) {
			case 1:
				q.dequeue();
				break;
			case 2:
				std::cout << "데이터를 입력하세요" << std::endl;
				std::cin >> data;
				q.push(data);
				std::cout << "데이터:" << data << " 이 추가되었습니다." << std::endl;
				break;
			case 3:
				int inde;
				std::cout << "인덱스 번호와 data를 입력하세요" << std::endl;
				std::cin >> inde;
				std::cin >> data;
				if (q.insert(inde, data)) {
					std::cout << "index:" << inde << "data:" << data << "가 추가되었습니다." << std::endl;
				}
			case 4:
				q.print();
			}
			std::cout << "\n 원하는 작업을 선택하시오.\n" << "(1)dequeue (2)enqueue (3)insert (4)print (5)terminate" << std::endl;
			std::cin >> choice;
		}
	}