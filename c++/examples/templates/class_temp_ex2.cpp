#include <iostream>
using namespace std;

template <class T>
class Array {
    private:
        T *ptr;
        int size;

    public:
        Array(T arr[], int s);
        void display();
};

template <class T>
Array<T>::Array(T arr[], int s) {
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++) {
        ptr[i] = arr[i];
    }
}

template <class T>
void Array<T>::display() {
    for (int i = 0; i < size; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    Array<int> intArr(arr1, 5);
    cout << "Array of integers: ";
    intArr.display();

    char char2[5] = {'a', 'b', 'c', 'd', 'e'};
    Array<char> charArr(char2, 5);
    cout << "Array of characters: ";
    charArr.display();

    return 0;
}
