#include <iostream>
using namespace std;

template <typename T>
class Pair {
    private:
        T first, second;

    public:
        Pair(T f, T s) : first(f), second(s) {}

        T getFirst() const { return first; }
        T getSecond() const { return second; }

        void setFirst(T f) { first = f; }
        void setSecond(T s) { second = s; }

        void display() const {
            cout << "Pair: (" << first << ", " << second << ")" << endl;
        }
};


int main()
{
    Pair<int> intPair(10, 20);
    intPair.setFirst(50);
    intPair.display();

    Pair<double> doublePair(3.5, 4.5);
    doublePair.display();

    Pair<char> charPair('a', 'b');
    charPair.display();

    return 0;
}
