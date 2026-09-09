#include "../include/hash_table.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int str_cmp(const void *a, const void *b) {
  return strcmp((const char *)a, (const char *)b);
}
static unsigned long str_hash(const void *s) {
  const unsigned char *str = (const unsigned char *)s;
  unsigned long hash = 5381;
  int c;
  while ((c = *str++))
  hash = ((hash << 5) + hash) + (unsigned long)c;
  return hash;
}

static char *strdup_lower(const char *s) {
  size_t n = strlen(s);
  char *r = malloc(n + 1);
  if (!r)
    return NULL;
  for (size_t i = 0; i < n; i++)
    r[i] = (char)tolower((unsigned char)s[i]);
  r[n] = '\0';
  return r;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <path-to-file> <min-word-length>\n", argv[0]);
    return 1;
  }
  const char *path = argv[1];
  int minlen = atoi(argv[2]);
  if (minlen < 1) {
    fprintf(stderr, "min-word-length must be >= 1\n");
    return 1;
  }

  FILE *f = fopen(path, "r");
  if (!f) {
    fprintf(stderr, "Failed to open file: %s\n", path);
    return 1;
  }

  HashTable *ht = hash_table_create(str_cmp, str_hash);
  if (!ht) {
    fprintf(stderr, "Failed to create hash table\n");
    fclose(f);
    return 1;
  }

  char buf[1024];
  while (fscanf(f, "%1023s", buf) == 1) {
    char tmp[1024];
    int p = 0;
    for (size_t i = 0; i < strlen(buf); i++) {
      if (isalpha((unsigned char)buf[i]))
        tmp[p++] = buf[i];
      else {
        if (p > 0) {
          tmp[p] = '\0';
          if (p >= minlen) {
            char *key = strdup_lower(tmp);
            if (!key) {
              fprintf(stderr, "allocation error\n");
              break;
            }
            void *v = hash_table_get(ht, key);
            if (v) {
              size_t *cnt = (size_t *)v;
              (*cnt)++;
              free(key);
            } else {
              size_t *cnt = malloc(sizeof(size_t));
              if (!cnt) {
                free(key);
                break;
              }
              *cnt = 1;
              hash_table_put(ht, key, cnt);
            }
          }
          p = 0;
        }
      }
    }
    if (p > 0) {
      tmp[p] = '\0';
      if (p >= minlen) {
        char *key = strdup_lower(tmp);
        if (!key) {
          fprintf(stderr, "allocation error\n");
          break;
        }
        void *v = hash_table_get(ht, key);
        if (v) {
          size_t *cnt = (size_t *)v;
          (*cnt)++;
          free(key);
        } else {
          size_t *cnt = malloc(sizeof(size_t));
          if (!cnt) {
            free(key);
            break;
          }
          *cnt = 1;
          hash_table_put(ht, key, cnt);
        }
      }
    }
  }

  fclose(f);

  void **keys = hash_table_keyset(ht);
  if (!keys) {
    fprintf(stderr, "Failed to produce keyset\n");
    hash_table_free(ht);
    return 1;
  }

  const char *best = NULL;
  size_t best_count = 0;
  for (int i = 0; keys[i] != NULL; ++i) {
    size_t *cnt = (size_t *)hash_table_get(ht, keys[i]);
    if (cnt && *cnt > best_count) {
      best_count = *cnt;
      best = (const char *)keys[i];
    }
  }

  if (best)
    printf("Most frequent word (len >= %d): '%s' (count: %zu)\n", minlen, best,
           best_count);
  else
    printf("No word of length >= %d found\n", minlen);

  /* cleanup: free keys and counts, then table */
  for (int i = 0; keys[i] != NULL; ++i) {
    free(keys[i]);
    void *v = hash_table_get(ht, keys[i]);
    if (v)
      free(v);
  }
  free(keys);
  hash_table_free(ht);
  return 0;
}
