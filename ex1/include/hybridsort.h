#pragma once
#include <stdlib.h>
#include <string.h>

/**
 * @brief hybrid sorting system that combine quickSort and selectionSort
 * @param base pointer ot the first element of the array that needs to be sorted
 * @param nitems number of elements in the array
 * @param size size in bytes of each element
 * @param k numbers of elements that decide when to switch from quick sort to
 * selection sort
 * @param compar pointer to a comparison function
 */

void hybrid_sort(void *base, size_t nitems, size_t size, size_t k,
                 int (*compar)(const void *, const void *));

/**
 * @brief performs selectionSort on a array
 * @brief hybrid sorting system that combine quickSort and selectionSort
 * @param base pointer ot the first element of the array that needs to be sorted
 * @param nitems number of elements in the array
 * @param size size in bytes of each element
 * @param compar pointer to a comparison function
 */
void selection_sort(void *base, size_t nitems, size_t size,
                    int (*compar)(const void *, const void *));
