#pragma once
#include "records.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief sorts all records from an input file and writes the (sorted) into an
 * out file
 * @param infile the input file containing the records to sort
 * @param outfile the output file where sorted records will be written
 * @param field the parameter which the records are sorted
 * @param k numbers of elements that decide when to switch from quick sort to
 * selection sort
 */
void sort_records(FILE *infile, FILE *outfile, size_t field, size_t k);
int cmp_id(const void *a, const void *b);
int cmp_field1(const void *a, const void *b);
int cmp_field2(const void *a, const void *b);
int cmp_field3(const void *a, const void *b);
