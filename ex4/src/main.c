#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/graph.h"
#include "../include/bfs.h"

unsigned long string_hash(const void *k) {
    unsigned long hash = 5381;
    const char *str = (const char *)k;
    int c;
    while ((c = *str++)) hash = ((hash << 5) + hash) + (unsigned long)c;
    return hash;
}

int string_compare(const void *a, const void *b) {
    return strcmp((const char*)a, (const char*)b);
}

void trim_string(char *s) {
    char *p = s;
    int l = (int)strlen(p);
    while(l > 0 && isspace((unsigned char)p[l - 1])) p[--l] = 0;
    while(*p && isspace((unsigned char)*p)) ++p, --l;
    memmove(s, p, (size_t)l + 1);
}

static char *dup_string(const char *s) {
    size_t len = strlen(s) + 1;
    char *new_s = malloc(len);
    if (new_s) {
        memcpy(new_s, s, len);
    }
    return new_s;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_file> <start_city> <output_file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *start_node = argv[2];
    char *output_file = argv[3];

    Graph g = graph_create(0, 0, string_compare, string_hash);
    FILE *fp = fopen(input_file, "r");
    if (!fp) { perror("Errore apertura file input"); return 1; }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        trim_string(line);
        char *city1_token = strtok(line, ",");
        char *city2_token = strtok(NULL, ",");

        if(city1_token && city2_token) {
            char *c1 = dup_string(city1_token);
            char *c2 = dup_string(city2_token);
            
            if (!c1 || !c2) {
                fprintf(stderr, "Errore allocazione memoria stringhe\n");
                free(c1); free(c2);
                continue;
            }
            graph_add_node(g, c1); 
            graph_add_node(g, c2);
            graph_add_edge(g, c1, c2, NULL);
        }
    }
    fclose(fp);
    void **result = breadth_first_visit(g, start_node, string_compare, string_hash);
    if (!result) {
        fprintf(stderr, "Errore: Nodo partenza non trovato o errore memoria.\n");
        graph_free(g);
        return 1;
    }
    FILE *fout = fopen(output_file, "w");
    if (!fout) { perror("Errore file output"); return 1; }
    
    for (int i = 0; result[i] != NULL; i++) {
        fprintf(fout, "%s\n", (char*)result[i]);
    }
    fclose(fout);
    free(result);
    return 0;
}