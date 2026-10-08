# Laboratorio per il corso di Algoritmi e Strutture Dati: regole d'esame, indicazioni generali e suggerimenti, consegne per gli esercizi

# Regole d'esame


## Studenti e studentesse di anni precedenti il 2024/2025

Gli studenti e le studentesse iscritti/e al secondo anno in un anno accademico precedente il 2024/2025 **possono** svolgere tutti gli esercizi di laboratorio interamente in C (come indicato nella presente specifica), oppure i primi due esercizi in C e gli ultimi due in Java.

## Studenti e studentesse con Algoritmi non di 9 CFU

Gli studenti e le studentesse che hanno nel piano di studi l'insegnamento di Algoritmi con un numero di CFU **differente da 9** sono pregati di contattare il docente al più presto, al fine di concordare un programma d'esame commisurato ai CFU.

## Validità del progetto di laboratorio

Le specifiche per il progetto di laboratorio descritte in questo documento resteranno valide fino all'ultimo appello relativo al corrente anno accademico **(vale a dire, quella di settembre 2026)** e non oltre! Gli appelli delle sessioni successive a quella dovranno essere sostenuti sulla base delle specifiche che verranno descritte nella prossima edizione del laboratorio di algoritmi.

## Gruppi di laboratorio e turni

Il progetto di laboratorio può essere svolto individualmente o in gruppo (al più 3 persone). **I membri di uno stesso gruppo devono appartenere tutti allo stesso turno di laboratorio**. Un progetto di laboratorio eseguito da un gruppo costituito da membri appartenenti a turni diversi sarà annullato (e ai singoli membri sarà richiesto di rifarlo in gruppi regolarmente costituiti).

Uno studente o una studentessa, assegnato/a al Turno X può spostarsi al Turno Y, **a patto che trovi un/a collega del turno Y che accetta di spostarsi al turno X**. La richiesta di spostamento deve essere inoltrata via email a entrambi i docenti di laboratorio dei turni coinvolti, da parte di una persona che intende effettuare lo scambio, mettendo in copia la persona disposta allo scambio inverso. Lo scambio si intende effettuato solo a seguito di esplicita autorizzazione (via email) da parte dei docenti.

E' possibile effettuare un solo spostamento di turno durante uno stesso anno accademico. I docenti si riservano di respingere le richieste di spostamento che non dovessero pervenire con **congruo anticipo (min. 1 mese prima)** rispetto alla data dello scritto che si intende sostenere.

## Algoritmo di esame

Come specificato nella descrizione ufficiale dell'insegnamento (https://laurea.informatica.unito.it/do/corsi.pl/Show?_id=iw3r), l'esame di _Algoritmi e Strutture Dati_ consiste in una prova scritta, somministrata mediante la piattaforma Esami, ed in una seguente discussione orale del progetto di laboratorio.

**Per poter sostenere lo scritto,** tutti i membri di un gruppo di laboratorio dovranno sottoporre il codice del progetto di laboratorio su tutti i correttori automatici messi a disposizione sulla pagina Moodle del Laboratorio di ASD, superandone **tutti i test.** Con un laboratorio il cui codice non dovesse superare qualche test (anche solo uno per un unico esercizio), non sarà possibile sostenere lo scritto. Stessa cosa in caso in cui mancasse la consegna di anche un solo esercizio, anche se altri membri del gruppo l'avessero consegnato. Inoltre, il progetto di laboratorio dovrà essere stato consegnato mediante GitLab (vedi sotto), cioè il repository del progetto deve essere stato condiviso con il docente di laboratorio interessato, e deve essere completo senza che vengano effettuati ulteriori commit dopo la data della prova scritta.

Il superamento dello scritto permette di accedere alle prove orali **nella medesima sessione della prova scritta superata** (si ricorda che le sessioni sono gennaio-febbraio 2026, giugno-luglio 2026, settembre 2026). Si noti che per quelle sessioni per cui sono previsti due appelli esisteranno due possibilità per la sostenere la prova orale (primo o secondo appello della sessione); per le sessioni in cui è previsto un solo appello, la prova orale deve essere effettuata necessariamente in quell'appello. Nel caso in cui l'orale non venga superato entro i termini della sessione, lo scritto dovrà essere ripetuto. **La prova orale non si tiene nella data e ora ufficiale su esse3**, invece lo studente dovrà prenotarsi su moodle in un'attività apposita scegliendo una data e ora tra quelle proposte. L'attività con le date e ore sarà resa visibile solo una volta pubblicati i risultati dello scritto su esse3. 

