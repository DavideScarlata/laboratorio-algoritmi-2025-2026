#include "../include/graph.h"

struct graph {
    int directed;
    int labelled;
    HashTable *adjacency;
    int (*compare)(const void *, const void *);
    unsigned long (*hash)(const void *);
    int edge_count;
};

Graph graph_create(int labelled, int directed, int (*compare)(const void*, const void*), unsigned long (*hash)(const void*)) {
    Graph gr = malloc(sizeof(struct graph));
    if (!gr) {
        return NULL;
    }

    gr->directed = directed;
    gr->labelled = labelled;
    gr->compare = compare;
    gr->hash = hash;
    gr->edge_count = 0;

    gr->adjacency = hash_table_create(compare, hash);
    if (!gr->adjacency) {
        free(gr);
        return NULL;
    }

    return gr;
}

int graph_is_directed(const Graph gr) { 
    return gr->directed; 
}

int graph_is_labelled(const Graph gr) { 
    return gr->labelled; 
}

int graph_add_node(Graph gr, const void* node) {
    if (!node) {
        return 0;
    }
    if (hash_table_contains_key(gr->adjacency, node)) {
        return 0;
    }

    HashTable *neighbors = hash_table_create(gr->compare, gr->hash);
    if (!neighbors) {
        return 0;
    }

    hash_table_put(gr->adjacency, node, neighbors);
    return 1;
}

int graph_contains_node(const Graph gr, const void* node) {
    if (!node) {
        return 0;
    }

    return hash_table_contains_key(gr->adjacency, node);
}

int graph_remove_node(Graph gr, const void* node) {
    if (!node) {
        return 0;
    }

    HashTable *neighbors = hash_table_get(gr->adjacency, node);
    if (!neighbors) {
        return 0;
    }

    void **keys = hash_table_keyset(neighbors);
    int n = hash_table_size(neighbors);
    for (int i = 0; i < n; i++) {
        graph_remove_edge(gr, node, keys[i]);
    }
    free(keys);

    if (gr->directed) {
        void **all_nodes = hash_table_keyset(gr->adjacency);
        int n_nodes = hash_table_size(gr->adjacency);
        for (int i = 0; i < n_nodes; i++) {
            void *other = all_nodes[i];
            if (gr->compare(other, node) == 0) continue;
            HashTable *adj = hash_table_get(gr->adjacency, other);
            if (hash_table_contains_key(adj, node)) {
                graph_remove_edge(gr, other, node);
            }
        }
        free(all_nodes);
    }

    hash_table_free(neighbors);
    hash_table_remove(gr->adjacency, node);

    return 1;
}

int graph_num_nodes(const Graph gr) {
    return hash_table_size(gr->adjacency);
}

void **graph_get_nodes(const Graph gr) {
    return hash_table_keyset(gr->adjacency);
}

int graph_add_edge(Graph gr, const void* node1, const void* node2, const void* label) {
    if (!node1 || !node2) {
        return 0;
    }
    if (!graph_contains_node(gr, node1) || !graph_contains_node(gr, node2)) {
        return 0;
    }

    HashTable *adj1 = hash_table_get(gr->adjacency, node1);
    HashTable *adj2 = hash_table_get(gr->adjacency, node2);

    if (hash_table_contains_key(adj1, node2)) {
        return 0;
    }

    Edge *e = malloc(sizeof(Edge));
    if (!e) {
        return 0;
    }

    e->source = (void*)node1;
    e->dest = (void*)node2;
    e->label = gr->labelled ? (void*)label : NULL;

    hash_table_put(adj1, node2, e);

    if (!gr->directed) {
        Edge *e_rev = malloc(sizeof(Edge));
        if (!e_rev) return 0;
        e_rev->source = (void*)node2;
        e_rev->dest = (void*)node1;
        e_rev->label = gr->labelled ? (void*)label : NULL;
        hash_table_put(adj2, node1, e_rev);
    }

    gr->edge_count++;
    return 1;
}

