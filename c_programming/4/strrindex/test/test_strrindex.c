#include "vendor/unity.h"
#include "../src/strrindex.h"


void setUp(void)
{
}

void tearDown(void)
{
}


static void test_empty_src(void) {
    int res = strrindex("", "test");
    TEST_ASSERT_EQUAL(-1, res);
}


static void test_single_match(void) {
    TEST_ASSERT_EQUAL(0, strrindex("foo", "foo"));
}


static void test_match_in_the_middle(void) {
    TEST_ASSERT_EQUAL(4, strrindex("spamfoos", "foo"));
}


static void test_two_matches(void) {
    TEST_ASSERT_EQUAL(3, strrindex("foofoo", "foo"));
}


static void test_many_matches(void) {
    TEST_ASSERT_EQUAL(15, strrindex("foofoofoofoofoofoo", "foo"));
}


static void test_match_one_letter(void) {
    TEST_ASSERT_EQUAL(6, strrindex("fffffff", "f"));
}


static void test_no_match(void) {
    TEST_ASSERT_EQUAL(-1, strrindex("abcd", "e"));
}


int main(void)
{
   UnityBegin("test/test_strrindex.c");

   RUN_TEST(test_empty_src);
   RUN_TEST(test_single_match);
   RUN_TEST(test_match_in_the_middle);
   RUN_TEST(test_two_matches);
   RUN_TEST(test_many_matches);
   RUN_TEST(test_match_one_letter);
   RUN_TEST(test_no_match);

   return UnityEnd();
}