Durante la prova orale, sarà facoltà del docente chiedere di eseguire gli algoritmi implementati su dati ulteriori, forniti dal docente stesso. Ugualmente, sarà facoltà del docente chiedere cambiamenti nel codice durante l'esame, per esempio per l'inclusione di ulteriori unit test o per la correzione di eventuali piccoli problemi di implementazione individuati durante la correzione. Al progetto non sarà comunque assegnato preventivamente un voto, ma esso costituirà la base per una discussione orale. In tale discussione la/il candidata/o dovrà dimostrare di conoscere sia gli aspetti teorici della materia, sia il codice consegnato.

Il voto finale sarà la media pesata dei voti ottenuti nelle due prove scritta ed orale [in base ai crediti associati alle parti di teoria (6 CFU) e di laboratorio (3 CFU), nella media lo scritto peserà 6 e l'orale 3], valutate in 30+1 esimi, essendo comunque necessario il raggiungimento della sufficienza in entrambe le prove.

### Esempio (caso di una sessione con 2 appelli):

- la studentessa/lo studente X intende sostenere la prova scritta nel primo appello di una sessione con 2 appelli;
- la studentessa/lo studente X deve assicurarsi che il progetto su GitLab, alla data della prova scritta che intende sostenere (in questo esempio, quella del primo appello della sessione), sia aggiornato alla versione che vuole presentare al docente di laboratorio;
- la studentessa/lo studente X deve sottoporre il codice del progetto su tutti e 4 i correttori automatici messi a disposizione nella pagina Moodle del Laboratorio di ASD, assicurandosi che passi tutti i test;
- se la studentessa/lo studente X supera la prova scritta nel primo appello della sessione, deve (pena la perdita del voto ottenuto nella prova scritta):
    - iscriversi a uno dei due appelli orali della stessa sessione,
    - prenotarsi su Moodle in uno degli slot messi a disposizione dal docente del turno di appartenenza,
    - sostenere l'orale nello slot temporale prenotato.

Studentesse/studenti diversi, appartenenti allo stesso gruppo di laboratorio, possono sostenere la prova **scritta** nello stesso appello o in appelli diversi. Se studentesse/studenti diversi, appartenenti allo stesso gruppo, superano la prova scritta nello stesso appello, **devono** sostenere l' **orale** nello stesso appello orale. Se studentesse/studenti diversi, appartenenti allo stesso gruppo, superano la prova scritta in appelli diversi, **possono** sostenere l'**orale** in appelli diversi.

Ad esempio, si consideri un gruppo di laboratorio costituito dalle studentesse/dagli studenti X, Y e Z, e si supponga che i soli X e Y sostengano la prova scritta nel primo appello di una sessione con due appelli, X con successo, mentre Y con esito insufficiente. Devono essere rispettate le seguenti condizioni:

- Alla data della prova scritta del primo appello della sessione, il progetto di laboratorio del gruppo su GitLab deve essere aggiornato alla versione che si intende presentare, e deve superare tutti i test automatici su Moodle.
- Il solo studente X deve sostenere la prova orale nella stessa sessione in cui ha superato lo scritto,  procedendo come indicato nell'esempio riportato sopra, mentre Y e Z sosterranno la discussione quando avranno superato la prova scritta.
- Supponiamo che Y e Z superino la prova scritta nell'appello di una sessione con un solo appello: essi dovranno sostenere la prova orale in quello stesso appello.
- Gli studenti Y e Z dovranno, di norma, presentare la stessa versione del progetto di laboratorio che ha presentato lo studente X; eventuali modifiche al laboratorio successive alla discussione di X dovranno cioè essere di modesta entità, debitamente documentate (i.e., il log delle modifiche dovrà comparire su GitLab) e motivate.

# Indicazioni generali e suggerimenti

## Uso di GitLab

Durante la scrittura del codice è richiesto di usare in modo appropriato il sistema di versioning GitLab. Questa richiesta implica quanto segue:

- Il progetto di laboratorio va inizializzato "clonando" il repository del laboratorio come descritto nel file `Git.md`.
- Come è prassi nei moderni ambienti di sviluppo, è richiesto di effettuare commit frequenti, con un nome significativo. L'ideale è un commit per ogni blocco di lavoro terminato (es. creazione e test di una nuova funzione, soluzione di un baco, creazione di una nuova interfaccia, ...). Meglio ancora se si usano branch e merge per gestire sessioni di lavoro più ampie.
- Ogni membro del gruppo dovrebbe effettuare il commit delle modifiche che lo hanno visto come principale sviluppatore, partecipando quindi attivamente ai commit del repository in misura più o meno bilanciata.
- Al termine del lavoro si dovrà consegnare l'intero repository (dandone accesso al docente di riferimento del turno).

Il file `Git.md` contiene un esempio di come usare Git per lo sviluppo degli esercizi proposti per questo laboratorio.

---

**Nota importante**: Su GitLab dovrà essere caricato solamente il codice sorgente, in particolare nessun file dati dovrà essere oggetto di commit!

---

## Linguaggio in cui sviluppare il laboratorio

L'intera implementazione del laboratorio deve essere realizzata nel linguaggio C.

Come indicato sotto, alcuni esercizi chiedono di implementare **codice generico**. Con "codice generico" si intende codice che deve poter essere eseguito con tipi di dato non noti a tempo di compilazione.

**Suggerimento per la realizzazione di codice generico in C**: Nel caso del C, è necessario capire come meglio approssimare l'idea di codice generico utilizzando quanto permesso dal linguaggio. Un approccio comune è far sì che le funzioni e le procedure presenti nel codice prendano in input puntatori a `void` e utilizzino qualche funzione fornita dall'utente per accedere alle componenti necessarie (uso di puntatori a funzione).

## Uso di librerie esterne e/o native del linguaggio scelto

È vietato l'uso di strutture dati native del linguaggio scelto o offerte da librerie esterne, quando la loro realizzazione è richiesta da uno degli esercizi proposti.

È, invece, possibile l'uso di strutture dati native del linguaggio o offerte da librerie esterne, se la loro realizzazione non è richiesta da uno degli esercizi proposti.

**Esempio:** l'uso di una libreria C che implementa array dinamici è consentito, solo se nessun esercizio chiede la realizzazione di un array dinamico.

## Relazione sugli esercizi

La relazione, per quegli esercizi che la richiedono, deve essere inserita in formato _MarkDown_ nel file README.md del progetto, divenendo così parte integrante della documentazione.

## Unit Testing

Come indicato esplicitamente nei testi degli esercizi, il progetto di laboratorio comprende obbligatoriamente la definizione di opportune suite di unit test.

È obbligatorio implementare unit test completi per tutte le funzioni di libreria sviluppate, escluse le funzioni dedicate all'interazione con l'utente e I/O su file, ma incluse le funzioni di utilità che si decidesse di aggiungere a quelle esplicitamente richieste dall'esercizio. Gli unit test rappresentano un'area in cui l'AI generativa può essere particolarmente utile per accelerare lo sviluppo e garantire una copertura esaustiva del codice.

Tuttavia, si rammenta che il focus del laboratorio rimane l'implementazione di strutture dati e algoritmi. Gli studenti dovranno dimostrare di aver compreso il senso degli unit test e di saper realizzare suite di test che coprano i casi più comuni e i casi limite.

## Qualità dell'implementazione

È parte del mandato degli esercizi la realizzazione di codice di buona qualità.

Per "buona qualità" intendiamo codice ben organizzato, ben modularizzato, ben commentato e ben testato.

**Alcuni suggerimenti:**

- **Importante**: Gli esercizi richiedono (fra le altre cose) di sviluppare codice generico. Nello sviluppare questa parte, si deve assumere di stare sviluppando una libreria generica intesa come fondamento di futuri programmi. Non è pertanto lecito fare assunzioni semplificative; in generale, l'implementazione della libreria generica deve restare separata e non deve essere influenzata in alcun modo dagli usi di essa eventualmente richiesti negli esercizi (ad esempio, se un esercizio dovesse richiedere l'implementazione della struttura dati grafo e quello stesso o un altro esercizio dovesse richiedere l'implementazione, a partire da tale struttura dati, di un algoritmo per il calcolo delle componenti connesse di un grafo, l'implementazione della struttura dati dovrebbe essere separata dall'algoritmo per il calcolo delle componenti connesse e *non* dovrebbe contenere elementi – variabili, procedure, funzioni, definizioni di tipo, ecc. – eventualmente utili a tale algoritmo, ma non essenziali alla struttura dati; analogamente, se un esercizio dovesse richiedere di operare su grafi con nodi di tipo stringa, l'implementazione della struttura dati grafo dovrebbe restare generica e non potrebbe quindi assumere per i nodi il solo tipo stringa).
- verificare che il codice sia suddiviso correttamente in moduli distinti;
- aggiungere un commento, prima di una definizione, che spieghi il funzionamento dell'oggetto definito, meglio se in formato [doxygen](https://www.doxygen.nl). Evitare quando possibile di commentare direttamente il codice interno alle funzioni/procedure implementate (se il codice è ben scritto, tali commenti in genere non servono);
- la lunghezza di una funzione/procedura è in genere un campanello di allarme: se essa cresce troppo, probabilmente è necessario rifattorizzare il codice spezzando la funzione in più parti. In linea di massima si può consigliare di intervenire quando la funzione cresce sopra le 30 righe (considerando anche commenti e spazi bianchi);
- sono accettabili commenti in italiano, sebbene siano preferibili in inglese;
- tutti i nomi (es., nomi di variabili, di funzioni, di tipi, ecc.) *devono* essere significativi e in inglese;
- il codice deve essere correttamente indentato; impostare l'indentazione a 2 o 4 caratteri e impostare l'editor in modo che inserisca "soft tabs" (cioè, deve inserire il numero corretto di spazi invece che un carattere di tabulazione);
- per dare i nomi agli identificatori, seguire le convenzioni in uso per il linguaggio C:
  - macro e costanti sono tutti in maiuscolo e in formato snake case (es. THE\_MACRO, THE\_CONSTANT); i nomi di tipo (e.g.  struct, typedefs, enums, ...) iniziano con una lettera maiuscola e proseguono in camel case (e.g., TheType, TheStruct); i nomi di funzione iniziano con una lettera minuscola e proseguono in snake case (e.g., the\_function());
