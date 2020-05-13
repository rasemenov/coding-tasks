#include "vendor/unity.h"
#include "../solution.h"

void setUp(void)
{
}

void tearDown(void)
{
}


static void test_second_larger_1(void)
{
    int expected[] = {1, 2};
    int actual[] = {1, 0};
    int nums2[] = {2};
    merge(actual, 2, 1, nums2, 1, 1);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));
}


static void test_second_larger_2(void)
{
    int expected[] = {1, 2, 3, 4};
    int actual[] = {1, 2, 0, 0};
    int nums2[] = {3, 4};
    merge(actual, 4, 2, nums2, 2, 2);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));
}

static void test_second_larger_3(void)
{
    int expected[] = {1, 2, 3, 4, 5, 6};
    int actual[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {4, 5, 6};
    merge(actual, 6, 3, nums2, 3, 3);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));
}


static void test_first_larger_1(void)
{
    int expected[] = {1, 2};
    int actual[] = {2, 0};
    int nums2[] = {1};
    merge(actual, 2, 1, nums2, 1, 1);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));
}


static void test_first_larger_2(void)
{
    int expected[] = {1, 2, 3, 4};
    int actual[] = {3, 4, 0, 0};
    int nums2[] = {1, 2};
    merge(actual, 4, 2, nums2, 2, 2);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));
}


static void test_first_larger_3(void)
{
    int expected[] = {1, 2, 3, 4, 5, 6};
    int actual[] = {4, 5, 6, 0, 0, 0};
    int nums2[] = {1, 2, 3};
    merge(actual, 6, 3, nums2, 3, 3);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));
}


static void test_single_element(void)
{
    int expected[] = {1};
    int actual[] = {0};
    int nums2[] = {1};
    merge(actual, 1, 0, nums2, 1, 1);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));
}

int main(void)
{
   UnityBegin("test/test_merge.c");

   RUN_TEST(test_first_larger_1);
   RUN_TEST(test_first_larger_2);
   RUN_TEST(test_first_larger_3);
   RUN_TEST(test_second_larger_1);
   RUN_TEST(test_second_larger_2);
   RUN_TEST(test_second_larger_3);
   RUN_TEST(test_single_element);

   return UnityEnd();
}
