#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
    T* arr;
    int size;
    int capacity;

public:

    Queue()
    {
        arr = new T[10];
        size = 0;
        capacity = 10;
    }

    bool empty()
    {
        return size == 0 ? true : false;
    }

    int Size()
    {
        return size;
    }

    int front()
    {
        return arr[0];
    }

    int back()
    {
        return arr[size - 1];
    }

    void resize()
    {
        T* temp;
        capacity += 10;
        temp = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

    void push(T value)
    {
        if (size-1 == capacity)
            resize();
        arr[size] = value;
        size++;
    }

    void pop()
    {
        T* temp = arr;
        arr = nullptr;
        arr = new T[capacity];
        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = temp[i];
        }
        size--;
        delete[] temp;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue<int> q;
    for (int i = 1; i < 10; i++)
    {
        q.push(i);
    }
    q.print();
    cout<< "\nback is: "<<q.back()<< "   front is: "<<q.front();
    q.pop();
    cout << endl;
    q.print();
    cout << "Size of queue is: " << q.Size();
}