
#include "utils.h"

static int randomNumberGenerator(int min, int max) {
	static bool firstCall = true;
	if (firstCall) {
		std::srand(static_cast<unsigned int>(std::time(0)));
		firstCall = false;
	}
	return std::rand() % (max - min + 1) + min;
}

Base * generate(void) {
	int n = randomNumberGenerator(0, 2);
	if (n == 0) {
		return new A();
	} else if (n == 1) {
		return new B();
	} else {
		return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Type A" << std::endl;
	else if(dynamic_cast<B *>(p))
		std::cout << "Type B" << std::endl;
	else if(dynamic_cast<C *>(p))
		std::cout << "Type C" << std::endl;
	else
		std::cout << "Undefined Type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Type A" << std::endl;
	}
	catch (std::exception &e) { }

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Type B" << std::endl;
	}
	catch (std::exception &e) { }

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Type C" << std::endl;
	}
	catch (std::exception &e) { }
}