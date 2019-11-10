#include "CUnit/CUnit.h"

int maxi(int i1, int i2)
{
  return (i1 > i2) ? i1 : i2;
}

int mini(int i1, int i2)
{
  return (i1 < i2) ? i1 : i2;
}

void test_maxi(void)
{
  CU_ASSERT(maxi(0,2) == 2);
  CU_ASSERT(maxi(0,-2) == 0);
  CU_ASSERT(maxi(2,2) == 2);
}

void test_mini(void) {
  CU_ASSERT(mini(3,6) == 3);
  CU_ASSERT(mini(0,-2) == -2);
  CU_ASSERT(mini(6,6) == 6);
}