#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

class Function 
{
public:
    virtual double calculate(double x) = 0;
};

class Line : public Function 
{
private:
    double a, b;

public:
    Line(double _a, double _b) : a(_a), b(_b) {}

    virtual double calculate(double x) {
        return a * x + b;
    }
};

class Ellipse_ : public Function 
{
private:
    double a, b;

public:
    Ellipse_(double _a, double _b) : a(_a), b(_b) {}

    virtual double calculate(double x) 
    {
        return b * sqrt(1 - pow(x / a, 2));    
    }
};

class Hyperbola : public Function
{
private:
    double a, b;

public:
    Hyperbola(double _a, double _b) : a(_a), b(_b) {}

    virtual double calculate(double x) 
    {
         return b * sqrt(pow(x / a, 2) - 1);  
    }
};

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a, b, x;
    cout << "Пряма\n";
    cout << "Введіть а: "; cin >> a;
    cout << "Введіть b: "; cin >> b;
    Line l(a, b);

    cout << "Еліпс\n";
    cout << "Введіть а: "; cin >> a;
    cout << "Введіть b: "; cin >> b;
    Ellipse_ e(a, b);

    cout << "\nГіпербола\n";
    cout << "Введіть а: "; cin >> a;
    cout << "Введіть b: "; cin >> b;
    Hyperbola h(a, b);

    cout << "\nВведіть х: "; cin >> x;
    cout << "\nПряма: y = " << l.calculate(x) << endl;
 
    cout << "Еліпс: y = " << e.calculate(x) << endl;  
    cout << "Гіпербола: y = " << h.calculate(x) << endl;
}