- i file vanno salvati in formato UTF-8.

# Consegne per gli esercizi

Come detto sopra, in sede di discussione d'esame, sarà facoltà del docente chiedere di eseguire gli algoritmi implementati su dati forniti dal docente stesso. Nel caso questi dati siano memorizzati su file, questi saranno della medesima struttura dei dataset forniti e descritti nel testo dell'esercizio. I codici sviluppati dovranno consentire un rapido e semplice adattamento agli input forniti: ad esempio, **una buona implementazione consentirà di inserire in input il nome del file su cui eseguire il test**, mentre una peggiore richiederà di modificare il codice sorgente e una successiva compilazione a fronte della sola modifica del nome del file contenente il dataset.

## Esercizio 1 - Algoritmo di ordinamento ibrido QuickSort-SelectionSort

Implementare un algoritmo di ordinamento **ibrido** che combini QuickSort e SelectionSort in base alla dimensione dell'array da ordinare. L'algoritmo deve funzionare nel seguente modo:

- Per array di dimensione maggiore o uguale a una soglia `k`, utilizzare QuickSort.
- Per array di dimensione minore di `k`, utilizzare SelectionSort.

L'ipotesi da verificare è se SelectionSort, pur avendo complessità O(n²), possa risultare più efficiente di QuickSort su array molto piccoli a causa del minor overhead nelle operazioni elementari. Sarà compito vostro determinare sperimentalmente se questa ipotesi è corretta e identificare eventuali valori ottimali della soglia.

