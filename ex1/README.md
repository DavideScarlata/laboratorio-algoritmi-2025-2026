# Esercizio 1 - Algoritmo di ordinamento ibrido QuickSort-SelectionSort

### 1. Scelte Implementative

L'obiettivo dell'esercizio era implementare un algoritmo di ordinamento ibrido che combinasse l'efficienza asintotica del **QuickSort** ($O(n \log n)$) con la semplicità e il basso overhead del **SelectionSort** per input di piccole dimensioni.

#### Strategia Ibrida e QuickSort
L'algoritmo `hybrid_sort` utilizza un approccio ricorsivo:
- Se la dimensione del sotto-array è inferiore a una soglia `k`, viene eseguito il `selection_sort`.
- Altrimenti, si procede con il `quick_sort`.

Per il partizionamento è stato implementato l'algoritmo della **Bandiera Olandese (Dutch National Flag)**. Questa tecnica di partizionamento a 3 vie (elementi minori, uguali e maggiori del pivot) è stata scelta specificamente per la sua robustezza nel gestire dataset con molte chiavi duplicate, evitando il degrado delle prestazioni a $O(n^2)$ tipico del partizionamento standard in questi scenari.

#### Gestione della Memoria e Genericità
L'intera libreria è stata realizzata in C generico (`void *`).
- Poiché il tipo di dato non è noto a priori, lo scambio degli elementi (`swap`) è stato implementato effettuando una **copia byte per byte (byte-wise copy)**. Questo approccio garantisce la corretta manipolazione di qualsiasi struttura dati passata alla libreria, interpretando la memoria grezza come sequenza di `unsigned char`.
- Per la scelta del pivot è stata adottata la strategia **Median-of-Three** (mediana tra primo, centrale e ultimo elemento), che riduce la probabilità di incappare nel caso peggiore su array parzialmente ordinati.

### 2. Unit Testing

Per garantire la correttezza del codice, è stata utilizzata la libreria **Unity**. I test, contenuti in `test_ex1.c`, coprono i seguenti casi:
- **Ordinamento di interi:** array casuali, già ordinati, ordinati inversamente, con duplicati e array vuoti.
- **Ordinamento di Record:** verifica della correttezza dei comparatori per tutti i campi (ID, float, intero, stringa).
- **Soglia K:** verifica che l'algoritmo funzioni correttamente indipendentemente dal valore di `k`.

### 3. Analisi Sperimentale

I test sono stati eseguiti su una macchina dotata delle seguenti specifiche:
- **Processore:** AMD Ryzen 7 5700U (8 core, 16 thread)
- **RAM:** 12 GB
- **Sistema Operativo:** Linux
- **Compilazione:** GCC con flag di ottimizzazione `-O3`.

Il dataset utilizzato (`records.bin`) contiene 20 milioni di record. Di seguito sono riportati i tempi di esecuzione misurati al variare della soglia `k`.

| K | Field 1 (ID) | Field 2 (Float) | Field 3 (Int) | Field 4 (String) |
|---|---|---|---|---|
| **0** (Pure QuickSort) | 7.958576 s | 4.205728 s | 6.877267 s | 4.210703 s |
| **10** | 5.220909 s | 3.397658 s | 6.391088 s | 5.023948 s |
| **50** | 5.193610 s | 4.293417 s | 6.600370 s | 4.929620 s |
| **100** | 5.568923 s | 4.365400 s | 7.147653 s | 6.418194 s |
| **500** | 9.330943 s | 7.367477 s | 10.057785 s | 10.890661 s |
| **1000** | 15.153907 s | 11.765145 s | 15.753580 s | 18.461124 s |
| **5000** | 66.378870 s | 55.955256 s | 73.252056 s | 92.811930 s |
| **10000** | 136.698394 s | 117.776580 s | 153.730711 s | 199.033956 s |
| **1000000** | > 5 min | > 5 min | > 5 min | > 5 min |

### 4. Analisi Critica

Rispondendo ai quesiti posti dalle specifiche del laboratorio:

1.  **Conferma dell'ipotesi ibrida (Small K) per i campi numerici:**
    Per i campi numerici (ID, Float, Int), si osserva un netto miglioramento delle prestazioni introducendo una soglia `k` piccola.
    - Il tempo migliore per l'ordinamento per ID si ottiene con **K compreso tra 10 e 50** (circa 5.2s contro i quasi 8s del QuickSort puro), confermando che per array di piccole dimensioni il SelectionSort è più efficiente grazie al minore overhead rispetto alle chiamate ricorsive.

2.  **Il comportamento con le Stringhe (Field 4):**
    A differenza dei campi numerici, per le stringhe l'approccio ibrido non ha portato a miglioramenti rispetto al QuickSort puro (K=0: 4.21s vs K=10: 5.02s).
    - **Motivazione:** Il confronto tra stringhe (`strncmp`) è un'operazione computazionalmente più costosa rispetto al confronto tra interi o float. SelectionSort esegue un numero di confronti quadratico $O(n^2)$; anche su array piccoli (es. 10-50 elementi), il costo accumulato di questi confronti pesanti supera il risparmio ottenuto evitando le chiamate ricorsive.
    - Tuttavia, il tempo complessivo rimane molto competitivo (circa 4.2s) grazie al partizionamento **Dutch National Flag**: poiché il testo contiene molti duplicati, il QuickSort riesce a raggruppare grandi porzioni di array in tempo lineare, riducendo drasticamente la profondità della ricorsione.

3.  **Degrado Prestazionale (High K):**
    Come previsto teoricamente, valori di `k` elevati (es. > 500) portano a un drastico peggioramento delle performance. Quando `k` cresce, la complessità quadratica $O(k^2)$ del SelectionSort inizia a dominare sul vantaggio algoritmico del QuickSort, portando i tempi a dilatarsi fino al timeout (> 5 minuti) per k molto grandi.

**Conclusione:**
Un valore di **K compreso tra 10 e 50** risulta essere la scelta ottimale per i tipi di dato semplici (interi, float), offrendo il miglior bilanciamento tra overhead ricorsivo e numero di confronti. Per tipi di dato con confronti costosi (come le stringhe), il QuickSort puro (K=0) o un K molto basso rimangono preferibili.