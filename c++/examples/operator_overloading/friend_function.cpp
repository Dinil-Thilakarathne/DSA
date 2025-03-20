#include <iostream>
using namespace std;

class Point {
    private:
        int x, y;

    public:
        Point(int a, int b) : x(a), y(b) {}

        // Declare friend function
        friend ostream& operator<<(ostream& out, const Point& p);
};

// Friend function definition
ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

int main() {
    Point p1(5, 10);
    cout << "Point: " << p1 << endl; // Calls the overloaded << operator
    return 0;
}
