#include <iostream>
using namespace std;

class Drawable {    // Interface
    public:
        virtual void draw() = 0;
        virtual void resize() = 0;
        virtual ~Drawable() {} // Virtual destructor
};

class Rectangle : public Drawable {
    public:
        void draw()  {
            cout << "Drawing Rectangle" << endl;
        }

        void resize() {
            cout << "Resizing Rectangle" << endl;
        }
};


int main()
{
    Rectangle r;
    r.draw();
    r.resize();
    return 0;
}
