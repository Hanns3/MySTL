#include <iostream>

using namespace std;

template<typename T>
class MyVector
{
public:

    MyVector(int size = 0)
    {
        SIZE = size;
        arr = new T[SIZE]{};
    }

    MyVector(MyVector& other)
    {
        this->SIZE = other.SIZE;
        arr = new T[SIZE]{};
        for (int i = 0; i < SIZE; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }

    ~MyVector()
    {
        delete[] arr;
    }

    int GetSize()
    {
        return SIZE;
    }

    T* begin()
    {
        return arr;
    }
    T* end()
    {
        return arr + SIZE;
    }

    void push_back(T value)
    {

        T* temp;
        temp = new T[SIZE + 1];
        for (int i = 0; i < SIZE; i++)
        {
            temp[i] = arr[i];
        }
        temp[SIZE] = value;
        SIZE++;
        delete[] arr;
        arr = temp;
  
        
    }
    void erase(const int index)
    {
        T* temp;
        temp = new T[SIZE - 1];
        for (int i = 0; i < SIZE; i++)
        {
            if (i == index)
            {
                continue;
            }
            else if (i<index)
            {
                temp[i] = arr[i];
            }
            else if (i>index)
            {
                temp[i - 1] = arr[i];
            }
            
        }
        delete[] arr;
        SIZE--;
        arr = temp;
    }

    void push_front(T value)
    {
        T *temp = new T[SIZE + 1];
        temp[0] = value;
        for (int i = 0; i < SIZE; i++)
        {
            temp[i + 1] = arr[i];
        }
        SIZE++;
        delete[] arr;
        arr = temp;
    }

    void Print()
    {
        for (int i = 0; i < GetSize(); i++)
        {
            cout << i + 1 << ". " << arr[i] << endl;
        }
        cout << endl;

    }

    void sort()
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                T temp;
                if (arr[i] < arr[k])
                {
                    temp = arr[k];
                    arr[k] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }

    bool operator>(const MyVector& other)
    {
        int size;
        if (this->SIZE > other.SIZE)
        {
            size = other.SIZE;
        }
        else
        {
            size = this->SIZE;
        }
        for (int i = 0; i < size ; i++)
        {
            if (this->arr[i] > other.arr[i])
            {
                return 1;
            }
            else if (this->arr[i] == other.arr[i])
            {
                continue;
            }
            else return 0;
        }
        if (this->SIZE > other.SIZE)
        {
            return 1;
        }
        else
            return 0;
    }

    T& operator[](const int index)
    {
        return arr[index];
    }

    MyVector& operator+(const MyVector& other)
    {
        if (this->SIZE == other.SIZE)
        {
            for (int i = 0; i < SIZE; i++)
            {
                this->arr[i] = this->arr[i] + other.arr[i];
            }
        }
        else
        {
            cout << "cant add this two vectors, because they have differents size"<<endl;
            return *this;
        }
    }
private:
    T* arr;
    int SIZE;
};


int main()
{

    MyVector<int> arr;
    MyVector<int> vec;
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(4);
    arr.push_back(7);
    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(7);
    arr.push_front(1);

    MyVector<int> col = arr + vec;

    col.Print();

}