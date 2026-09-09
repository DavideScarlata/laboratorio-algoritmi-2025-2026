#pragma once
#include <stdint.h>
#include <stdio.h>

/**
 * @brief the struct of a single record
 *
 * bytes 0-7: id
 * bytes 8-11: filed1
 * bytes 12-19: field2
 * bytes 20-36: filed3
 */
typedef struct {
  uint64_t id;
  float field1;
  int64_t field2;
  char field3[16];
} Record;

/**
 * @brief read a record from a given file
 * @param file the file from which to read the record
 * @param record pointer to the record struct where to save the data
 * @return 0 in case of error or and of a file, 1 in case of success
 */
int read_record(FILE *file, Record *record);

/**
 * @brief write a record into the file
 * @param file the output file where to write the record
 * @param record pointer to the record that needs to be written
 * @return 0 in case of error, 1 in case of success
 */
int write_record(FILE *file, const Record *record);

/**
 * @brief loads records from given file into an allocated array
 * @param file the file from which to read the records
 * @param records pointer to the array of record pointers
 * @param count pointer to a size_t variable containing the number of records
 * read
 * @return 0 in case of error, 1 in case of success
 */
int load_records_from_file(FILE *file, Record **records, size_t *count);

/**
 * @brief saves records from given array into an output file
 * @param file the file where to write the records
 * @param records pointer to the array of record struct to write
 * @param count number of record that will be written
 * @return 0 in case of error, 1 in case of success
 */
int save_records_to_file(FILE *file, const Record *records, size_t count);

/**
 * @brief print a given record
 * @param pointer to the record that will be printed
 */
void print_record(const Record *record);
