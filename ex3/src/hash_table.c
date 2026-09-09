#include "../include/hash_table.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Entry {
  void *key;
  void *value;
  struct Entry *next;
} Entry;

struct HashTable {
  Entry **buckets;
  size_t capacity;
  int (*cmp)(const void *, const void *);
  unsigned long (*hash)(const void *);
  int size;
};

static const size_t prime_sizes[] = {
    53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593,
    49157, 98317, 196613, 393241, 786433, 1572869, 3145739,
    6291469, 12582917, 25165843, 50331653, 100663319,
    201326611, 402653189, 805306457, 1610612741
};
static const int num_primes = sizeof(prime_sizes) / sizeof(prime_sizes[0]);

static size_t next_prime_capacity(size_t current_cap) {
    for (int i = 0; i < num_primes; i++) {
        if (prime_sizes[i] > current_cap) {
            return prime_sizes[i];
        }
    }
    return current_cap * 2 + 1;
}

static void hash_table_resize(HashTable *ht, size_t new_capacity) {
    if (new_capacity <= ht->capacity) return;
    Entry **new_buckets = calloc(new_capacity, sizeof(Entry *));
    if (!new_buckets) return;
    for (size_t i = 0; i < ht->capacity; i++) {
        Entry *curr = ht->buckets[i];
        while (curr) {
            Entry *next = curr->next;
            unsigned long h = ht->hash(curr->key);
            size_t idx = h % new_capacity;

            curr->next = new_buckets[idx];
            new_buckets[idx] = curr;

            curr = next;
        }
    }
    free(ht->buckets);
    ht->buckets = new_buckets;
    ht->capacity = new_capacity;
}

HashTable *hash_table_create(int (*cmp)(const void *, const void *),
                             unsigned long (*hash)(const void *)) {
  if (!cmp || !hash)
    return NULL;

  HashTable *ht = malloc(sizeof(HashTable));
  if (!ht)
    return NULL;

  ht->capacity = prime_sizes[0];
  ht->buckets = calloc(ht->capacity, sizeof(Entry *));
  if (!ht->buckets) {
    free(ht);
    return NULL;
  }

  ht->cmp = cmp;
  ht->hash = hash;
  ht->size = 0;

  return ht;
}

void hash_table_put(HashTable *ht, const void *key, const void *value) {
  if (!ht || !key)
    return;
    
  if ((size_t)ht->size >= (ht->capacity / 4) * 3){
      hash_table_resize(ht, next_prime_capacity(ht->capacity));
  }
  unsigned long h = ht->hash(key);
  size_t idx = h % ht->capacity;
  Entry *curr = ht->buckets[idx];
  while (curr) {
    if (ht->cmp(key, curr->key) == 0) {
      curr->value = (void *)value;
      return;
    }
    curr = curr->next;
  }

  Entry *e = malloc(sizeof(Entry));
  if (!e)
    return;

  e->key = (void *)key;
  e->value = (void *)value;
  e->next = ht->buckets[idx];
  ht->buckets[idx] = e;
  ht->size++;
}

void *hash_table_get(const HashTable *ht, const void *key) {
  if (!ht || !key)
    return NULL;

  unsigned long h = ht->hash(key);
  size_t idx = h % ht->capacity;

  Entry *curr = ht->buckets[idx];
  while (curr) {
    if (ht->cmp(key, curr->key) == 0)
      return curr->value;
    curr = curr->next;
  }
  return NULL;
}

int hash_table_contains_key(const HashTable *ht, const void *key) {
  return hash_table_get(ht, key) != NULL;
}

void hash_table_remove(HashTable *ht, const void *key) {
  if (!ht || !key)
    return;

  unsigned long h = ht->hash(key);
  size_t idx = h % ht->capacity;

  Entry *curr = ht->buckets[idx];
  Entry *prev = NULL;

  while (curr) {
    if (ht->cmp(key, curr->key) == 0) {
      if (prev)
        prev->next = curr->next;
      else
        ht->buckets[idx] = curr->next;

      free(curr);
      ht->size--;
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}

int hash_table_size(const HashTable *ht) {
  if (!ht)
    return 0;
  return (size_t)ht->size;
}

void **hash_table_keyset(const HashTable *ht) {
  if (!ht)
    return NULL;

  size_t n = (size_t)ht->size;
  void **arr = malloc((n + 1) * sizeof(void *));
  if (!arr)
    return NULL;

  int pos = 0;
  for (size_t i = 0; i < ht->capacity; i++) {
    Entry *curr = ht->buckets[i];
    while (curr) {
      arr[pos++] = curr->key;
      curr = curr->next;
    }
  }
  arr[pos] = NULL;

  return arr;
}

void hash_table_free(HashTable *ht) {
  if (!ht)
    return;

  for (size_t i = 0; i < ht->capacity; i++) {
    Entry *curr = ht->buckets[i];
    while (curr) {
      Entry *next = curr->next;
      free(curr);
      curr = next;
    }
  }

  free(ht->buckets);
  free(ht);
}
