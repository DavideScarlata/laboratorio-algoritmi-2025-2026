# Relazione Esercizio 2: Tavola Hash Generica

## Introduzione
Questo progetto implementa una **Hash Table** (tavola hash) generica in linguaggio C, che utilizza la tecnica del **concatenamento (separate chaining)** per la risoluzione delle collisioni.
L'obiettivo dell'esercizio è fornire una struttura dati flessibile in grado di memorizzare coppie `<chiave, valore>` di tipo arbitrario, gestendo dinamicamente la memoria e garantendo efficienza nelle operazioni di inserimento, ricerca e cancellazione.

## Scelte Implementative

### 1. Risoluzione delle Collisioni: Separate Chaining
Come richiesto dalle specifiche, è stato utilizzato il concatenamento. La struttura interna `HashTable` mantiene un array di puntatori a strutture `Entry`.
* Ogni bucket dell'array funge da testa di una lista concatenata.
* In caso di collisione (due chiavi diverse con lo stesso indice hash), la nuova entry viene aggiunta in testa alla lista corrispondente.
Questa scelta garantisce che il fattore di carico possa superare teoricamente 1, anche se le performance degraderebbero; per questo motivo è stato implementato il ridimensionamento automatico.

### 2. Politica di Resizing: Numeri Primi
Rispetto a un'implementazione standard che raddoppia semplicemente la capacità ($2^n$), nel codice finale è stata introdotta una miglioria significativa: **la capacità della tabella segue una sequenza precalcolata di numeri primi** (`53, 97, 193, ...`).

* **Motivazione:** L'uso di numeri primi come dimensione dell'array riduce drasticamente la probabilità di collisioni sistematiche (clustering) quando la funzione di hash interagisce con pattern nei dati di input.
* **Threshold:** Il resize viene innescato quando il numero di elementi supera il **75%** della capacità attuale (Load Factor > 0.75).

### 3. Genericità e Gestione della Memoria
La libreria è stata progettata per essere agnostica rispetto al tipo di dati:
* Utilizza `void*` sia per le chiavi che per i valori.
* Richiede all'utente di fornire funzioni specifiche per il confronto (`cmp`) e l'hashing (`hash`) delle chiavi.

**Nota importante sulla ownership:**
La Hash Table adotta una politica di **Shallow Copy**. La tabella salva solo i puntatori forniti dall'utente e **non effettua copie profonde** dei dati, né libera la memoria puntata da chiavi e valori quando viene distrutta.
* **Vantaggio:** Maggiore flessibilità e minori overhead (l'utente potrebbe voler memorizzare puntatori a oggetti statici o gestiti altrove).
* **Responsabilità:** È compito del chiamante (come fatto nel `main_ex2.c`) allocare la memoria per le chiavi (es. tramite `strdup`) e liberarla correttamente prima di distruggere la tabella.

---

## Utilizzo di Large Language Models (ChatGPT)

Per lo sviluppo di questo esercizio è stato utilizzato ChatGPT come supporto alla programmazione. Di seguito si riporta il resoconto del processo iterativo e di revisione critica.

**Link alla chat:** [https://chatgpt.com/share/69667250-f274-800b-9e7a-bae54e440172](https://chatgpt.com/share/69667250-f274-800b-9e7a-bae54e440172)

### 1. Generazione Iniziale
Il prompt iniziale richiedeva la generazione di una Hash Table in C che rispettasse l'interfaccia definita nel testo dell'esercizio.
L'LLM ha prodotto una versione funzionante che implementava correttamente:
* Le struct di base (`HashTable`, `Entry`).
* Le firme delle funzioni richieste.
* La logica di base per `put`, `get` e `remove`.

### 2. Analisi Critica e Refactoring
Analizzando il codice generato dall'LLM, sono stati identificati alcuni punti deboli o migliorabili che ho corretto nell'implementazione finale (`src/hash_table.c`):

* **Strategia di Ridimensionamento:**
    * *Output LLM:* Il codice originale eseguiva un semplice raddoppio (`capacity *= 2`).
    * *Intervento:* Ho modificato la logica per utilizzare un array statico di numeri primi (`prime_sizes`). Questo migliora la distribuzione degli elementi nei bucket, specialmente con funzioni di hash semplici come quella usata per le stringhe.

* **Gestione degli Errori e Robustezza:**
    * Ho aggiunto controlli più stringenti sui puntatori `NULL` in ingresso alle funzioni pubbliche per evitare crash (Segmentation Fault).

* **Organizzazione del Codice:**
    * L'LLM tendeva a fornire tutto in un unico blocco o file flat. Ho riorganizzato il progetto separando l'interfaccia (`include/hash_table.h`), l'implementazione (`src/hash_table.c`) e i test, creando un `Makefile` modulare per gestire la compilazione separata e ordinata.

### 3. Unit Testing
Gli unit test (`test/test_ex2.c`) sono stati inizialmente suggeriti dall'LLM ma sono stati ampliati manualmente per coprire casi limite, come:
* Inserimento di chiavi duplicate (aggiornamento del valore).
* Verifica del comportamento dopo una rimozione.
* Verifica della correttezza delle chiavi restituite da `hash_table_keyset`.

