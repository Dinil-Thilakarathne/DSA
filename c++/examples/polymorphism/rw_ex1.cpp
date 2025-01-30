#include <iostream>
using namespace std;

// Abstract Base Class (Interface for all accounts)
class BankAccount {
protected:
    double balance;
public:
    BankAccount(double bal) : balance(bal) {}

    virtual void calculateInterest() = 0; // Pure virtual function

    void showBalance() { cout << "Balance: $" << balance << endl; }
};

// Savings Account (Simple interest: 4% per year)
class SavingsAccount : public BankAccount {
public:
    SavingsAccount(double bal) : BankAccount(bal) {}

    void calculateInterest() override {
        double interest = balance * 0.04; // 4% interest
        balance += interest;
        cout << "Savings Account Interest: $" << interest << endl;
    }
};

// Current Account (No interest, but charges $10 monthly)
class CurrentAccount : public BankAccount {
public:
    CurrentAccount(double bal) : BankAccount(bal) {}

    void calculateInterest() override {
        cout << "No interest for Current Account." << endl;
        balance -= 10; // Service charge
        cout << "Service Charge: $10 deducted." << endl;
    }
};

// Fixed Deposit (Higher interest: 7% per year)
class FixedDepositAccount : public BankAccount {
public:
    FixedDepositAccount(double bal) : BankAccount(bal) {}

    void calculateInterest() override {
        double interest = balance * 0.07; // 7% interest
        balance += interest;
        cout << "Fixed Deposit Interest: $" << interest << endl;
    }
};

int main() {
    // Using base class pointers for polymorphism
    BankAccount* acc1 = new SavingsAccount(1000);
    BankAccount* acc2 = new CurrentAccount(1000);
    BankAccount* acc3 = new FixedDepositAccount(1000);

    cout << "Before Interest Calculation:\n";
    acc1->showBalance();
    acc2->showBalance();
    acc3->showBalance();

    cout << "\nApplying Interest Calculation:\n";
    acc1->calculateInterest();
    acc2->calculateInterest();
    acc3->calculateInterest();

    cout << "\nAfter Interest Calculation:\n";
    acc1->showBalance();
    acc2->showBalance();
    acc3->showBalance();

    // Free allocated memory
    delete acc1;
    delete acc2;
    delete acc3;

    return 0;
}
