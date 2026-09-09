#include "../include/hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int string_cmp(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

unsigned long string_hash(const void *k) {
    unsigned long hash = 5381;
    int c;
    const unsigned char *str = (const unsigned char *)k;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + (unsigned long)c; 
    return hash;
}
void test_basic_ops() {
    printf("Running test_basic_ops...\n");
    HashTable *ht = hash_table_create(string_cmp, string_hash);
    assert(ht != NULL);
    assert(hash_table_size(ht) == 0);
    char *k1 = "hello";
    char *v1 = "world";
    hash_table_put(ht, k1, v1);
    
    assert(hash_table_size(ht) == 1);
    assert(hash_table_contains_key(ht, "hello") == 1);
    assert(strcmp((char*)hash_table_get(ht, "hello"), "world") == 0);

    char *v2 = "everyone";
    hash_table_put(ht, k1, v2);
    assert(hash_table_size(ht) == 1);
    assert(strcmp((char*)hash_table_get(ht, "hello"), "everyone") == 0);

    hash_table_remove(ht, "hello");
    assert(hash_table_size(ht) == 0);
    assert(hash_table_contains_key(ht, "hello") == 0);
    assert(hash_table_get(ht, "hello") == NULL);

    hash_table_free(ht);
    printf("test_basic_ops passed.\n");
}

void test_resize_and_collision() {
    printf("Running test_resize_and_collision...\n");
    HashTable *ht = hash_table_create(string_cmp, string_hash);

    int num_items = 100;
    char keys[100][20];
    int values[100];

    for(int i = 0; i < num_items; i++) {
        sprintf(keys[i], "key_%d", i);
        values[i] = i;
        hash_table_put(ht, keys[i], &values[i]);
    }

    assert(hash_table_size(ht) == (size_t)num_items);

    for(int i = 0; i < num_items; i++) {
        int *val = (int*)hash_table_get(ht, keys[i]);
        assert(val != NULL);
        assert(*val == i);
    }

    hash_table_free(ht);
    printf("test_resize_and_collision passed.\n");
}
void test_keyset() {
    printf("Running test_keyset...\n");
    HashTable *ht = hash_table_create(string_cmp, string_hash);
    
    hash_table_put(ht, "k1", "v1");
    hash_table_put(ht, "k2", "v2");
    hash_table_put(ht, "k3", "v3");

    void **keys = hash_table_keyset(ht);
    assert(keys != NULL);

    int count = 0;
    for(int i = 0; keys[i] != NULL; i++) {
        count++;
        char *k = (char*)keys[i];
        assert(strcmp(k, "k1") == 0 || strcmp(k, "k2") == 0 || strcmp(k, "k3") == 0);
    }
    assert(count == 3);

    free(keys); 
    hash_table_free(ht);
    printf("test_keyset passed.\n");
}

int main() {
    test_basic_ops();
    test_resize_and_collision();
    test_keyset();
    
    printf("\nAll tests passed successfully!\n");
    return 0;
}