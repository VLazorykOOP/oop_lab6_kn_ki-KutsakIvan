#include <iostream>

using namespace std;

class Base
{
protected:
	int dat;
	// double A[5] = { 1,1,1,1,1 };
public:
	Base() : dat(1) {}
	Base(int d) : dat(d) {}
};

class D1 : protected Base
{
protected:
	int d1;
public:
	D1() : d1(1) {}
	D1(int d) : d1(d) {}
	D1(int d, int dt) : Base(dt), d1(d) {}
};

class D2 : protected Base
{
protected:
	double d2;
public:
	D2() : d2(1) {}
	D2(int d) : d2(d) {}
	D2(int d, double dt) : Base(d), d2(dt) {}
};

class D12 : protected D1, protected D2
{
protected:
	double dt;
public:
	D12() : dt(1) {}
	D12(int d) : dt(d) {}
	D12(int a, int b, int c, double d, int e) : D1(a, b), D2(c, d), dt(e) {}
};

class R : protected D12, protected D1, protected D2
{
protected:
	double dt;
public:
	R() : dt(1) {}
	R(int d) : dt(d) {}
	R(int a, int b, int c, double d, int e, int f, int g, int h, double i, int j) : D12(a, b, c, d, e), D1(f, g), D2(h, i), dt(j +
		1.) {}
	void showDat()
	{
		std::cout << "dat =? Error C2385 ambiguous access level dat " << std::endl;
		/// << dat << std::endl;
		std::cout << "B12VV::D1V::Base::dat = " << D12::D1::Base::dat << std::endl;
		std::cout << "B12VV::D1V::Base::dat = " << Base::dat << std::endl;
		std::cout << "B12VV::D1V::Base::dat = " << D12::D2::Base::dat << std::endl;
	}
};

// virtual 
//
class D1V : virtual protected Base
{
protected:
	int d1;
public:
	D1V() : d1(1) {}
	D1V(int d) : d1(d) {}
	D1V(int d, int dt) : Base(dt), d1(d) {}
};
class D2V : virtual protected Base
{
protected:
	double d2;
public:
	D2V() : d2(1) {}
	D2V(int d) : d2(d) {}
	D2V(int d, double dt) : Base(d), d2(dt) {}
};
class D12V : virtual protected D1V, virtual public D2V
{
protected:
	double dt;
public:
	D12V() : dt(1) {}
	D12V(int d) : dt(d) {}
	D12V(int a, int b, int c, double d, int e) : D1V(a, b), D2V(c, d), dt(e) {}
};
class RV : virtual protected D12V, virtual protected D1V, virtual protected D2V {
protected:
	double dt;
public:
	RV() : dt(1) {}
	RV(int d) : dt(d) {}
	RV(int a, int b, int c, double d, int e, int f, int g, int h, double i, int j) : D12V(a, b, c, d, e), D1V(f, g), D2V(h, i), dt(j +
		1.) {}
	void showDat()
	{
		std::cout << " dat = " << dat << std::endl;
		std::cout << "B12VV::D1V::Base::dat = " << D12V::D1V::Base::dat << std::endl;
		std::cout << "B12VV::D1V::Base::dat = " << Base::dat << std::endl;
		std::cout << "B12VV::D1V::Base::dat = " << D12V::D2V::Base::dat << std::endl;
	}
};
int main()
{
	R a, b(1, 2, 3, 4.5, 5, 6, 7, 8, 9.5, 10);
	RV av, bv(1, 2, 3, 4.5, 5, 6, 7, 8, 9.5, 10);
	std::cout << "Test !\n";
	std::cout << "Size for Base " << sizeof(Base) << std::endl;
	std::cout << "Size for D1 " << sizeof(D1) << std::endl;
	std::cout << "Size for D2 " << sizeof(D2) << std::endl;
	std::cout << "Size for D12 " << sizeof(D12) << std::endl;
	std::cout << "Size for R " << sizeof(R) << std::endl;
	std::cout << "Size for Base " << sizeof(Base) << std::endl;
	std::cout << "Size for D1V " << sizeof(D1V) << std::endl;
	std::cout << "Size for D2V " << sizeof(D2V) << std::endl;
	std::cout << "Size for D12V " << sizeof(D12V) << std::endl;
	std::cout << "Size for RV " << sizeof(RV) << std::endl;
	std::cout << "Size for object class R " << sizeof(R) << " or "
		<< sizeof(a) << " or " << sizeof(b) << std::endl;
	std::cout << "Size for object class RV3 " << sizeof(RV) << " or "
		<< sizeof(av) << " or " << sizeof(bv) << std::endl;
	b.showDat();
	bv.showDat();
}

