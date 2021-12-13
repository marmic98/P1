In nprimiV4.c è stata usat ala funzione sqrt() la quale calcola la radice quadrata
Questo per ridurre l'intervallo dei numeri da esaminare per decretare la primalità del nyumero esaminato.
Poichè ci si avvale della funzione sqrt() è stato necessario includere l'intestazione della libreria math.h indicandolo in fase di compilazione
gcc -o np nprimiV4.c -lm dove -lm linka la libreria math.h
