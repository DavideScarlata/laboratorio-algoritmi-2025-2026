#include "../include/records.h"
#include <stdlib.h>
#include <string.h>

int read_record(FILE *file, Record *record) {
  if (file == NULL || record == NULL)
    return 0;

  return fread(record, sizeof(Record), 1, file) == 1;
}

int write_record(FILE *file, const Record *record) {
  if (file == NULL || record == NULL)
    return 0;
  return fwrite(record, sizeof(Record), 1, file) == 1;
}
int load_records_from_file(FILE *file, Record **records, size_t *count) {
  if (file == NULL || records == NULL || count == NULL)
    return -1;

  if (fseek(file, 0, SEEK_END) != 0) {
    perror("fseek SEEK_END failed");
    return 0;
  }

  long filesize = ftell(file);
  if (filesize == -1) {
    perror("ftell failed");
    return -1;
  }

  rewind(file);

  if ((size_t)filesize % sizeof(Record) != 0) {
    fprintf(stderr,
            "Errore: la dimensione del file (%ld) non e' un multiplo di "
            "sizeof(Record) (%zu)\n",
            filesize, sizeof(Record));
    return -1;
  }

  *count = (size_t)filesize / sizeof(Record);
  if (*count == 0) {
    *records = NULL;
    return 0; 
  }

  *records = (Record*)malloc((size_t)filesize);
  if (*records == NULL) {
      fprintf(stderr, "Errore: malloc di %ld bytes fallita\n", filesize);
      return -1;
  }

  size_t items_read = fread(*records, sizeof(Record), *count, file);
  if (items_read != *count) {
    fprintf(stderr, "Errore: letti %zu record, attesi %zu\n", items_read,
            *count);
    free(*records);
    *records = NULL;
    return -1;
  }

  return 0;
}

int save_records_to_file(FILE *file, const Record *records, size_t count) {
  if (file == NULL || (records == NULL && count > 0))
    return -1;
  if (count == 0)
    return 0;

  size_t items_written = fwrite(records, sizeof(Record), count, file);
  if (items_written != count) {
    fprintf(stderr, "Errore: scritti %zu record, attesi %zu\n", items_written,
            count);
    return -1;
  }
  return 0; 
}

void print_record(const Record *record) {
  if (record == NULL) {
    printf("NULL Record\n");
    return;
  }

  char field3_safe[17];
  memcpy(field3_safe, record->field3, 16);
  field3_safe[16] = '\0';

  printf("Record[ID: %lu, F1: %.2f, F2: %ld, F3: '%s']\n", record->id,
        record->field1, record->field2, field3_safe);
}
