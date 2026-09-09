#pragma once

#include <stddef.h>
#include "hash_table.h"

/**
 * @brief Opaque structure representing a priority queue implemented
 *        as a ternary max-heap.
 */
typedef struct PriorityQueue PriorityQueue;

/**
 * @brief Create a new empty priority queue.
 *
 *
 * @param compare function used to compare two elements.
 *        It must return:
 *        - >0 if first element has higher priority
 *        - 0 if equal priority
 *        - <0 if lower priority
 * @param hash function mapping an element to an unsigned long,
 *        used internally for fast lookup (contains/remove).
 * @return pointer to a new PriorityQueue, or NULL on failure
 */
PriorityQueue *priority_queue_create(
    int (*compare)(const void *, const void *),
    unsigned long (*hash)(const void *)
);

/**
 * @brief Insert a new element into the priority queue.
 *
 * @param pq pointer to the priority queue
 * @param element pointer to the element to insert
 * @return 0 on success, -1 on invalid arguments or allocation failure
 */
int priority_queue_push(PriorityQueue *pq, void *element);

/**
 * @brief Check whether an element is contained in the queue.
 *
 * @param pq pointer to the priority queue
 * @param element pointer to the element to search for
 * @return 1 if present, 0 if not present or invalid arguments
 */
int priority_queue_contains(const PriorityQueue *pq, const void *element);

/**
 * @brief Return the element with maximum priority without removing it.
 *
 * @param pq pointer to the priority queue
 * @return pointer to the top element, or NULL if queue is empty or invalid
 */
void *priority_queue_top(const PriorityQueue *pq);

/**
 * @brief Remove the element with maximum priority from the queue.
 *
 * @param pq pointer to the priority queue
 */
void priority_queue_pop(PriorityQueue *pq);

/**
 * @brief Remove a specific element from the priority queue.
 *
 * @param pq pointer to the priority queue
 * @param element pointer to the element to remove
 * @return 1 if the element was removed, 0 if not found or invalid arguments
 */
int priority_queue_remove(PriorityQueue *pq, const void *element);

/**
 * @brief Return the number of elements currently stored in the queue.
 *
 * @param pq pointer to the priority queue
 * @return number of elements, or -1 if pq is NULL
 */
int priority_queue_size(const PriorityQueue *pq);

/**
 * @brief Free the priority queue and its internal structures.
 *
 * @param pq pointer to the priority queue
 */
void priority_queue_free(PriorityQueue *pq);