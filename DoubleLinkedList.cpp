#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList {
private:
	struct Node {
		Node* pNext;
		Node* pPrev;
		T data;
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr) {
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	Node* head;
	Node* tail;
	int Size;
public:
	DoubleLinkedList() :head{ nullptr }, tail{ nullptr }, Size{ 0 } { }
	DoubleLinkedList(const DoubleLinkedList& other) : head{ nullptr }, tail{ nullptr }, Size{ 0 } {
		Node* current = other.head;
		while (current != nullptr) {
			push_back(current->data);
			current = current->pNext;
		}
	}
	void display() {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->pNext;
		}
	}
	void push_back(T value) {
		Node* newNode = new Node(value);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->pPrev = tail;
			tail->pNext = newNode;
			tail = newNode;

		}
		Size++;
	}
	void push_front(T value) {
		Node* newNode = new Node(value);
		newNode->pPrev = nullptr;
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			head->pPrev = newNode;
			newNode->pNext = head;
			head = newNode;
		}
		Size++;
	}
	void pop_back() {
		if (head == nullptr) {
			return;
		}
		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node* tmp = tail;
			tail = tail->pPrev;
			delete tmp;
			tail->pNext = nullptr;
		}
		Size--;

	}
	void pop_front() {
		if (head == nullptr) {
			return;
		}
		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node* tmp = head;
			head = head->pNext;
			delete tmp;

			head->pPrev = nullptr;
		}
		Size--;
	}
	void insert(T value, int index) {
		if (index > Size || index < 0) {
			return;
		}
		if (index == 0) {
			push_front(value);
			return;
		}
		else if (index == Size) {
			push_back(value);
			return;
		}
		else {
			Node* current = nullptr;
			int currentIndex;
			if (index <= Size / 2) {
				current = head;
				currentIndex = 0;
				while (currentIndex < index - 1) {
					current = current->pNext;
					currentIndex++;
				}
			}
			else {
				current = tail;
				currentIndex = Size - 1;
				while (currentIndex > index - 1) {
					current = current->pPrev;
					currentIndex--;
				}
			}

			Node* newNode = new Node(value);

			newNode->pNext = current->pNext;
			current->pNext = newNode;
			newNode->pPrev = current;
			if (newNode->pNext != nullptr) {
				newNode->pNext->pPrev = newNode;
			}
			Size++;
		}
	}
	void erase(int index) {
		if (index >= Size || index < 0) {
			return;
		}
		if (index == 0) {
			pop_front();
			return;
		}
		else if (index == Size - 1) {
			pop_back();
			return;
		}
		else {
			Node* current = nullptr;
			int currentIndex;
			if (index <= Size / 2) {
				current = head;
				currentIndex = 0;
				while (currentIndex < index - 1) {
					current = current->pNext;
					currentIndex++;
				}
			}
			else {
				current = tail;
				currentIndex = Size - 1;
				while (currentIndex > index - 1) {
					current = current->pPrev;
					currentIndex--;
				}
			}

			Node* tmp = current->pNext;
			if (tmp == nullptr) return;
			
			current->pNext = tmp->pNext;
			if (tmp->pNext != nullptr) {
				tmp->pNext->pPrev = current;
			}
			delete tmp;
			Size--;
		}
	}
	bool find(T value) {
		Node* current = head;
		while (current != nullptr) {
			if (current->data == value) {
				return true;
			}
			current = current->pNext;
		}
		return false;
	}
	void reverse() {
		if (head == nullptr) {
			return;
		}
		Node* current = head;
		tail = head;
		while (current != nullptr) {
			Node* tmp = current->pNext;
			current->pNext = current->pPrev;
			current->pPrev = tmp;
			if (tmp == nullptr) {
				head = current;
			}
			current = tmp;
		}
	}
	int size() {
		return Size;
	}
	bool is_empty() {
		return Size == 0;
	}
	void clear() {
		while (Size != 0) {
			pop_front();
		}
	}
	~DoubleLinkedList() {
		clear();
	}

	const T& operator[] (int index) const {
		if (index < 0 || index > Size - 1) {
			throw std::out_of_range("Index out of bounds");
		}
		Node* current;
		if (index <= Size / 2) {
			current = head;
			for (int i = 0; i < index; ++i) {
				current = current->pNext;
			}
		}
		else {
			current = tail;
			for (int i = Size - 1; i > index; --i) {
				current = current->pPrev;
			}
		}
		return current->data;
	}
	T& operator[] (int index) {
		if (index < 0 || index > Size - 1) {
			throw std::out_of_range("Index out of bounds");
		}
		Node* current;
		if (index <= Size / 2) {
			current = head;
			for (int i = 0; i < index; ++i) {
				current = current->pNext;
			}
		}
		else {
			current = tail;
			for (int i = Size - 1; i > index; --i) {
				current = current->pPrev;
			}
		}
		return current->data;
	}
	DoubleLinkedList& operator= (const DoubleLinkedList& other) {
		if (this == &other) {
			return *this;
		}
		clear();
		Node* current = other.head;
		while (current != nullptr) {
			push_back(current->data);
			current = current->pNext;
		}

		return *this;
	}
};



int main() {
	DoubleLinkedList<int> list;

	list.push_back(10);
	list.push_back(20);
	list.push_front(5);
	list.push_back(30);
	list.push_back(40);

	list.display();
	cout << "\n";

	list.pop_front();
	list.pop_back();
	list.display();
	cout << "\n";

	list.insert(15, 1);
	list.insert(25, 3);
	list.display();
	cout << "\n";

	list.erase(2);
	list.display();
	cout << "\n";

	cout << "Size: " << list.size() << "\n";
	cout << "Find 25: " << list.find(25) << "\n";
	cout << "Find 100: " << list.find(100) << "\n";

	cout << "Index 1: " << list[1] << "\n";
	list[1] = 99;
	cout << "Index 1 after change: " << list[1] << "\n";

	list.reverse();
	list.display();
	cout << "\n";

	DoubleLinkedList<int> copyList = list;
	copyList.display();
	cout << "\n";

	DoubleLinkedList<int> assignList;
	assignList.push_back(111);
	assignList = list;
	assignList.display();
	cout << "\n";

	list.clear();
	cout << "Is empty: " << list.is_empty() << "\n";
}
