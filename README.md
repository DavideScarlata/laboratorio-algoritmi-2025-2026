# Algoritmi e Strutture Dati - Progetto Universitario

Questa repository contiene il mio progetto finale per il laboratorio del corso di **Algoritmi e Strutture Dati**. Il progetto si concentra sull'implementazione di algoritmi e strutture dati generiche e robuste in **C**, seguendo rigorosamente le moderne pratiche di ingegneria del software, tra cui test unitari completi, gestione sicura della memoria e design modulare.

##  Caratteristiche Principali e Architettura

Sebbene la repository contenga diverse implementazioni algoritmiche, il fiore all'occhiello del progetto è l'**Esercizio 3**, per il quale ho progettato e sviluppato una **Coda di Priorità** avanzata e altamente ottimizzata:

* **Heap Ternario (**$k=3$**):** Implementazione di un heap ternario al posto di un classico heap binario. Questo riduce l'altezza dell'albero a $\log_3 n$, ottimizzando i tempi per le operazioni di `heapify_up`.

* **Tabella Hash Sincronizzata:** Per superare il classico collo di bottiglia della ricerca $O(n)$ nelle code di priorità, l'heap è stato strettamente accoppiato a una Hash Table sviluppata ad hoc. La mappa hash tiene traccia costantemente dell'indice di ogni elemento all'interno dell'array dell'heap.

  * **Risultato:** Ricerca di un elemento arbitrario in tempo $O(1)$ e rimozione/aggiornamento di un elemento arbitrario in tempo $O(\log_3 n)$.

* **Simulazione CPU Scheduler:** L'efficienza della struttura è stata validata a livello pratico simulando uno scheduler di CPU non-preemptive. Il programma elabora in modo efficiente un dataset di grandi dimensioni (`tasks.csv`), utilizzando un approccio ad avanzamento temporale logico per evitare attese inutili (busy waiting).

##  Tecnologie e Strumenti

* **C:** Linguaggio principale del progetto, con un forte utilizzo di `void*` e puntatori a funzione per creare strutture dati generiche e riutilizzabili.

* **Makefile:** Strumento utilizzato per l'automazione della compilazione e l'esecuzione dei test.

* **Unit Testing:** Suite di test scritta su misura per garantire la correttezza algoritmica, la gestione dei casi limite (edge-case) e l'integrità della struttura (in particolar modo per validare la delicata sincronizzazione tra l'Heap e la mappa Hash).

* **Valgrind:** Utilizzato intensivamente durante tutto lo sviluppo per garantire la totale assenza di memory leak.

##  Struttura del Progetto

```
├── src/            # Codice sorgente per le strutture dati e gli algoritmi
├── include/        # File header che definiscono l'API pubblica
├── tests/          # Test unitari per ciascun modulo
├── data/           # Dataset utilizzati per le simulazioni (es. tasks.csv)
├── Makefile        # Istruzioni di compilazione
└── README.md

```

##  Come Compilare ed Eseguire

Clona la repository e utilizza il `Makefile` fornito per compilare il progetto ed eseguire i test.

```
# Clona la repository
git clone https://github.com/TuoUsername/TuoNomeRepository.git
cd TuoNomeRepository

# Compila il progetto
make

# Esegui la suite di test unitari
make test

# Pulisci i file di build
make clean

```
