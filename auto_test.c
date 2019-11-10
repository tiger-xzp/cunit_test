#include <stdio.h>
#include <string.h>
#include "CUnit/Automated.h"

extern void test_maxi(void);
extern void test_mini(void);

int init_max_suite(void) {
	return 0;
}

int clean_max_suite(void) {
	return 0;
}

int init_min_suite(void) {
	return 0;
}

int clean_min_suite(void) {
	return 0;
}

int main()
{
	CU_pSuite pMaxSuite = NULL;
	CU_pSuite pMinSuite = NULL;

	//initalize and registry
	if(CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	//add suite
	pMaxSuite = CU_add_suite("TEST_MAX",init_max_suite,clean_max_suite);
	pMinSuite = CU_add_suite("TEST_MIN",init_min_suite,clean_min_suite);
	if (pMaxSuite == NULL || pMinSuite == NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//add test
	if((NULL == CU_add_test(pMaxSuite,"test of maxi()",test_maxi)) ||
		(NULL == CU_add_test(pMinSuite,"test of mini()",test_mini))) {
		CU_cleanup_registry();
	return CU_get_error();
	}

	//run all tests
	CU_automated_run_tests();
	CU_list_tests_to_file();
	CU_cleanup_registry();
	return CUE_SUCCESS;
}