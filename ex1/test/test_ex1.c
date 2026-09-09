#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include "unity.h"
#include "hybridsort.h"
#include "records.h"
#include "sort_records.h"

int compare_ints(const void *a, const void *b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return (ia > ib) - (ia < ib);
}
Record create_rec(uint64_t id, float f1, int64_t f2, const char* f3) {
    Record r;
    r.id = id;
    r.field1 = f1;
    r.field2 = f2;
    memset(r.field3, 0, 16); 
    if (f3) {
        strncpy(r.field3, f3, 15);
        r.field3[15] = '\0'; 
    }
    return r;
}

void setUp(void) {}
void tearDown(void) {}


void test_hybrid_sort_integers_random(void) {
    int arr[] = {10, 5, 2, 3, 7, 8, 1, 9, 4, 6};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    hybrid_sort(arr, 10, sizeof(int), 4, compare_ints);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 10);
}

void test_hybrid_sort_integers_sorted(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int expected[] = {1, 2, 3, 4, 5};
    hybrid_sort(arr, 5, sizeof(int), 0, compare_ints);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 5);
}

void test_hybrid_sort_integers_reverse(void) {
    int arr[] = {5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5};
    hybrid_sort(arr, 5, sizeof(int), 2, compare_ints);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 5);
}

void test_hybrid_sort_duplicates(void) {
    int arr[] = {3, 1, 2, 3, 1};
    int expected[] = {1, 1, 2, 3, 3};
    hybrid_sort(arr, 5, sizeof(int), 2, compare_ints);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 5);
}

void test_hybrid_sort_empty_or_null(void) {
    int *arr = NULL;
    hybrid_sort(arr, 0, sizeof(int), 0, compare_ints);
    TEST_PASS();
}
void test_sort_records_by_id(void) {
    Record arr[3];
    arr[0] = create_rec(100, 1.0, 1, "C");
    arr[1] = create_rec(50, 2.0, 2, "B");
    arr[2] = create_rec(150, 3.0, 3, "A");
    hybrid_sort(arr, 3, sizeof(Record), 0, cmp_id);

    TEST_ASSERT_EQUAL_UINT64(50, arr[0].id);
    TEST_ASSERT_EQUAL_UINT64(100, arr[1].id);
    TEST_ASSERT_EQUAL_UINT64(150, arr[2].id);
}

void test_sort_records_by_field1_float(void) {
    Record arr[3];
    arr[0] = create_rec(1, 10.5f, 1, "C");
    arr[1] = create_rec(2, 2.2f, 2, "B");
    arr[2] = create_rec(3, 99.9f, 3, "A");

    hybrid_sort(arr, 3, sizeof(Record), 0, cmp_field1);

    TEST_ASSERT_FLOAT_WITHIN(0.001f, 2.2f, arr[0].field1);
    TEST_ASSERT_FLOAT_WITHIN(0.001f, 10.5f, arr[1].field1);
    TEST_ASSERT_FLOAT_WITHIN(0.001f, 99.9f, arr[2].field1);
}

void test_sort_records_by_field2_int64(void) {
    Record arr[3];
    arr[0] = create_rec(1, 1.0, 500, "C");
    arr[1] = create_rec(2, 1.0, -10, "B");
    arr[2] = create_rec(3, 1.0, 100, "A");

    hybrid_sort(arr, 3, sizeof(Record), 0, cmp_field2);

    TEST_ASSERT_EQUAL_INT64(-10, arr[0].field2);
    TEST_ASSERT_EQUAL_INT64(100, arr[1].field2);
    TEST_ASSERT_EQUAL_INT64(500, arr[2].field2);
}
int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(test_hybrid_sort_integers_random);
    RUN_TEST(test_hybrid_sort_integers_sorted);
    RUN_TEST(test_hybrid_sort_integers_reverse);
    RUN_TEST(test_hybrid_sort_duplicates);
    RUN_TEST(test_hybrid_sort_empty_or_null);
    
    RUN_TEST(test_sort_records_by_id);
    RUN_TEST(test_sort_records_by_field1_float);
    RUN_TEST(test_sort_records_by_field2_int64);
    
    return UNITY_END();
}