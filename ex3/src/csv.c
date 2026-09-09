#include "../include/csv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int csv_read_tasks(const char *filename, Task ***tasks, size_t *count) {
  FILE *f = fopen(filename, "r");
  if (!f) {
    return -1;
  }

  fseek(f, 0, SEEK_END);
  size_t len = ftell(f);
  fseek(f, 0, SEEK_SET);

  char *buf = malloc(len + 1);
  if (!buf) {
    return -1;
  }

  buf[len] = '\0';
  fread(buf, len, 1, f);
  fclose(f);

  int rows = 0;
  for (size_t i = 0; i < len; i++) {
    if (buf[i] == '\n') {
      rows++;
    }
  }

  int capacity = rows;
  int size = 0;
  Task **arr = malloc(capacity * sizeof(Task *));
  if (!arr) {
    return -1;
  }

  char *currP = buf;

  while (*currP) {
    Task *t = malloc(sizeof(Task));
    if (!t) {
      return -1;
    }
    t->id = (int)strtol(currP, &currP, 10);
    currP++;
    t->start = (int)strtol(currP, &currP, 10);
    currP++;
    t->length = (int)strtol(currP, &currP, 10);
    currP++;
    t->priority = (int)strtol(currP, &currP, 10);

    char *newline = memchr(currP, '\n', buf + len - currP);
    if (newline) {
      currP = newline + 1;
    }

    arr[size++] = t;
  }
  free(buf);
  *tasks = arr;
  *count = size;
  return 0;
}