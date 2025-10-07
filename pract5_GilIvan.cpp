// pract5_GilIvan.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Node {
	int data;
	Node* next;
	Node* prev;

	Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};


class DoublyLinkedList {
public:
	Node* head = nullptr;
	Node* tail = nullptr;

	void push_front(int n) {

		if (head == nullptr) { //список пустой
			head = new Node(n);
			return;
		}
		if (tail == nullptr) {
			Node* ptr = new Node(n);
			ptr->next = head;
			tail = head;
			tail->prev = ptr;
			head = ptr;
			return;
		}
		Node* ptr = new Node(n);
		head->prev = ptr;
		ptr->next = head;
		head = ptr;
	}

	void push_back(int n) {

		if (head == nullptr) {
			head = new Node(n);
			return;
		}
		if (tail == nullptr) {
			Node* ptr = new Node(n);
			ptr->prev = head;
			head->next = ptr;
			tail = ptr;
			return;
		}
		Node* ptr = new Node(n);
		tail->next = ptr;
		ptr->prev = tail;
		tail = ptr;
	}

	void pop_front() {
		if (head->next == nullptr) {
			head = nullptr;
			return;
		}
		if (head->next == tail) {
			head->next->prev = nullptr;
			head = head->next;

			tail = nullptr;
			head->next = nullptr;
			return;
		}
		head->next->prev = nullptr;
		head = head->next;
	}

	void pop_back() {
		if (tail == nullptr) {
			head = nullptr;
			return;
		}
		if (tail->prev == head) {
			tail = nullptr;
			head->next = nullptr;
			return;
		}
		tail->prev->next = nullptr;
		tail = tail->prev;
	}

	void sort() {
		if (head == nullptr || head->next == nullptr)
		{
			std::cout << "Нет списка или недостаточно символов для сортировки\n" << std::endl;
			return;
		}

		int count = 0;
		Node* ptrCount = head;
		while (ptrCount != nullptr) {
			count++;
			ptrCount = ptrCount->next;
		}

		for (int i = 0; i < count - 1; i++) {
			Node* ptr = head;
			bool swapped = false;

			while (ptr->next != nullptr) {
				if (ptr->data > ptr->next->data) {
					Node* first = ptr;
					Node* second = ptr->next;
					first->next = second->next;
					second->prev = first->prev;
					if (second->next != nullptr)
						second->next->prev = first;
					if (first->prev != nullptr)
						first->prev->next = second;
					second->next = first;
					first->prev = second;
					if (head == first)
						head = second;
					if (first->next == nullptr)
						tail = first;
					swapped = true;
				}
				else {
					ptr = ptr->next;
				}
			}
			if (!swapped)
			{
				break;
			}
		}
	}


	void remove_duplicates() {

		if (head == nullptr || head->next == nullptr) {
			std::cout << "Нет списка или недостаточно дублирующих символолов\n" << std::endl;
			return;
		}

		Node* ptr = head;
		Node* next = head->next;

		while (next != nullptr) {
			if (ptr->data == next->data) {
				ptr->next = next->next;
				if (next->next != nullptr)
					next->next->prev = ptr;
				next = nullptr;
				next = ptr->next;
			}
			else {
				ptr = next;
				next = next->next;
			}
		}
		tail = ptr;
	}

	void display_list() {
		Node* ptr = head;

		if (ptr == nullptr) {
			std::cout << "Лист пустой\n" << std::endl;
			return;
		}
		else {
			while (ptr->next != nullptr) {
				std::cout << ptr->data << std::endl;
				ptr = ptr->next;
			}
			if (tail != nullptr) {
				std::cout << tail->data << std::endl;
			}
		}
	}

};



int main()
{
	
	setlocale(LC_ALL, "Russian");
	DoublyLinkedList list = {};

	short choose = 0;

	while (true) {
		std::cout << "Введите номер действия \n 1. Добавить элемент в начало\n 2. Добавить элементв в конец\n 3. Удалить элемент с начала\n 4. Удалить элемент с конца\n 5. Отобразить список\n 6. Сортировать список\n 7. Удалить дубликаты \n 8. Выйти\n";
		std::cin >> choose;

		if (choose == 1) {
			std::cout << "Выбрано: Добавить элемент в начало\n Напишите число\n";
			int n;
			std::cin >> n;
			list.push_front(n);
		}
		else if (choose == 2) {
			std::cout << "Выбрано: Добавить элемент в конец\n Напишите число\n";
			int n;
			std::cin >> n;
			list.push_back(n);
		}
		else if (choose == 3) {
			std::cout << "Выбрано: Удалить элемент с начала\n";
			list.pop_front();
		}
		else if (choose == 4) {
			std::cout << "Выбрано: Удалить элемент с конца\n";
			list.pop_back();
		}
		else if (choose == 5) {
			std::cout << "Выбрано: Отобразить список\n";
			list.display_list();
		}
		else if (choose == 6) {
			std::cout << "Выбрано: Сортировать список\n";
			list.sort();
		}
		else if (choose == 7) {
			std::cout << "Выбрано: Удалить дубликаты\n";
			list.remove_duplicates();
		}
		else if (choose == 8) {
			std::cout << "Выбрано: Выйти\n Хорошего дня!\n";
			return false;
		}
		else {
			std::cout << "Выбран неверный номер действия\n";
		}
	}
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
