#include <iostream>

using namespace std;


template <typename T>
class MyList
{
public:
    MyList()
    {
        size = 0;
        head = nullptr;
    }


    MyList(T data)
    {
        head = new Node<T>(data);
        size = 1;
    }


    int GetSize() { return size; }

    void insert(T data, const int index)
    {
        if (index == 0)
        {
            push_front(data);
        }
        else
        {
            Node<T>* previous = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                previous = previous->pNext;
            }
            Node<T> * newNode = new Node<T>(data, previous->pNext);
            previous->pNext = newNode;
            size++;
        }
    }

    void removeAt(const int index)
    {
        if (!size)
        {
            cout << "List is empty"<<endl;
            return;
        }
        if (index > size-1)
        {
            cout << "Out of range" << endl;
            return;
        }
        Node<T>* previous = this->head;
        for (int i = 0; i < index-1; i++)
        {
            previous = previous->pNext;
        }
        Node<T>* current = previous->pNext;
        if (index == 0)
        {
            pop_front();
            return;
        }
        if (index == size)
        {
            pop_back();
            return;
        }
        previous->pNext = current->pNext;
        delete current;
        size--;
    }

    void pop_front()
    {
        Node<T>* current = this->head;
        head = head->pNext;
        delete current;
        size--;
    }

    void clear()
    {
        while (size)
        {
            pop_front();
        }
    }
    void push_back(T data)
    {
        if (head == nullptr)
        {
            head = new Node<T>(data);
            size++;
        }
        else
        {
            Node<T>* current = this->head;
            while (current->pNext != nullptr)
            {
                current = current->pNext;
            }
            current->pNext = new Node<T>(data);
            size++;
        }
    }
    void push_front(T data)
    {
        head = new Node<T>(data, head);
        size++;
    }

    void pop_back()
    {
        Node<T>* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        delete current;
        size--;
    }

    void print()
    {
        Node<T>* current = this->head;
        for (int i = 0; i < size; i++)
        {
            cout << current->data<<endl;
            current=current->pNext;
        }
            
    }

    T& operator[](const int index)
    {
        int counter = 0;
        Node<T>* current = this->head;
        if (size == 0)
        {
            cout << "List is empty";
            return;
        }
        while (current != nullptr)
        {
            if (counter == index)
            {
                return current->data;
            }
            current = current->pNext;
            counter++;
        }

    }

    ~MyList()
    {
        clear();
    }

private:
    template <typename T>
    class Node
    {
    public:
        T data;
        Node* pNext;

        Node(T data, Node* pnext = nullptr)
        {
            this->data = data;
            this->pNext = pnext;
        }
        Node(const Node& other)
        {
            this->data = other->data;
            this->pNext = other->pNext;
        }
    };

    Node<T> *head;
    int size;
};

int main()
{
    MyList<int> lst;
    for (int i = 0; i < 10; i++)
    {
        lst.push_back(i);
    }
    lst.print();
    
    cout << "pop_back" << endl;
    lst.print();
    lst.removeAt(9);
    cout << "removeAt" << endl;
    lst.print();


    return 0;
}