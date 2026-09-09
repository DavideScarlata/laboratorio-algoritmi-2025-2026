#ifndef BFS_H
#define BFS_H

#include "graph.h"
#include <stdio.h>

/**
 * @file bfs.h
 * @brief Funzione per la visita in ampiezza (Breadth-First Search) su un grafo.
 */

/**
 * @brief Esegue una visita BFS su un grafo a partire da un nodo iniziale.
 *
 * La funzione visita tutti i nodi raggiungibili a partire dal nodo `start`,
 * usando una coda interna per la BFS. Restituisce un array dinamico di puntatori
 * ai nodi visitati, terminato da `NULL`.
 *
 * @param gr      Il grafo da visitare.
 * @param start   Nodo di partenza della visita.
 * @param compare Funzione di confronto tra nodi (es. strcmp).
 * @param hash    Funzione di hash dei nodi (per compatibilità, non usata nella BFS).
 *
 * @return Array dinamico di puntatori ai nodi visitati, terminato da NULL.
 * Deve essere liberato dall'utente.
 */
void **breadth_first_visit(Graph gr, void* start, 
                            int (*compare)(const void*, const void*), 
                            unsigned long (*hash)(const void*));

#endif