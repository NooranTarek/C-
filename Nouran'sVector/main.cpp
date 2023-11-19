#include <iostream>

using namespace std;

template <typename T>
class List {
protected:
    T *items;
    int size;
    int index;

public:
    List()
    {
        size = 2;
        index = -1;
        items = new T[size];
    }

    List(int size)
    {
        this->size = size;
        index = -1;
        items = new T[size];
    }

    void Add(T data)
    {
        if (index == size - 1)
        {
            Extend();
        }
        index++;
        items[index] = data;
    }

    void Extend()
    {
        T *temp = new T[size * 2];
        for (int i = 0; i < size; i++)
        {
            temp[i] = items[i];
        }
        delete[] items;
        items = temp;
        size *= 2;
    }

    int GetSize() const
    {
        return size;
    }

    ~List()
    {
        delete[] items;
    }
};

int main()
{
    List<int> newList;
    newList.Add(3);
    newList.Add(7);
    newList.Add(11);
    newList.Add(5);
    cout << "size of the array after extending it : " << newList.GetSize() << endl;

    return 0;
}
