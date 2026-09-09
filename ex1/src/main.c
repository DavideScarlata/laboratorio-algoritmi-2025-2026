#include "../include/sort_records.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <infile> <outfile> <field> <k>\n", argv[0]);
    return 1;
  }

  FILE *input = fopen(argv[1], "rb");
  FILE *output = fopen(argv[2], "wb");
  if (!input || !output) {
    perror("Failed to open file");
    if (input)
      fclose(input);
    if (output)
      fclose(output);
    return 1;
  }

  size_t field = strtoul(argv[3], NULL, 10);

  size_t k = strtoul(argv[4], NULL, 10);

  printf("Ordinamento avviato: Field=%zu, K=%zu\n", field, k);

  clock_t start = clock();
  sort_records(input, output, field, k);
  clock_t end = clock();

  double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Tempo impiegato: %lf s\n", cpu_time_used);

  fclose(input);
  fclose(output);

  return 0;
}
