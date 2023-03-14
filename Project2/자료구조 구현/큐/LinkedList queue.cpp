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
		std::cout << "ť�� ������ϴ�" << std::endl;
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
		std::cout << "�߸��� index ��ȣ �Դϴ�" << std::endl;
		return 0;
	}
	if (front == NULL) {
		std::cout << "�����Ͱ� �������� �ʽ��ϴ�" << std::endl;
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
			std::cout << "�ε���:" << index << "�� ������:" << data << "�� �߰��Ǿ����ϴ�." << std::endl;
			count++;
			return 1;
		}
	}

	void list::dequeue() {
		if (rear == front) {
			std::cout << "ť�� ������ϴ�." << std::endl;
		}
		else {
			front = front->next;
		}
	}
	void list::print() {
		if (front == rear) {
			std::cout << "�����Ͱ� ������ϴ�" << std::endl;
		}
		for (node* temp = front; temp != NULL; temp = temp->next) {
			std::cout << temp->data << ' ';
		}
	}
	int main() {
		list q;
		std::cout << "\n ���ϴ� �۾��� �����Ͻÿ�.\n" << "(1)dequeue (2)enqueue (3)insert (4)print (5)terminate" << std::endl;
		int choice;
		int data;
		std::cin >> choice;
		while (choice != 5) {
			switch (choice) {
			case 1:
				q.dequeue();
				break;
			case 2:
				std::cout << "�����͸� �Է��ϼ���" << std::endl;
				std::cin >> data;
				q.push(data);
				std::cout << "������:" << data << " �� �߰��Ǿ����ϴ�." << std::endl;
				break;
			case 3:
				int inde;
				std::cout << "�ε��� ��ȣ�� data�� �Է��ϼ���" << std::endl;
				std::cin >> inde;
				std::cin >> data;
				if (q.insert(inde, data)) {
					std::cout << "index:" << inde << "data:" << data << "�� �߰��Ǿ����ϴ�." << std::endl;
				}
			case 4:
				q.print();
			}
			std::cout << "\n ���ϴ� �۾��� �����Ͻÿ�.\n" << "(1)dequeue (2)enqueue (3)insert (4)print (5)terminate" << std::endl;
			std::cin >> choice;
		}
	}