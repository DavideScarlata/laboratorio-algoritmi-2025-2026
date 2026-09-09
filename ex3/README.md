# Relazione Esercizio 3: Coda di Priorità con Heap Ternario

## 1. Introduzione

Il presente esercizio richiede l'implementazione di una struttura dati di tipo **Coda di Priorità** (Priority Queue), realizzata mediante un **Heap Ternario** (Max-Heap). L'obiettivo principale è fornire una libreria generica in linguaggio C in grado di gestire elementi di tipo arbitrario, offrendo operazioni efficienti di inserimento, estrazione del massimo e, specificamente, la modifica o rimozione di elementi arbitrari grazie all'integrazione di una **Tavola Hash**.

A dimostrazione della flessibilità della libreria, è stata sviluppata un'applicazione di simulazione per lo scheduling di task su un processore singolo, seguendo una logica non-preemptive.

## 2. Scelte Progettuali e Implementative

### 2.1. Struttura Dati: Heap Ternario

Per l'implementazione della coda di priorità è stata scelta una struttura ad albero rappresentata implicitamente tramite un array dinamico (`void **data`). A differenza del classico heap binario, si è optato per un **Heap Ternario** ($k=3$).

* **Motivazione**: Un heap $k$-ario riduce l'altezza dell'albero da $\log_2 n$ a $\log_k n$. Questo comporta un numero inferiore di livelli da attraversare durante le operazioni di risalita (`heapify_up`), potenzialmente migliorando le prestazioni in inserimento. Di contro, l'operazione di discesa (`heapify_down`) richiede più confronti per individuare il figlio con priorità maggiore (3 confronti invece di 2), ma il bilanciamento scelto ($k=3$) rappresenta spesso un buon compromesso tra altezza dell'albero e costo di elaborazione dei nodi.
* **Indicizzazione**: Dato un nodo all'indice $i$:
    * Il padre si trova a: $\lfloor \frac{i-1}{3} \rfloor$
    * L'$j$-esimo figlio ($1 \le j \le 3$) si trova a: $3i + j$

### 2.2. Integrazione con Tavola Hash

Una limitazione delle code di priorità standard basate su heap è la difficoltà nel ricercare o rimuovere un elemento che non sia la radice (operazioni tipicamente $O(n)$).
Per ovviare a questo problema, la struttura `PriorityQueue` mantiene internamente una **Tavola Hash** (`HashTable *map`) che associa:

* **Chiave**: Puntatore all'elemento inserito nella coda.
* **Valore**: Indice corrente dell'elemento nell'array dello heap.

Questa scelta architetturale permette di ottenere le coordinate di qualsiasi elemento in tempo costante $O(1)$, rendendo l'operazione `contains` immediata e l'operazione `remove` logaritmica (limitata solo dal costo di ripristino dell'heap).

### 2.3. Genericità del Codice

L'implementazione rispetta i requisiti di genericità del linguaggio C:
* La struttura gestisce puntatori generici `void *`.
* L'ordinamento e l'hashing sono delegati a funzioni fornite dall'utente all'atto della creazione (`cmp` e `hash`).
* Questo design disaccoppia la logica della struttura dati dal tipo di dato ospitato (nel caso specifico, la struct `Task`).

## 3. Analisi della Complessità

Di seguito si riporta l'analisi della complessità temporale asintotica per le operazioni principali, considerando $n$ come numero di elementi nella coda.

| Operazione | Complessità Temporale | Descrizione |
| :--- | :--- | :--- |
| `priority_queue_push` | $O(\log_3 n)$ | Inserimento in coda all'array e risalita (`heapify_up`). L'aggiornamento della mappa è $O(1)$. |
| `priority_queue_pop` | $O(\log_3 n)$ | Rimozione della radice, spostamento dell'ultimo elemento in testa e discesa (`heapify_down`). |
| `priority_queue_top` | $O(1)$ | Accesso diretto all'elemento in posizione 0.|
| `priority_queue_contains` | $O(1)$ | Verifica diretta tramite la Tavola Hash interna. |
| `priority_queue_remove` | $O(\log_3 n)$ | Accesso all'indice tramite Hash Map ($O(1)$) seguito da rimozione e ripristino heap (`heapify_up` o `down`). |

**Nota**: Le complessità della Hash Table si intendono nel caso medio. Nel caso pessimo (molte collisioni), le operazioni degraderebbero linearmente, ma l'uso di una funzione di hash robusta e il resizing automatico minimizzano questo rischio.

## 4. Simulazione di Scheduling (Main)

L'applicazione `main_ex3` simula uno scheduler di CPU **non-preemptive**.
Il programma legge un dataset di task da CSV e simula l'avanzamento temporale:

1.  I task vengono caricati in memoria.
2.  Al tempo corrente $t$, tutti i task con `start_time <= t` vengono inseriti nella coda di priorità.
3.  Viene estratto il task a priorità massima.
4.  La CPU "esegue" il task (avanzando il tempo di `task->length`) senza interruzioni.
5.  Il ciclo si ripete finché tutti i task non sono completati.

Per massimizzare l'efficienza, se la coda è vuota ma ci sono ancora task futuri, il tempo salta direttamente al prossimo `start_time` disponibile, evitando cicli di attesa inutili ("busy waiting").

## 5. Strategia di Testing

La correttezza della libreria è verificata tramite una suite di unit test (`test/test_ex3.c`) che copre:

* **Funzionalità Base**: Push, pop e verifica dell'ordine di estrazione corretto.
* **Integrazione Mappa**: Verifica che `contains` restituisca `true`/`false` correttamente prima e dopo le rimozioni.
* **Rimozione Arbitraria**: Test di rimozione di elementi sia dalle foglie che dai nodi interni, verificando il mantenimento della proprietà di heap.
* **Scalabilità**: Inserimento ed estrazione di grandi quantità di elementi per testare il resizing dinamico dell'array e della tabella hash.