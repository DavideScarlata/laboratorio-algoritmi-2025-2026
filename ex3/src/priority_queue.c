#include "../include/priority_queue.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 16
#define HEAP_CHILDREN 3

struct PriorityQueue {
    void **data;
    size_t size;
    size_t capacity;
    int (*compare)(const void *, const void *);
    unsigned long (*hash)(const void *);
    HashTable *map;
};

static void swap(PriorityQueue *pq, size_t i, size_t j) {
    void *tmp = pq->data[i];
    pq->data[i] = pq->data[j];
    pq->data[j] = tmp;

    hash_table_put(pq->map, pq->data[i], (void *)(size_t)(i + 1));
    hash_table_put(pq->map, pq->data[j], (void *)(size_t)(j + 1));
}

static void heapify_up(PriorityQueue *pq, size_t idx) {
    if (idx == 0) {
        return;
    }
    size_t parent = (idx - 1) / HEAP_CHILDREN;

    if (pq->compare(pq->data[idx], pq->data[parent]) <= 0) {
        return;
    }
    
    swap(pq, idx, parent);
    heapify_up(pq, parent);
}

static void heapify_down(PriorityQueue *pq, size_t idx) {
    size_t largest = idx;

    for (size_t i = 1; i <= HEAP_CHILDREN; i++) {
        size_t child = HEAP_CHILDREN * idx + i;
        if (child < pq->size && pq->compare(pq->data[child], pq->data[largest]) > 0) {
            largest = child;
        }
    }

    if (largest != idx) {
        swap(pq, idx, largest);
        heapify_down(pq, largest);
    }
}

static int ensure_capacity(PriorityQueue *pq) {
    if (pq->size < pq->capacity) {
        return 0;
    }

    size_t new_cap = pq->capacity * 2;
    void **new_data = realloc(pq->data, new_cap * sizeof(void *));
    if (!new_data) {
        return -1;
    }

    pq->data = new_data;
    pq->capacity = new_cap;
    return 0;
}

PriorityQueue *priority_queue_create(int (*compare)(const void *, const void *),
                                     unsigned long (*hash)(const void *)) {
    if (!compare || !hash) {
        return NULL;
    }

    PriorityQueue *pq = malloc(sizeof(PriorityQueue));
    if (!pq) {
        return NULL;
    }

    pq->data = malloc(INITIAL_CAPACITY * sizeof(void *));
    if (!pq->data) { 
        free(pq); return NULL; 
    }

    pq->size = 0;
    pq->capacity = INITIAL_CAPACITY;
    pq->compare = compare;
    pq->hash = hash;
    pq->map = hash_table_create(compare, hash);
    if (!pq->map) { 
        free(pq->data); free(pq); return NULL; 
    }

    return pq;
}

int priority_queue_push(PriorityQueue *pq, void *element) {
    if (!pq || !element) {
        return -1;
    }

    if (hash_table_contains_key(pq->map, element)) {
        return 0;
    }

    if (ensure_capacity(pq) != 0) {
        return -1;
    }

    size_t idx = pq->size;
    pq->data[idx] = element;
    pq->size++;

    hash_table_put(pq->map, element, (void *)(size_t)(idx + 1));
    heapify_up(pq, idx);

    return 1;
}

int priority_queue_contains(const PriorityQueue *pq, const void *element) {
    if (!pq || !element) {
        return 0;
    }
    return hash_table_contains_key(pq->map, element);
}

void *priority_queue_top(const PriorityQueue *pq) {
    if (pq->size == 0) {
        return NULL;
    }

    return pq->data[0];
}

void priority_queue_pop(PriorityQueue *pq) {
    if (!pq || pq->size == 0) {
        return;
    }
    swap(pq, 0, pq->size - 1);
    hash_table_remove(pq->map, pq->data[pq->size - 1]);
    pq->size--;
    if (pq->size > 0) {
        heapify_down(pq, 0);
    }
}

int priority_queue_remove(PriorityQueue *pq, const void *element) {
    if (!pq || !element) {
        return -1;
    }

    void *val = hash_table_get(pq->map, element);
    if (!val) {
        return 0;
    }
    
    size_t idx = (size_t)(size_t)val - 1;

    size_t last = pq->size - 1;

    void *toBeRemoved = pq->data[idx];
    swap(pq, idx, last);
    hash_table_remove(pq->map, toBeRemoved);

    pq->size--;

    if (idx != pq->size - 1) {
        size_t parent = (idx - 1) / HEAP_CHILDREN;
        if (idx > 0 && pq->compare(pq->data[idx], pq->data[parent]) > 0) {
            heapify_up(pq, idx);
        } else {
            heapify_down(pq, idx);
        }
    }
    return 1;
}

int priority_queue_size(const PriorityQueue *pq) {
    if (!pq) {
        return -1;
    }

    return (int)pq->size;
}

void priority_queue_free(PriorityQueue *pq) {
    if (!pq) {
        return;
    }

    free(pq->data);
    hash_table_free(pq->map);
    free(pq);
}