#pragma once
#include <stddef.h>

typedef struct HashTable HashTable;

/**
 * @brief Create a new hash table.
 *
 * The user must provide:
 * - a comparison function to determine whether two keys are equal;
 *   it must return 0 when the two keys are equal (strcmp-like behavior).
 * - a hash function mapping a key to an unsigned long.
 *
 * @param cmp comparison function for keys
 * @param hash hash function for keys
 * @return a pointer to a new HashTable, or NULL on allocation failure
 */
HashTable *hash_table_create(int (*cmp)(const void *, const void *),
                             unsigned long (*hash)(const void *));

/**
 * @brief Insert or update a key-value pair.
 *
 * If the key already exists in the table, its associated value is updated.
 * The table does not copy keys or values.
 *
 * @param ht pointer to the hash table
 * @param key pointer to the key
 * @param value pointer to the value
 */
void hash_table_put(HashTable *ht, const void *key, const void *value);

/**
 * @brief Retrieve the value associated with a key.
 *
 * @param ht pointer to the hash table
 * @param key pointer to the key
 * @return pointer to the associated value, or NULL if the key is not found
 */
void *hash_table_get(const HashTable *ht, const void *key);

/**
 * @brief Check whether a key is present in the table.
 *
 * @param ht pointer to the hash table
 * @param key pointer to the key
 * @return 1 if the key exists, 0 otherwise
 */
int hash_table_contains_key(const HashTable *ht, const void *key);

/**
 * @brief Remove a key-value pair from the table.
 *
 * The key and value are not freed; only the internal entry structure is freed.
 *
 * @param ht pointer to the hash table
 * @param key pointer to the key to remove
 */
void hash_table_remove(HashTable *ht, const void *key);

/**
 * @brief Get the number of key-value pairs in the table.
 *
 * @param ht pointer to the hash table
 * @return number of stored entries
 */
 int hash_table_size(const HashTable *ht);

/**
 * @brief Return a dynamically allocated NULL-terminated array of keys.
 *
 * The returned array must be freed by the caller.
 * Keys themselves are not duplicated and must not be freed unless they
 * were dynamically allocated by the user.
 *
 * @param ht pointer to the hash table
 * @return array of key pointers, or NULL on allocation error
 */
void **hash_table_keyset(const HashTable *ht);

/**
 * @brief Free the hash table and its internal structures.
 *
 * Does NOT free keys or values: users retain ownership.
 *
 * @param ht pointer to the hash table
 */
void hash_table_free(HashTable *ht);