### Specifiche dell'implementazione:

1. **QuickSort**: implementare una versione robusta che sia efficiente su tutti i casi di test presenti nel dataset (descritto sotto). La scelta della strategia di partizionamento e del pivot è lasciata agli studenti, che dovranno valutare le prestazioni sui dati reali.
2. **SelectionSort**: implementare la versione classica O(n²).
3. **Algoritmo ibrido**: deve rispettare la soglia `k` e passare automaticamente da un algoritmo all'altro durante la ricorsione.

La libreria deve supportare l'ordinamento di array di diversi tipi di dato tramite funzioni di comparazione, rispettando la seguente definizione:

```c
void hybridsort(void *base,
                size_t nitems,
                size_t size,
                size_t k,
                int (*compar)(const void *, const void *));
```

Interpretare i parametri della funzione `hybridsort` considerando la richiesta per una implementazione generica.

### Unit Testing

Implementare gli unit test per la libreria secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

Gli unit test devono coprire:
- Correttezza di eventuali funzioni ausiliarie sviluppate;
- Correttezza dell'ordinamento per tutti i tipi di dato;
- Comportamento con array vuoti e di dimensione piccola;
- Diversi valori della soglia `k`;
- Casi limite, ad esempio, array già ordinati, ordinati inversamente, con elementi duplicati.

### Uso della libreria di ordinamento implementata

#### Dataset

Il file `records.bin.gz` che potete trovare (compresso) all'indirizzo:

