#include "stdafx.h"
#include "testBoost.h"
#include "boost/thread.hpp"

bool TEST_BOOST::testBoost() {
	boost::function<void()> func([](){std::cout << "my thread!" << std::endl; });
	boost::thread thread(func);
	thread.join();
	std::cout << "my thread is over!" << std::endl;
	return true;
}
