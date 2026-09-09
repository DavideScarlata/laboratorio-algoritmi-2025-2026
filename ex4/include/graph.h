#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include "hash_table.h"

/**
 * @brief Rappresenta un arco del grafo.
 */
typedef struct {
    void *source;   /**< Nodo di partenza */
    void *dest;     /**< Nodo di destinazione */
    void *label;    /**< Etichetta opzionale dell'arco */
} Edge;

/**
 * @brief Tipo opaco per il grafo.
 */
typedef struct graph* Graph;

/**
 * @brief Crea un nuovo grafo.
 * * @param labelled Se diverso da 0, il grafo supporta etichette sugli archi.
 * @param directed Se diverso da 0, il grafo è diretto.
 * @param compare Funzione di confronto per i nodi.
 * @param hash Funzione di hash per i nodi.
 * @return Graph Puntatore al nuovo grafo o NULL in caso di errore.
 */
Graph graph_create(int labelled, int directed,
                   int (*compare)(const void*, const void*),
                   unsigned long (*hash)(const void*));

/**
 * @brief Controlla se il grafo è diretto.
 * * @param gr Grafo.
 * @return int 1 se diretto, 0 altrimenti.
 */
int graph_is_directed(const Graph gr);

/**
 * @brief Controlla se il grafo supporta etichette.
 * * @param gr Grafo.
 * @return int 1 se etichettato, 0 altrimenti.
 */
int graph_is_labelled(const Graph gr);

/**
 * @brief Aggiunge un nodo al grafo.
 * * @param gr Grafo.
 * @param node Nodo da aggiungere.
 * @return int 1 se aggiunto, 0 se già presente o errore.
 */
int graph_add_node(Graph gr, const void* node);

/**
 * @brief Controlla se un nodo è presente nel grafo.
 * * @param gr Grafo.
 * @param node Nodo da cercare.
 * @return int 1 se presente, 0 altrimenti.
 */
int graph_contains_node(const Graph gr, const void* node);

/**
 * @brief Rimuove un nodo dal grafo.
 * * @param gr Grafo.
 * @param node Nodo da rimuovere.
 * @return int 1 se rimosso, 0 se non presente o errore.
 */
int graph_remove_node(Graph gr, const void* node);

/**
 * @brief Restituisce il numero di nodi nel grafo.
 * * @param gr Grafo.
 * @return int Numero di nodi.
 */
int graph_num_nodes(const Graph gr);

/**
 * @brief Restituisce tutti i nodi del grafo.
 * * @param gr Grafo.
 * @return void** Array di puntatori ai nodi. Deve essere liberato con free().
 */
void **graph_get_nodes(const Graph gr);

/**
 * @brief Aggiunge un arco tra due nodi.
 * * @param gr Grafo.
 * @param node1 Nodo sorgente.
 * @param node2 Nodo destinazione.
 * @param label Etichetta dell'arco (NULL se non etichettato).
 * @return int 1 se aggiunto, 0 se già presente o errore.
 */
int graph_add_edge(Graph gr, const void* node1, const void* node2, const void* label);

/**
 * @brief Controlla se esiste un arco tra due nodi.
 * * @param gr Grafo.
 * @param node1 Nodo sorgente.
 * @param node2 Nodo destinazione.
 * @return int 1 se l'arco esiste, 0 altrimenti.
 */
int graph_contains_edge(const Graph gr, const void* node1, const void* node2);

/**
 * @brief Rimuove un arco tra due nodi.
 * * @param gr Grafo.
 * @param node1 Nodo sorgente.
 * @param node2 Nodo destinazione.
 * @return int 1 se rimosso, 0 se non presente o errore.
 */
int graph_remove_edge(Graph gr, const void* node1, const void* node2);

/**
 * @brief Restituisce il numero totale di archi nel grafo.
 * * @param gr Grafo.
 * @return int Numero di archi.
 */
int graph_num_edges(const Graph gr);

/**
 * @brief Restituisce tutti gli archi del grafo.
 * * @param gr Grafo.
 * @return Edge** Array di puntatori agli archi. L'array e gli Edge devono essere liberati con free().
 */
Edge **graph_get_edges(const Graph gr);

/**
 * @brief Restituisce l'etichetta di un arco tra due nodi.
 * * @param gr Grafo.
 * @param node1 Nodo sorgente.
 * @param node2 Nodo destinazione.
 * @return void* Puntatore all'etichetta, NULL se non presente.
 */
void *graph_get_label(const Graph gr, const void* node1, const void* node2);

/**
 * @brief Restituisce i vicini di un nodo.
 * * @param gr Grafo.
 * @param node Nodo di cui ottenere i vicini.
 * @return void** Array di puntatori ai nodi vicini. Deve essere liberato con free().
 */
void **graph_get_neighbours(const Graph gr, const void* node);

/**
 * @brief Restituisce il numero di vicini di un nodo.
 * * @param gr Grafo.
 * @param node Nodo di cui contare i vicini.
 * @return int Numero di vicini.
 */
int graph_num_neighbours(const Graph gr, const void* node);

/**
 * @brief Libera tutta la memoria associata al grafo.
 * * @param gr Grafo da liberare.
 */
void graph_free(Graph gr);

#endif