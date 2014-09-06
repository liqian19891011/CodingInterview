#include <assert.h>
#include "TestClass.h"

void TestClass::TestUpdateBits()
{
	Bit bit;
	int result = bit.UpdateBit(2048, 21, 2, 6);
	assert(result == 2132);
}

void TestClass::TestDecimalToBinary()
{
	Bit bit;
	bit.DecimalToBinary("32.72");
}

void TestClass::TestBitDistance()
{
	Bit bit;
	assert( 2 == bit.BitDistance(31, 14));
}

void TestClass::TestSwapBits()
{
	Bit bit;
	bit.SwapBits(14);
}