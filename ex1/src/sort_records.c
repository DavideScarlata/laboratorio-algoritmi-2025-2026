#include "../include/sort_records.h"
#include "../include/hybridsort.h"
#include "../include/records.h"
#include <stdlib.h>
#include <string.h>

int cmp_id(const void *a, const void *b);
int cmp_field1(const void *a, const void *b);
int cmp_field2(const void *a, const void *b);
int cmp_field3(const void *a, const void *b);

void sort_records(FILE *infile, FILE *outfile, size_t field, size_t k) {

  if (fseek(infile, 0, SEEK_END) != 0) {
    perror("fseek fallita");
    return;
  }
  long filesize = ftell(infile);
  rewind(infile);

  if (filesize == -1) {
    perror("ftell (in sort_records) fallito");
    return;
  }
  size_t r_size = sizeof(Record);

  if ((size_t)filesize % r_size != 0) {
    fprintf(stderr,
            "Warning: Dimensione file non multipla di sizeof(Record) (%zu).\n",
            r_size);
  }

  size_t nitems = (size_t)filesize / r_size;

  unsigned char *data = malloc((size_t)filesize);
  if (data == NULL && nitems > 0) {
    fprintf(stderr, "malloc fallita in sort_records\n");
    return;
  }

  size_t items_read = fread(data, r_size, nitems, infile);
  if (items_read != nitems) {
    fprintf(stderr, "Errore lettura: letti %zu elementi su %zu attesi.\n",
            items_read, nitems);
    nitems = items_read;
  }

  int (*cmp)(const void *a, const void *b);
  switch (field) {
  case 0:
    cmp = cmp_id;
    break;
  case 1:
    cmp = cmp_field1;
    break;
  case 2:
    cmp = cmp_field2;
    break;
  case 3:
    cmp = cmp_field3;
    break;
  default:
    fprintf(stderr,
            "Errore: Field non valido: %zu. Deve essere 0, 1, 2, o 3.\n",
            field);
    free(data);
    return;
  }

  hybrid_sort(data, nitems, r_size, k, cmp);
  fwrite(data, r_size, nitems, outfile);

  free(data);
}

int cmp_id(const void *a, const void *b) {
  uint64_t x = *(uint64_t *)a;
  uint64_t y = *(uint64_t *)b;
  return (x > y) - (x < y);
}

int cmp_field1(const void *a, const void *b) {
  float x = *(float *)((unsigned char *)a + 8);
  float y = *(float *)((unsigned char *)b + 8);
  return (x > y) - (x < y);
}

int cmp_field2(const void *a, const void *b) {
  int64_t x = *(int64_t *)((unsigned char *)a + 12);
  int64_t y = *(int64_t *)((unsigned char *)b + 12);
  return (x > y) - (x < y);
}

int cmp_field3(const void *a, const void *b) {
  return strncmp((char *)a + 20, (char *)b + 20, 16);
}
