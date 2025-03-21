#include <iostream>
using namespace std;

template <typename T, int max>
T arrMin(T arr[], int size) {
    T min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    int intArr[] = {10, 20, 5, 15};
    cout << "Minimum value in intArr: " << arrMin<int, 4>(intArr, 4) << endl;

    double doubleArr[] = {1.2, 3.4, 0.5, 2.1};
    cout << "Minimum value in doubleArr: " << arrMin<double, 4>(doubleArr, 4) << endl;

    char charArr[] = {'a', 'A', '1', '6'};
    cout << "Minimum value in charArr: " << arrMin<char, 4>(charArr, 4) << endl;

    return 0;
}
