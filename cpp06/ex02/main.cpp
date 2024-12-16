#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Error.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void) {
	std::srand(time(NULL));
	int random = (std::rand() % 3) + 1;
	switch (random) {
		case 1:
			return (new A());
		case 2:
			return (new B());
		case 3:
			return (new C());
	};
	return (NULL);
};

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "it's me, A!" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Helloooo, I'm B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Just C, ok?" << std::endl;
	else
		throw ErrorNULL();
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "it's me, A!" << std::endl;
	} catch (std::exception &e) {
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "Helloooo, I'm B" << std::endl;
		} catch (std::exception &e) {
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "Just C, ok?" << std::endl;
			} catch (std::exception &e) {
				throw Error();
			}
		}
	}
}

int main(void)
{
	Base *base = generate();
	try
	{
		identify(*base);
		identify(base);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete base;
	return 0;
}