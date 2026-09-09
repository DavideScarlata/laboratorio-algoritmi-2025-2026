#include "../include/bfs.h"
#include "../include/hash_table.h"
#include <stdlib.h>
#include <stdio.h>

static int VISITED_VALUE = 1;

void **breadth_first_visit(Graph gr, void* start, int (*compare)(const void*, const void*), unsigned long (*hash)(const void*)) {
    if (!graph_contains_node(gr, start)) {
        return NULL;
    }
    
    int n_nodes = graph_num_nodes(gr);
    int capacity = (n_nodes > 0) ? n_nodes : 1;
    
    void **visited = malloc(sizeof(void*) * ((size_t)capacity + 1));
    int visited_count = 0;

    void **queue = malloc(sizeof(void*) * (size_t)capacity);
    int head = 0, tail = 0;
    
    HashTable *visited_set = hash_table_create(compare, hash);
    
    if (!visited || !queue || !visited_set) {
        if(visited) free(visited);
        if(queue) free(queue);
        if(visited_set) hash_table_free(visited_set);
        return NULL;
    }
    queue[tail++] = start;
    visited[visited_count++] = start;
    hash_table_put(visited_set, start, &VISITED_VALUE);

    while (head < tail) {
        void *current = queue[head++];

        void **neighbors = graph_get_neighbours(gr, current);
        int n_neigh = graph_num_neighbours(gr, current);

        if (neighbors) { 
            for (int i = 0; i < n_neigh; i++) {
                void *neighbor = neighbors[i];
                if (!hash_table_contains_key(visited_set, neighbor)) {
                    if (visited_count >= capacity) {
                        int new_capacity = capacity * 2;
                        void **temp_v = realloc(visited, sizeof(void*) * ((size_t)new_capacity + 1));
                        if (!temp_v) {
                            free(neighbors);
                            free(queue);
                            free(visited);
                            hash_table_free(visited_set);
                            return NULL;
                        }
                        visited = temp_v;
                        void **temp_q = realloc(queue, sizeof(void*) * (size_t)new_capacity);
                        if (!temp_q) {
                            free(neighbors);
                            free(queue);
                            free(visited);
                            hash_table_free(visited_set);
                            return NULL;
                        }
                        queue = temp_q;
                        
                        capacity = new_capacity;
                    }

                    queue[tail++] = neighbor;
                    visited[visited_count++] = neighbor;
                    hash_table_put(visited_set, neighbor, &VISITED_VALUE);
                }
            }
            free(neighbors);
        }
    }

    free(queue);
    hash_table_free(visited_set);
    void **final_visited = realloc(visited, sizeof(void*) * ((size_t)visited_count + 1));
    if (final_visited) {
        visited = final_visited;
    }
    visited[visited_count] = NULL;
    
    return visited;
}