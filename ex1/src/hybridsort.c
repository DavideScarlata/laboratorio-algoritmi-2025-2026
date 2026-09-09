#include "../include/hybridsort.h"
#include <stdlib.h>
#include <string.h>


void swap(void *a, void *b, size_t size) {
  unsigned char *pa = (unsigned char *)a;
  unsigned char *pb = (unsigned char *)b;

  for (size_t i = 0; i < size; i++) {
    unsigned char tmp = pa[i];
    pa[i] = pb[i];
    pb[i] = tmp;
  }
}void hybrid_sort(void *base, size_t nitems, size_t size, size_t k,
                 int (*compar)(const void *, const void *)) {

  if (nitems < 2 || !base || !compar || size == 0) {
    return;
  }
  if (nitems < k) {
    selection_sort(base, nitems, size, compar);
    return;
  }
  char *array = (char *)base;
  
  size_t first = 0;
  size_t middle = (nitems - 1) / 2;
  size_t last = nitems - 1;
  
  char *p_first = array + first * size;
  char *p_middle = array + middle * size;
  char *p_last = array + last * size;

  if (compar(p_first, p_middle) > 0) {
    swap(p_first, p_middle, size);
  }
  if (compar(p_middle, p_last) > 0) {
    swap(p_middle, p_last, size);
    if (compar(p_first, p_middle) > 0) {
      swap(p_first, p_middle, size);
    }
  }
  swap(p_middle, p_last, size);
  char *pivot = array + (nitems - 1) * size;
  size_t lt = 0; 
  size_t i = 0; 
  size_t gt = nitems - 1; 

  while (i < gt) {
    int cmp = compar(array + i * size, pivot);

    if (cmp < 0) {
      swap(array + i * size, array + lt * size, size);
      i++;
      lt++;
    } else if (cmp == 0) {
      i++;
    } else { 
      gt--;
      swap(array + i * size, array + gt * size, size);
    }
  }
  swap(array + gt * size, array + (nitems - 1) * size, size);

  if (lt > 0) {
    hybrid_sort(base, lt, size, k, compar);
  }
  
  size_t gt_start_index = gt + 1;
  size_t gt_size = (nitems > gt_start_index) ? (nitems - gt_start_index) : 0;
  
  if (gt_size > 0) {
    hybrid_sort(array + gt_start_index * size, gt_size, size, k, compar);
  }
}

void selection_sort(void *base, size_t nitems, size_t size,
                    int (*compar)(const void *, const void *)) {

  if (nitems < 2 || !base || !compar || size == 0)
    return;

  unsigned char *array = (unsigned char *)base;

  for (size_t start = 0; start < nitems - 1; start++) {
    size_t min = start;

    for (size_t j = start + 1; j < nitems; j++) {
      unsigned char *min_elem = &array[min * size];
      unsigned char *current_elem = &array[j * size];

      if (compar(current_elem, min_elem) < 0) {
        min = j;
      }
    }

    if (min != start) {
      swap(&array[start * size], &array[min * size], size);
    }
  }
}