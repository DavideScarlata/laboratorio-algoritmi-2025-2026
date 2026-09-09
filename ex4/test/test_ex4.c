#include "../include/graph.h"
#include "../include/bfs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

unsigned long string_hash(const void *k) {
    unsigned long hash = 5381;
    const char *str = (const char *)k;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + (unsigned long)c;
    return hash;
}

int string_compare(const void *a, const void *b) {
    return strcmp((const char*)a, (const char*)b);
}

void test_add_remove_nodes() {
    printf("Esecuzione test_add_remove_nodes...\n");
    Graph g = graph_create(0, 1, string_compare, string_hash);
    assert(g);

    assert(graph_add_node(g, "A") == 1);
    assert(graph_add_node(g, "B") == 1);
    assert(graph_add_node(g, "A") == 0);

    assert(graph_contains_node(g, "A") == 1);
    assert(graph_contains_node(g, "B") == 1);
    assert(graph_contains_node(g, "C") == 0);

    assert(graph_remove_node(g, "B") == 1);
    assert(graph_contains_node(g, "B") == 0);
    assert(graph_remove_node(g, "B") == 0);

    graph_free(g);
    printf("test_add_remove_nodes passato.\n");
}

void test_add_remove_edges() {
    printf("Esecuzione test_add_remove_edges...\n");
    Graph g = graph_create(0, 1, string_compare, string_hash);
    assert(g);

    graph_add_node(g, "A");
    graph_add_node(g, "B");
    graph_add_node(g, "C");

    assert(graph_add_edge(g, "A", "B", NULL) == 1);
    assert(graph_add_edge(g, "A", "B", NULL) == 0);
    assert(graph_contains_edge(g, "A", "B") == 1);
    assert(graph_contains_edge(g, "B", "A") == 0);

    assert(graph_add_edge(g, "B", "C", NULL) == 1);
    assert(graph_remove_edge(g, "A", "B") == 1);
    assert(graph_contains_edge(g, "A", "B") == 0);
    assert(graph_remove_edge(g, "A", "B") == 0);
    graph_free(g);
    printf("test_add_remove_edges passato.\n");
}

void test_bfs() {
    printf("Esecuzione test_bfs...\n");
    Graph g = graph_create(0, 0, string_compare, string_hash);
    assert(g);

    graph_add_node(g, "A");
    graph_add_node(g, "B");
    graph_add_node(g, "C");
    graph_add_node(g, "D");
    graph_add_edge(g, "A", "B", NULL);
    graph_add_edge(g, "A", "C", NULL);
    graph_add_edge(g, "B", "D", NULL);

    void **visited = breadth_first_visit(g, "A", string_compare, string_hash);

    int count = 0;
    while (visited[count] != NULL) count++;
    assert(count == 4);

    assert(string_compare(visited[0], "A") == 0);
    int second_ok = (string_compare(visited[1], "B") == 0 && string_compare(visited[2], "C") == 0)
                 || (string_compare(visited[1], "C") == 0 && string_compare(visited[2], "B") == 0);
    assert(second_ok);
    assert(string_compare(visited[3], "D") == 0);

    free(visited);
    graph_free(g);
    printf("test_bfs passato.\n");
}

int main() {
    test_add_remove_nodes();
    test_add_remove_edges();
    test_bfs();

    printf("\nTest finiti\n");
    return 0;
}