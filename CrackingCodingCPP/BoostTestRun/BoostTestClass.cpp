#include "BoostTestClass.h"
#include<boost\test\unit_test.hpp>
#include "Hard.h"

void BoostTestClass::TestAddWithoutPlus()
{
	Hard h;
	//BOOST_CHECK_EQUAL(h.addWithoutPlus(1,2), 3);
}