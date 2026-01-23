#include "Base.hpp"

Base::~Base() {}

Base *generate(void)
{
	std::srand(std::time(0));

	int r = rand() % 3;
	if (r)
		return (new A);
	else if (r == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cout << "IDKKK\n";
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "'A'\n";
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "'B'\n";
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "'C'\n";
		return ;
	}
	catch(const std::exception& e) {}
	std::cout << "IDKKKK\n";
}