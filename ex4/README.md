# Relazione Esercizio 4: Libreria Grafo Sparso e Visita BFS

## 1. Introduzione
L'obiettivo dell'esercizio è la realizzazione di una libreria generica in linguaggio C per la gestione di **grafi**, ottimizzata per dati sparsi. L'implementazione si basa sulla struttura dati *Hash Table* (sviluppata nell'Esercizio 2) per garantire efficienza nelle operazioni di inserimento e ricerca.
La libreria è stata successivamente utilizzata per implementare l'algoritmo di visita in ampiezza (BFS) e testata su un dataset reale contenente le distanze tra varie località italiane (`italian_dist_graph.csv`).

## 2. Scelte Progettuali e Implementative

### 2.1 Rappresentazione del Grafo (Grafi Sparsi)
Per soddisfare il requisito di ottimizzazione per **grafi sparsi**, si è scelto di non utilizzare una matrice di adiacenza (che richiederebbe spazio $O(V^2)$, inefficiente se $E \ll V^2$).
Si è optato invece per una variante delle **liste di adiacenza**, implementate però tramite **Tavole Hash annidate**:

1.  **Struttura Principale (`adjacency`)**: Una Hash Table che mappa ogni nodo (chiave) alla propria struttura dei vicini (valore).
2.  **Struttura dei Vicini**: Il valore associato a ogni nodo è, a sua volta, una Hash Table. Questa contiene come chiavi i nodi adiacenti e come valori le strutture `Edge` (che incapsulano il puntatore all'etichetta dell'arco).

Questa scelta architetturale offre vantaggi significativi rispetto alle liste concatenate classiche:
* **Verifica esistenza arco**: $O(1)$ medio (invece di $O(degree(u))$ nelle liste linkate).
* **Rimozione arco**: $O(1)$ medio.
* **Efficienza spaziale**: La memoria allocata è proporzionale al numero di nodi e archi presenti ($O(V + E)$), ideale per grafi sparsi.

### 2.2 Gestione della Genericità
La libreria è completamente generica e agnostica rispetto al tipo di dato dei nodi e delle etichette.
* I nodi e le etichette sono gestiti tramite puntatori `void *`.
* Per il corretto funzionamento delle Hash Table interne, la funzione `graph_create` richiede all'utente di fornire:
    * Una funzione di confronto (`compare`).
    * Una funzione di hashing (`hash`).
Ciò permette di utilizzare il grafo con stringhe (come nel `main_ex4`), interi o strutture personalizzate senza modifiche al codice sorgente della libreria.

### 2.3 Grafi Diretti e Non Diretti
La struttura `Graph` mantiene un flag `directed`.
* **Inserimento in grafo non diretto**: L'inserimento di un arco $(u, v)$ comporta automaticamente l'inserimento dell'arco $(v, u)$ nelle rispettive tabelle di adiacenza.
* **Rimozione**: Analogamente, la rimozione elimina entrambe le entrate.

## 3. Algoritmo di Visita in Ampiezza (BFS)

L'algoritmo `breadth_first_visit` è stato implementato utilizzando:
1.  **Coda (FIFO)**: Implementata tramite un array dinamico (`void **queue`) gestito con indici `head` e `tail`. L'array viene ridimensionato (raddoppiato) se la capacità viene superata.
2.  **Set dei Visitati**: Per verificare in tempo costante $O(1)$ se un nodo è già stato visitato, è stata utilizzata una **Hash Table** di supporto (`visited_set`), invece di marcare i nodi stessi (che richiederebbe la modifica della struttura dati interna o dei dati utente).

L'algoritmo restituisce un array dinamico contenente i nodi nell'ordine di visita.

## 4. Analisi della Complessità

Di seguito le complessità temporali attese (caso medio, assumendo una buona distribuzione della funzione hash):

| Operazione | Complessità Temporale | Note |
|:-----------|:---------------------:|:-----|
| `graph_add_node` | $O(1)$ | Inserimento nella HT principale. |
| `graph_remove_node` | $O(D)$ | $D$ = grado del nodo (necessario rimuovere archi incidenti). |
| `graph_add_edge` | $O(1)$ | Due inserimenti in HT (se non diretto). |
| `graph_remove_edge` | $O(1)$ | Rimozione dalla HT dei vicini. |
| `graph_contains_edge`| $O(1)$ | Lookup diretto nella HT dei vicini. |
| `breadth_first_visit`| $O(V + E)$ | Ogni nodo e ogni arco vengono processati al più una volta. |

## 5. Risultati Sperimentali

Il programma `main_ex4` è stato eseguito sul dataset `italian_dist_graph.csv` partendo dalla città di "torino".

* **Comando**: `$ ./bin/main_ex4 italian_dist_graph.csv torino output.txt`
* **Dataset**: italian_dist_graph.csv
* **Tempo di esecuzione**:  0m0,173s
* **Output**: Il file `output.txt` è stato generato correttamente contenente la lista delle località raggiunte.

I tempi di esecuzione rilevati sono coerenti con la complessità teorica lineare $O(V+E)$, confermando l'efficienza della struttura basata su Hash Table anche per il caricamento e la visita di dataset di dimensioni medie.

## 6. Conclusioni
La soluzione proposta soddisfa i requisiti di genericità e gestione efficiente della memoria per grafi sparsi. L'uso delle Hash Table sia per l'implementazione del grafo che per le strutture ausiliarie della BFS ha permesso di mantenere basse le costanti moltiplicative delle operazioni, garantendo prestazioni elevate.