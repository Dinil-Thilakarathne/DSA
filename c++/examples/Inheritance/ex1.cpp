#include <iostream>
#include <string>
using namespace std;

// Base class for single inheritance
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    void displayPersonInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class for single inheritance
class Librarian : public Person {
private:
    string employeeID;

public:
    Librarian(string n, int a, string id) : Person(n, a), employeeID(id) {}
    void displayLibrarianInfo() const {
        displayPersonInfo();
        cout << "Employee ID: " << employeeID << endl;
    }
};

// Another base class for multiple inheritance
class Membership {
protected:
    string membershipID;
    string membershipType;

public:
    Membership(string id, string type) : membershipID(id), membershipType(type) {}
    void displayMembershipInfo() const {
        cout << "Membership ID: " << membershipID << ", Type: " << membershipType << endl;
    }
};

// Derived class for multiple inheritance
class Member : public Person, public Membership {
protected:
    int borrowedBooks;

public:
    Member(string n, int a, string id, string type, int books)
        : Person(n, a), Membership(id, type), borrowedBooks(books) {}

    void displayMemberInfo() const {
        displayPersonInfo();
        displayMembershipInfo();
        cout << "Borrowed Books: " << borrowedBooks << endl;
    }
};

// Derived class for multilevel inheritance
class PremiumMember : public Member {
private:
    float discountRate;

public:
    PremiumMember(string n, int a, string id, string type, int books, float discount)
        : Member(n, a, id, type, books), discountRate(discount) {}

    void displayPremiumMemberInfo() const {
        displayMemberInfo();
        cout << "Discount Rate: " << discountRate << "%" << endl;
    }
};

int main() {
    // Single Inheritance: Librarian
    Librarian librarian("Alice", 35, "L123");
    cout << "Librarian Information:" << endl;
    librarian.displayLibrarianInfo();
    cout << endl;

    // Multiple Inheritance: Member
    Member member("Bob", 28, "M456", "Standard", 3);
    cout << "Member Information:" << endl;
    member.displayMemberInfo();
    cout << endl;

    // Multilevel Inheritance: Premium Member
    PremiumMember premiumMember("Charlie", 40, "P789", "Premium", 5, 15.0f);
    cout << "Premium Member Information:" << endl;
    premiumMember.displayPremiumMemberInfo();
    cout << endl;

    return 0;
}
