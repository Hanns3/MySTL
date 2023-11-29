#include <iostream>


template <class T>
class Stack {
private:
    T* arr;
    int size;

public:
    Stack()
    {
        arr = new T;
        size = 0;
    }
    ~Stack()
    {
        delete[] arr;
    }

    T get_value()
    {
        return arr[size-1];
    }

    int get_size()
    {
        return size;
    }

    bool isEmpty()
    {
        if (!size)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void push(T value)
    {
        if (!size)
        {
            delete[] arr;
            arr = new T[1];
            arr[0] = value;
            size++;
        }
        else
        {
            T* temp = new T[size];
            temp = arr;
            arr = nullptr;
            arr = new T[size + 1];
            for (int i = 0; i < size; i++)
            {
                arr[i] = temp[i];
            }
            arr[size] = value;
            size++;
            delete[] temp;
        }
    }

    void pop()
    {
        if (!size)
        {
            return;
        }
        else
        {
            T* temp = new T[size];
            temp = arr;
            arr = nullptr;
            arr = new T[size - 1];
            for (int i = 0; i < size-1; i++)
            {
                arr[i] = temp[i];
            }
            size--;
            delete[] temp;
        }

    }
    
    int search(T value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                return i+1;
            }
        }
        return 0;           // if cant find element function returns 0
    }

};

int main()
{
    Stack<int> st;

    for (int i = 0; i < 10; i++)
    {
        st.push(i);
    }
    std::cout << st.get_size() << std::endl << std::endl;
    std::cout << st.search(6) << std::endl;
}