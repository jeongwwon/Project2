#include<iostream>
class node {
public:
	int data;
	node* next;
};

class list {
public:
	int count;
	node* head;
	list() {
		head = NULL;
		count = 0;
	}
	void insert(int index, int data);
	void remove(int index);
	void print();
};

void list::insert(int index, int data) {
	if (index <= list::count) {
		node* newnode = new node; //���ο� ��带 class node�� �����ͷ� �ʱ�ȭ
		newnode->data = data;        //�ʱ�ȭ�� data�� �Ķ���ͷ� �ʱ�ȭ
		newnode->next = NULL; 
		if (head == NULL) {             //list�� head���� ������ ���ο� ����� �ּҸ� head�� �Է�
			head = newnode;
		}
		// list�� ���������
		else {
			node* temp = head; // ������� �ʴٸ� head�� ����Ű�� ������ temp ����
			for (int i = 0; i < index-1 ; i++) //index=2
			{
				temp = temp->next;   // 0 (1) 3newnode.next->{2}
			}
			if (temp->next != NULL) {
				newnode->next = temp->next; //���� ����� ������ ���ο� ����� �������� ����
			}
			temp->next = newnode;     // 1.ó���� �ε���-1 ��ŭ�� ���� head�� next�� head�� ���� 2.head�� next�� ������� �ʴٸ� ������ head�� next�� newnode��
			//next�� ���� 3.newnode�� head�� next�� ����
		}
		count++;
		std::cout << "index:" << index <<',' << "data:" << data << "  " << "inserted!" << std::endl;
	}
	else
		std::cout << "fail!" << std::endl;
}
void list::remove(int index) {
	if (index < list::count) {
		node* temp = head;
		int tdata;
		if (index == 0) {  //����Ʈ ���� �տ��� ����
			tdata = head->data;
			head = head->next;
			delete temp;
		}
		else
		{
			node* prev = head;    //prev �� head������
			for (int i = 0; i < index - 1; i++)
			{
				prev = prev->next;  // index-1 ��ŭ head�̵�
			}
			temp = prev->next;   //����� head�� next�� temp�� ����  (*prev).next
			tdata = temp->data;  //temp�� data�� tdata�� �Ҵ�
			prev->next = temp->next; //temp�� next�� ����� head�� next�� ���� -> temp ����
			delete temp;
		}
		std::cout << "index:" << index <<',' << "data:" << tdata << "  " << "deleted!!" << std::endl;
}
	else {
		std::cout << "fail remove!" << std::endl;
	}
	count--;
}
void list::print()
{
	for (node* temp = head; temp != NULL; temp = temp->next)
	{
		std::cout << temp->data << " ";
	}
	std::cout << std::endl;
}

int main()
{

	list llist;

	for (int i = 0; i < 5; i++) {
		llist.insert(i, i);
	}

	llist.print();

	llist.remove(3);
	llist.remove(8);

	llist.insert(3, 10);
	llist.remove(10);
	
	llist.print();
	
	std::cout << llist.count << "  this ";
}