int graph_contains_edge(const Graph gr, const void* node1, const void* node2) {
    if (!node1 || !node2) {
        return 0;
    }

    HashTable *adj = hash_table_get(gr->adjacency, node1);
    if (!adj) {
        return 0;
    }

    return hash_table_contains_key(adj, node2);
}

int graph_remove_edge(Graph gr, const void* node1, const void* node2) {
    if (!node1 || !node2) {
        return 0;
    }

    HashTable *adj1 = hash_table_get(gr->adjacency, node1);
    if (!adj1) {
        return 0;
    }

    Edge *e = hash_table_get(adj1, node2);
    if (!e) {
        return 0;
    }

    free(e);
    hash_table_remove(adj1, node2);

    if (!gr->directed) {
        HashTable *adj2 = hash_table_get(gr->adjacency, node2);
        Edge *e_rev = hash_table_get(adj2, node1);
        if (e_rev) {
            free(e_rev);
            hash_table_remove(adj2, node1);
        }
    }

    gr->edge_count--;
    return 1;
}

int graph_num_edges(const Graph gr) {
    return gr->edge_count;
}

Edge **graph_get_edges(const Graph gr) {
    if (!gr) {
        return NULL;
    }
    Edge **arr = malloc(sizeof(Edge*) * ((size_t)gr->edge_count + 1));
    if (!arr) { 
        return NULL; 
    }

    int n_nodes = hash_table_size(gr->adjacency);
    void **nodes = hash_table_keyset(gr->adjacency);
    if (!nodes) {
        free(arr);
        return NULL;
    }

    int index = 0;

    for (int i = 0; i < n_nodes; i++) {
        HashTable *adj = hash_table_get(gr->adjacency, nodes[i]);
        void **neigh_keys = hash_table_keyset(adj);
        int n_neigh = hash_table_size(adj);

        for (int j = 0; j < n_neigh; j++) {
            Edge *original = hash_table_get(adj, neigh_keys[j]);

            if (!gr->directed && gr->compare(original->source, original->dest) > 0) 
                continue;
            
            Edge *copy = malloc(sizeof(Edge));
            if (!copy) {
                for (int k = 0; k < index; k++) free(arr[k]);
                free(arr);
                free(neigh_keys);
                free(nodes);
                return NULL;
            }

            copy->source = original->source;
            copy->dest = original->dest;
            copy->label = original->label;

            arr[index++] = copy;
        }

        free(neigh_keys);
    }

    arr[index] = NULL;
    free(nodes);
    return arr;
}

void *graph_get_label(const Graph gr, const void* node1, const void* node2) {
    if (!node1 || !node2) {
        return NULL;
    }

    HashTable *adj = hash_table_get(gr->adjacency, node1);
    if (!adj) {
        return NULL;
    }

    Edge *e = hash_table_get(adj, node2);
    if (!e) {
        return NULL;
    }

    return e->label;
}

void **graph_get_neighbours(const Graph gr, const void* node) {
    if (!node) {
        return NULL;
    }

    HashTable *adj = hash_table_get(gr->adjacency, node);
    if (!adj) {
        return NULL;
    }

    return hash_table_keyset(adj);
}

int graph_num_neighbours(const Graph gr, const void* node) {
    if (!node) {
        return 0;
    }

    HashTable *adj = hash_table_get(gr->adjacency, node);
    if (!adj) {
        return 0;
    }
    
    return hash_table_size(adj);
}

void graph_free(Graph gr) {
    void **nodes = hash_table_keyset(gr->adjacency);
    int n_nodes = hash_table_size(gr->adjacency);

    for (int i = 0; i < n_nodes; i++) {
        HashTable *adj = hash_table_get(gr->adjacency, nodes[i]);
        void **neigh = hash_table_keyset(adj);
        int n = hash_table_size(adj);

        for (int j = 0; j < n; j++) {
            Edge *e = hash_table_get(adj, neigh[j]);
            free(e);
        }
        free(neigh);
        hash_table_free(adj);
    }

    free(nodes);
    hash_table_free(gr->adjacency);
    free(gr);
}