> [https://datacloud.di.unito.it/index.php/s/3c9H8ZAFqQWEBcf](https://datacloud.di.unito.it/index.php/s/3c9H8ZAFqQWEBcf)

contiene 20 milioni di record da ordinare in formato binario compresso.

**Formato del file binario:**
Il file compresso deve essere estratto prima dell'uso. Una volta decompresso, `records.bin` è strutturato come una sequenza di record, ognuno dei quali occupa esattamente 36 bytes:
- **Byte 0-7**: `id` (intero senza segno a 64 bit, little-endian)  
- **Byte 8-11**: `field1` (float a 32 bit, IEEE 754, little-endian)
- **Byte 12-19**: `field2` (intero con segno a 64 bit, little-endian)
- **Byte 20-35**: `field3` (stringa di 16 caratteri, padding con '\0' se necessario)

Il campo `field3` contiene parole estratte dalla Divina Commedia (massimo 15 caratteri utili + terminatore). I campi sono generati per testare diversi scenari di ordinamento, inclusi casi che possono portare alcuni algoritmi di ordinamento al caso peggiore.

**Suggerimento:**  Per facilitare la manipolazione del file binario, si consiglia di implementare una libreria di supporto con funzioni come:

```c
int read_record(FILE *file, Record *record);
int write_record(FILE *file, const Record *record);
int load_records_from_file(FILE *file, Record **records, size_t *count);
int save_records_to_file(FILE *file, const Record *records, size_t count);
void print_record(const Record *record);
```

#### Programma principale

Usando l'algoritmo implementato precedentemente, si realizzi la seguente funzione per ordinare i *record* contenuti nel file `records.bin` in ordine non decrescente secondo i valori contenuti nei campi specificati.

```c
void sort_records(FILE *infile, FILE *outfile, size_t field, size_t k);
```

**Parametri:**
- `infile`: il file binario contenente i record da ordinare.
- `outfile`: il file binario nel quale salvare i record ordinati (deve essere diverso da `infile`).
- `field`: può valere 1, 2, 3 o 4 e indica quale campo deve essere usato per ordinare i record:
  - `1`: ordina per `id` (intero senza segno a 64 bit);
  - `2`: ordina per `field1` (float);
  - `3`: ordina per `field2` (intero con segno a 64 bit);
  - `4`: ordina per `field3` (stringa, ordine lessicografico).
- `k`: soglia per l'algoritmo ibrido:
  - se `k=0`: l'intero array sarà ordinato solo con QuickSort;
  - se `k > numero_totale_record`: l'intero array sarà ordinato solo con SelectionSort;
  - altrimenti: usa QuickSort per sottoinsiemi ≥ k, SelectionSort per sottoinsiemi < k.

### Analisi sperimentale

Si misurino i tempi di risposta dell'algoritmo ibrido per ciascuno dei quattro campi che si possono usare come chiave di ordinamento, al variare di `k`.

**Valori di k da testare**: 0, 10, 50, 100, 500, 1000, 5000, 10000, 1000000

**Gestione della memoria**: L'implementazione deve gestire correttamente l'allocazione e la deallocazione della memoria, evitando memory leak e sprechi di memoria. Si consiglia di testare l'applicazione con strumenti come Valgrind.

Si produca una breve relazione (in formato Markdown nel file `README.md`) in cui si riportano:

1. **Tabelle dei tempi**: tempi di esecuzione per ogni combinazione di campo e valore di k.
2. **Analisi critica**:
   - I risultati corrispondono alle aspettative teoriche?
   - Esiste un valore ottimale di k? Se sì, quale e perché?
   - L'approccio ibrido offre vantaggi rispetto agli algoritmi puri?
   - Ci sono differenze significative tra i diversi tipi di campi?

**Vincoli temporali**: Nel caso l'ordinamento non finisca entro 5 minuti, interrompere l'esecuzione e riportare un fallimento dell'operazione nella relazione. Tempi di esecuzione eccessivi possono indicare che il valore di k è troppo elevato o che ci sono problemi nell'implementazione del QuickSort, ad esempio, degenerazione verso il caso peggiore O(n²). In quest'ultimo caso, riflettere sulla strategia di scelta del pivot per sistemare il problema.

**Si ricorda che i file `records.bin.gz`, `records.bin` (e i file compilati) NON DEVONO ESSERE OGGETTO DI COMMIT SU GIT!**

### Condizioni per la consegna

- Creare una sottocartella chiamata `ex1` all'interno del repository.
- La consegna deve obbligatoriamente contenere un `Makefile` che con il comando `make all` produca all'interno di `ex1/bin` due file eseguibili chiamati `main_ex1` e `test_ex1`.
- Se avete usato librerie esterne (come Unity per i test) includete anche queste per consentire la corretta compilazione.
- L'eseguibile `test_ex1` non deve richiedere parametri e deve eseguire tutti gli unit test automatizzati.
- L'eseguibile `main_ex1` deve ricevere come parametri:

```bash
$ ./bin/main_ex1 <input_file> <output_file> <field> <k>
```

**Esempio di utilizzo:**
```bash
$ ./bin/main_ex1 records.bin sorted_output.bin 1 50
```

Questo comando ordinerà i record del file `records.bin` secondo il campo `id` (field=1) usando l'algoritmo ibrido con soglia k=50, salvando il risultato in `sorted_output.bin`.

## Esercizio 2 - Tavole hash (con concatenamento)

Si implementi, avvalendosi del supporto di un sistema basato su un Large Language Model, quale, ad esempio, ChatGPT (si veda sotto), una libreria generica che realizza la struttura dati *tavola hash (con concatenamento)* in grado di ospitare un insieme di coppie {<chiave_1,valore_1>,...,<chiave_n,valore_n>}.

La tavola hash deve accettare chiavi e valori di tipi generici (tutte le chiavi hanno uno stesso tipo, tutti i valori hanno uno stesso tipo, ma chiavi e valori possono avere tipi fra loro differenti).

La struttura dati deve offrire almeno le seguenti funzionalità (ricavare il significato delle varie funzioni e procedure e dei loro parametri a partire dai loro prototipi e da quanto studiato nella parte di teoria del corso):

```
HashTable* hash_table_create(int (*f1)(const void*,const void*), unsigned long (*f2)(const void*));
void hash_table_put(HashTable*, const void*, const void*);
void* hash_table_get(const HashTable*, const void*);
int hash_table_contains_key(const HashTable*, const void*);
void hash_table_remove(HashTable*, const void*);
int hash_table_size(const HashTable*);
void** hash_table_keyset(const HashTable*);
void hash_table_free(HashTable*);
```

### Unit Testing

Implementare avvalendosi del supporto di un sistema basato su un Large Language Model (LLM), quale, ad esempio, ChatGPT (si veda sotto), gli unit-test degli algoritmi secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Uso delle funzioni implementate

All'indirizzo:

> [https://datacloud.di.unito.it/index.php/s/Ti4Mz7j4Xtjn3Db](https://datacloud.di.unito.it/index.php/s/Ti4Mz7j4Xtjn3Db)

potete trovare un file (`iliade.txt`) contenente l'Iliade di Omero in inglese.

Avvalendosi di un sistema basato su LLM, scrivere un programma che utilizza l'hash table implementata per calcolare la parola di lunghezza almeno pari ad un valore minimo dato che sia più frequente nel file di testo dato.

### Uso di sistema basato su un Large Language Model

Si richiede che per implementare quanto richiesto dal presente esercizio ci si avvalga del supporto di un sistema basato su un Large Language Model, quale, ad esempio, ChatGPT.

È possibile che il processo di sviluppo risulti iterativo, comportando varie interazioni con il sistema LLM.

**ATTENZIONE**: I Large Language Models spesso forniscono implementazioni che non rispettano le specifiche dell'esercizio, in particolare ignorando la complessità computazionale richiesta per le strutture dati. **Le consegne che non rispettano la complessità computazionale specificata saranno considerate completamente invalide**. È responsabilità del gruppo studiare attentamente il codice generato, verificarne la correttezza algoritmica e assicurarsi che rispetti i vincoli richiesti.

Serve quindi assumere un ruolo critico e di supervisione nel processo, non limitandosi ad accettare passivamente l'output del sistema LLM, ma analizzandolo, validandolo e, se necessario, richiedendo modifiche specifiche per garantire la conformità ai requisiti.

Si documenti, in una relazione (README.md su git), il suddetto processo di sviluppo nei suoi aspetti principali (prompt iniziale, output prodotto dal sistema, analisi critica dell'output, identificazione di eventuali problemi di complessità, raffinamento del prompt, iterazioni successive, ecc.) e si riportino alcune considerazioni generali sull'intero processo, con particolare attenzione alle sfide incontrate nel garantire la correttezza algoritmica.

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex2` all'interno del repository.
- La consegna deve obbligatoriamente contenere un `Makefile`. Questo file con il comando `make all` deve produrre all'interno di `ex2/bin` due file eseguibili chiamati `main_ex2` e `test_ex2`. Se avete usato librerie esterne (come Unity) includete anche queste per consentire la corretta compilazione.
- L'eseguibile `test_ex2` non deve richiedere nessun parametro e deve eseguire tutti gli unit test automatizzati prodotti.
- L'eseguibile `main_ex2` deve ricevere come parametri il percorso del file di testo da usare e la lunghezza minima delle parole da considerare. Per esempio:

```
$ ./main_ex2 /tmp/data/iliade.txt 6
```

## Esercizio 3 - Heap ternario

**TBD TBD TBD**

### Unit Testing

Implementare gli unit-test degli algoritmi secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Uso delle funzioni implementate

**TBD TBD TBD**

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex3` all'interno del repository.
- La consegna deve obbligatoriamente contenere un `Makefile`. Questo file con il comando `make all` deve produrre all'interno di `ex3/bin` due file eseguibili chiamati `main_ex3` e `test_ex3`. Se avete usato librerie esterne (come Unity) includete anche queste per consentire la corretta compilazione.
- L'eseguibile `test_ex3` non deve richiedere nessun parametro e deve eseguire tutti gli unit test automatizzati prodotti.
- L'eseguibile `main_ex3` deve ricevere come parametri il percorso del dizionario da usare come riferimento e il file da correggere. Per esempio:

```
$ ./main_ex3 /tmp/data/dictionary.txt /tmp/data/correctme.txt
```


## Esercizio 4 - Grafi sparsi e Visita in Ampiezza

Si implementi una libreria che realizza la struttura dati *Grafo* in modo che sia ottimale per dati sparsi
(**attenzione**: le scelte implementative che farete dovranno essere giustificate in relazione alle nozioni presentate
durante le lezioni in aula).

È richiesto che l'implementazione sfrutti la Tavola Hash implementata nell'Esercizio 2.

L'implementazione deve essere generica sia per quanto riguarda il tipo dei nodi, sia per quanto riguarda le etichette
degli archi, implementando le funzioni riportate nel seguente header file (con requisiti minimi di complessità; dove _N_ può indicare il numero di nodi o il numero di archi, a seconda del contesto):

### graph.h

#### Strutture Dati

```c
typedef struct graph *Graph;

typedef struct edge {
    void* source;   // nodo d'origine
    void* dest;     // nodo di destinazione
    void* label;    // etichetta dell'arco
} Edge;
```
---
#### Creazione e Configurazione

```c
Graph graph_create(int labelled,
                  int directed,
                  int (*compare)(const void*, const void*),
                  unsigned long (*hash)(const void*));
```
Crea un grafo vuoto, etichettato se `labelled == 1` e diretto se `directed == 1`. Le funzioni `compare` e `hash` sono necessarie per la costruzione della tavola hash che deve essere usata dalla libreria.  
**Complessità**: O(1)

```c
int graph_is_directed(const Graph gr);
```
Dice se il grafo è diretto o meno.  
**Complessità**: O(1)

```c
int graph_is_labelled(const Graph gr);
```
Dice se il grafo è etichettato o meno.  
**Complessità**: O(1)

---
#### Gestione Nodi

```c
int graph_add_node(Graph gr, const void* node);
```
Aggiunge un nodo al grafo.  
**Complessità**: O(1)

```c
int graph_contains_node(const Graph gr, const void* node);
```
Controlla se un nodo è presente nel grafo.  
**Complessità**: O(1)

```c
int graph_remove_node(Graph gr, const void* node);
```
Rimuove un nodo dal grafo.  
**Complessità**: O(N)

```c
int graph_num_nodes(const Graph gr);
```
Restituisce il numero di nodi nel grafo.  
**Complessità**: O(1)

```c
void** graph_get_nodes(const Graph gr);
```
Recupera tutti i nodi del grafo.  
**Complessità**: O(N)

---
#### Gestione Archi

```c
int graph_add_edge(Graph gr, const void* node1, const void* node2, const void* label);
```
Aggiunge un arco dati gli estremi e l'etichetta.  
**Complessità**: O(1) (*)

```c
int graph_contains_edge(const Graph gr, const void* node1, const void* node2);
```
Controlla se un arco è presente nel grafo.  
**Complessità**: O(1) (*)

```c
int graph_remove_edge(Graph gr, const void* node1, const void* node2);
```
Rimuove un arco dal grafo.  
**Complessità**: O(1) (*)

```c
int graph_num_edges(const Graph gr);
```
Restituisce il numero di archi nel grafo.  
**Complessità**: O(N)

```c
Edge** graph_get_edges(const Graph gr);
```
Recupera tutti gli archi del grafo.  
**Complessità**: O(N)

```c
void* graph_get_label(const Graph gr, const void* node1, const void* node2);
```
Recupera l'etichetta di un arco.  
**Complessità**: O(1) (*)

---
#### Adiacenza

```c
void** graph_get_neighbours(const Graph gr, const void* node);
```
Recupera i nodi adiacenti a un dato nodo.  
**Complessità**: O(1) (*)

```c
int graph_num_neighbours(const Graph gr, const void* node);
```
Recupera il numero di nodi adiacenti a un dato nodo.  
**Complessità**: O(1)

---
#### Distruzione

```c
void graph_free(Graph gr);
```
Libera la memoria allocata per il grafo.

---

**Nota**: Le complessità contrassegnate con (*) assumono un'implementazione efficiente della tavola hash sottostante, e quando il grafo è veramente sparso, assumendo che l'operazione venga effettuata su un nodo la cui lista di adiacenza ha una lunghezza in O(1).

La struttura ```struct graph``` deve essere decisa prendendo in considerazione la richiesta di usare la Tabella Hash dell'esercizio precedente.

*Suggerimento*:  un grafo non diretto può essere rappresentato usando un'implementazione per grafi diretti modificata
per garantire che, per ogni arco *(a,b)* etichettato *w*, presente nel grafo, sia presente nel grafo anche l'arco *(b,a)*
etichettato *w*. Ovviamente, il grafo dovrà mantenere l'informazione che specifica se esso è un grafo diretto o non diretto.
Similmente, un grafo non etichettato può essere rappresentato usando l'implementazione per grafi etichettati modificata per garantire
che le etichette siano sempre `null` (che invece non devono mai essere `null` per i grafi etichettati).

### Unit Testing

Implementare gli unit-test degli algoritmi secondo le indicazioni suggerite nel documento [Unit Testing](UnitTesting.md).

### Uso della libreria che implementa la struttura dati Grafo

Si implementi l'algoritmo di visita in ampiezza secondo il seguente prototipo di funzione

```c
void** breadth_first_visit(Graph gr,
                          void* start,
                          int (*compare)(const void*, const void*),
                          unsigned long (*hash)(const void*));
```
Start è il nodo di partenza da cui cominciare la visita, la funzione restituisce l'array dei nodi nell'ordine di visita. Eventualmente, la funzione restituisce null se il nodo start non è presente nel grafo. L'implementazione dell'algoritmo di visita in ampiezza dovrà utilizzare la libreria sui grafi appena implementata.

L'algoritmo dovrà poi essere usato con i dati contenuti nel file `italian_dist_graph.csv`, che potete recuperare all'indirizzo:

> [https://datacloud.di.unito.it/index.php/s/FqneW99EGWLSRpY](https://datacloud.di.unito.it/index.php/s/FqneW99EGWLSRpY)

Tale file contiene le distanze in metri tra varie località italiane e una frazione delle località a loro più vicine. Il formato è un CSV standard: i campi sono separati da virgole; i record sono separati dal carattere di fine riga (`\n`).

Ogni record contiene i seguenti dati:

- `place1`: (tipo stringa) nome della località "sorgente" (la stringa può contenere spazi ma non può contenere virgole);
- `place2`: (tipo stringa) nome della località "destinazione" (la stringa può contenere spazi ma non può contenere virgole);
- `distance`: (tipo float) distanza in metri tra le due località.

**Note:**

- Potete interpretare le informazioni presenti nelle righe del file come archi **non diretti**.
- Il file è stato creato a partire da un dataset poco accurato. I dati riportati contengono inesattezze e imprecisioni.

**Si ricorda che il file `italian_dist_graph.csv` (e i file compilati) NON DEVONO ESSERE OGGETTO DI COMMIT SU GIT!**

### Condizioni per la consegna:

- Creare una sottocartella chiamata `ex4` all'interno del repository, che conterrà i file relativi a questo esercizio.
- Includete nella consegna anche un `Makefile` che con il comando `make all` deve produrre all'interno di `ex4/bin` due file eseguibili chiamati `main_ex4` e `test_ex4`. Se avete usato librerie esterne (come Unity) includete anche queste per consentire la corretta compilazione.
- L'eseguibile `test_ex4` non deve richiedere nessun parametro e deve eseguire tutti gli unit test automatizzati prodotti.
- L'eseguibile `main_ex4` deve ricevere come parametri il percorso del file `italian_dist_graph.csv`, il nome della città di partenza e il nome di un file di output, e salvare in quest'ultimo i nomi delle località visitate durante una visita in ampiezza del grafo, un nome per riga, partendo da un nodo di partenza specificato. I nomi dei file non devono essere hardcoded, ma devono essere passati come argomenti da linea di comando.

```
$ ./main_ex4 italian_dist_graph.csv torino output.txt
```

Si documenti brevemente, in una relazione (README.md su git), le scelte implementative effettuate e i risultati e tempi dell'esecuzione dell'algoritmo rispetto a quanto atteso.
