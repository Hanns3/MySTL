#include <iostream>
#define DEBUG

using namespace std;

template<typename T>
class List
{

public:
	List();
	~List();

	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void clear();
	void pop_back();
	void removeAt(const int index);
	void insert(T data, const int index);
	void print(const int index);
	int GetSize() { return size; }
	T& operator[](const int index);
private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		Node* pPrev;
		T data;

		Node(T data=T(), Node* pNext=nullptr,Node* pPrev=nullptr )
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
		~Node()
		{
			
		}
	};
	Node<T>* head;
	Node<T>* tail;
	int size;

};

template<typename T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;

}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (head == nullptr)
	{
		head = tail = new Node<T>(data);
		size++;
	}
	else
	{
		tail->pNext = newNode;
		newNode->pPrev = tail;
		tail = newNode;
		size++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head, head);
	size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = this->head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::pop_back()
{
	Node<T>* current = this->tail;
	tail= tail->pPrev;
	size--;
	delete current;
	
}

template<typename T>
void List<T>::removeAt(const int index)
{
	if (!size)
	{
		cout << "List is empty"<<endl;
		return;
	}
	if (index > size)
	{
		cout << "Out of range"<<endl;
		return;
	}
	Node<T>* previous = this->head;
	for (int i = 0; i < index-1; i++)
	{
		previous = previous->pNext;
	}
	
	Node<T>* current = previous->pNext;
	Node <T>* next = current->pNext;
	if (next == nullptr)
	{
		pop_back();
	}
	else if (index == 0)
	{
		pop_front();
	}
	else
	{
		previous->pNext = next;
		next->pPrev = previous;
		delete current;
		size--;
	}
}

template<typename T>
void List<T>::insert(T data, const int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* temp = new Node<T>(data);
		Node<T>* previous = this->head;
		for (int i = 0; i < index-1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* current = previous->pNext;
		previous->pNext = temp;
		current->pPrev = temp;
		temp->pNext = current;
		temp->pPrev = previous;
		size++;
	}
}

template<typename T>
void List<T>::print(const int index)
{
	int mid = size / 2;
	
	if (mid >= index)
	{
		Node<T>* current = this->head;
#ifdef DEBUG
		cout << "start" << endl;
#endif // DEBUG
		for (int i = 0; i < size; i++)
		{
			if ((i) == index)
			{
				cout << current->data;
				break;
			}
			current = current->pNext;

		}
	}
	else
	{
		Node<T>* current = this->tail;
#ifdef DEBUG
		cout << "end" << endl;
#endif // DEBUG

		
		for (int i = size; i > 0; i--)
		{
			if ((i-1) == index)
			{
				cout << current->data;
				break;
			}
			else
			{
				current = current->pPrev;
			}
		}
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	Node<T>* current = this->head;
	if (index == -1)
	{
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		return current->data;
	}
	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			return current->data;
			break;
		}
		else
		{
			current = current->pNext;
		}
	}
}

int main()
{
	List<int> lst;
	for (int i = 0; i < 10; i++)
	{
		lst.push_back(i);
	}
	lst.print(7);
	return 0;
}
