#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    double salary;

public:
    virtual void getData() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void displayData() {
        cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << endl;
    }

    virtual void bonus() {
        double b = 0.05 * salary;
        cout << "Bonus (Person): " << b << endl;
    }

    virtual ~Person() {}
};

class Admin : virtual public Person {
public:
    void getData() override {
        Person::getData();
    }

    void displayData() override {
        cout << "[Admin] ";
        Person::displayData();
    }

    void bonus() override {
        double b = 0.10 * salary;
        cout << "Bonus (Admin): " << b << endl;
    }
};

class Account : virtual public Person {
public:
    void getData() override {
        Person::getData();
    }

    void displayData() override {
        cout << "[Account] ";
        Person::displayData();
    }

    void bonus() override {
        double b = 0.12 * salary;
        cout << "Bonus (Account): " << b << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        Person::getData();
    }

    void displayData() override {
        cout << "[Master] ";
        Person::displayData();
    }

    void bonus() override {
        double b = 0.20 * salary;
        cout << "Bonus (Master): " << b << endl;
    }
};

int main() {
    Person* emp;

    Admin a;
    Account acc;
    Master m;

    cout << "--- Admin Employee ---" << endl;
    emp = &a;
    emp->getData();
    emp->displayData();
    emp->bonus();

    cout << "\n--- Account Employee ---" << endl;
    emp = &acc;
    emp->getData();
    emp->displayData();
    emp->bonus();

    cout << "\n--- Master Employee ---" << endl;
    emp = &m;
    emp->getData();
    emp->displayData();
    emp->bonus();

    return 0;
}

