#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Worker {
protected:
    string name; // ім'я
    int age; // вік
    float salary; // зарплата
public:
    Worker() : name("Невідомий"), age(0), salary(0.0f) {}
    Worker(string n, int a, float s) : name(n), age(a), salary(s) {}
    virtual ~Worker() {}
    virtual void print() const {
        cout << "Ім'я: " << name << ", Вік: " << age << ", Зарплата: " << salary << endl;
    }
    friend ostream& operator<<(ostream& os, const Worker& w) {
        os << "Ім'я: " << w.name << ", Вік: " << w.age << ", Зарплата: " << w.salary;
        return os;
    }

    friend istream& operator>>(istream& is, Worker& w) // введення даних працівника
    {
        cout << "Введіть ім'я: ";
        getline(is, w.name);
        cout << "Введіть вік: ";
        is >> w.age;
        cout << "Введіть зарплату: ";
        is >> w.salary;
        is.ignore(); // видаляємо символ нового рядка з буфера
        return is;
    }
};

class Family {
protected:
    string fatherName; // ім'я батька
    string motherName; // ім'я матері
    int numberOfChildren; // кількість дітей
public:
    Family() : fatherName("Невідомий"), motherName("Невідома"), numberOfChildren(0) {}
    Family(string fn, string mn, int nc) : fatherName(fn), motherName(mn), numberOfChildren(nc) {}
    virtual ~Family() {}
    virtual void print() const {
        cout << "Ім'я батька: " << fatherName << ", Ім'я матері: " << motherName << ", Кількість дітей: " << numberOfChildren << endl;
    }
    friend ostream& operator<<(ostream& os, const Family& f) {
        os << "Ім'я батька: " << f.fatherName << ", Ім'я матері: " << f.motherName << ", Кількість дітей: " << f.numberOfChildren;
        return os;
    }

    friend istream& operator>>(istream& is, Family& f) // введення даних родини
    {
        cout << "Введіть ім'я батька: ";
        getline(is, f.fatherName);
        cout << "Введіть ім'я матері: ";
        getline(is, f.motherName);
        cout << "Введіть кількість дітей: ";
        is >> f.numberOfChildren;
        is.ignore(); // видаляємо символ нового рядка з буфера
        return is;
    }
};

class WorkerFamily : public Worker, public Family {
protected:
    string address;// адреса
public:
    WorkerFamily() : address("Невідома") {}
    WorkerFamily(string n, int a, float s, string fn, string mn, int nc, string ad)
        : Worker(n, a, s), Family(fn, mn, nc), address(ad) {}
    virtual ~WorkerFamily() {}
    virtual void print() const {
        Worker::print();
        Family::print();
        cout << "Адреса: " << address << endl;
    }
    friend ostream& operator<<(ostream& os, const WorkerFamily& wf) {
        const Worker& w = wf;
        const Family& f = wf;

        os << w << ", " << f << ", Адреса: " << wf.address;
        return os;
    }

    friend istream& operator>>(istream& is, WorkerFamily& wf) {
        Worker& w = wf;
        Family& f = wf;

        cout << "Введіть дані працівника: " << endl;
        is >> w;
        cout << "Введіть дані сім'ї: " << endl;
        is >> f;
        cout << "Введіть адресу: ";
        getline(is, wf.address);

        return is;
    }

};

void main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Тестуємо клас Worker
    Worker w1("Джон Доу", 35, 50000.0f);
    w1.print();

    Worker w2;
    cin >> w2;
    cout << w2 << endl;

    // Тестуємо клас Family
    Family f1("Джон Доу", "Джейн Доу", 2);
    f1.print();

    Family f2;
    cin >> f2;
    cout << f2 << endl;

    // Тестуємо клас WorkerFamily
    WorkerFamily wf1("Джон Доу", 35, 50000.0f, "Джон Доу", "Джейн Доу", 2, "вул. Головна, 123");
    wf1.print();

    WorkerFamily wf2;
    cin >> wf2;
    cout << wf2 << endl;
}