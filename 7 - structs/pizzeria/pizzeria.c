#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define NPIZZE 3
#define MAXLENSTR 30

typedef struct Pizza{
    char* nome;
    char* farina;
    char* cottura;
    char* ingredienti;
    double prezzo;
}Pizza;

typedef struct Ordine{
    int antipasto;
    Pizza** pizza;
    int numPizze;
    int bibita;
    double conto;
}Ordine;

void* xrealloc(void* p, size_t size){
    p = realloc(p, size);
    if (p == NULL){
        printf("Allocation of %lu bytes failed", size);
        exit(-1);
    }
    return p;
}

void* xmalloc(size_t size){
    void* p = malloc(size);
    if (p == NULL){
        printf("Allocation of %lu bytes failed", size);
        exit(-1);
    }
    return p;
}

void readLine(char* s, int len){
    fgets(s, len, stdin);
    int newLen = strlen(s);
    if (s[newLen - 1] == '\n')
        s[newLen - 1] = '\0';
}

char* readString(int len){
    char* s = xmalloc(len);
    readLine(s, len);
    int newLen = strlen(s);
    s = xrealloc(s, newLen);
    return s;
}


Pizza** menuPizze; //alloc globale perchè sennò dovevo poartarla per parametro everywhere

void printPizze(Pizza** pizze, int num){
    for(int i = 0; i < num; i++){
        printf("Nome: %s\nIngredienti: %s\nCottura: %s\nFarina utilizzata: %s\nPrezzo: %g\n\n", pizze[i]->nome, pizze[i]->ingredienti, pizze[i]->cottura, pizze[i]->farina, pizze[i]->prezzo);
    }
}

Pizza** inputPizza(int numPizze){
    Pizza **pizza = xmalloc(sizeof(Pizza*) * numPizze);
    int choice = 0;
    for(int i = 0; i< numPizze; i++){
        printf("Seleziona Pizza\n1 - 2 - 3\n");
        scanf("%d", &choice);
        fflush(stdin);
        pizza[i] = xmalloc(sizeof(Pizza));
        if (choice == 1)
            pizza[i] = menuPizze[0];
        if (choice == 2)
            pizza[i] = menuPizze[1];
        if (choice == 3)
            pizza[i] = menuPizze[2];
    }
    return pizza;
}

Ordine* takeOrder(Ordine* order){
    order = xmalloc(sizeof(Ordine));
    printf("Antipasti\n1 - fritto etero(la casa lo sconsiglia poiche' da normie) Prezzo $1\n2 - fritto non binario Prezzo $ 2.5\n3 - fritto transgender Prezzo $5.5\nScelta: ");
    scanf("%d", &order->antipasto);
    if (order->antipasto == 1)
        order->conto += 1;
    if (order->antipasto == 2)
        order->conto += 2.5;
    if (order->antipasto == 3)
        order->conto += 5.5;
    
    order->numPizze = 0;

    printf("numero di pizze?\n");
    scanf("%d", &order->numPizze);
    fflush(stdin);
    printf("Scegli la tua pizza\n");
    printPizze(menuPizze, NPIZZE);
    order->pizza = inputPizza(order->numPizze);
    
    for (int i = 0; i < order->numPizze; i++)
        order->conto += order->pizza[i]->prezzo;

    printf("Preferisci una bibita? Prezzo $2.50 y = 1/n = 0 ");
    scanf("%d", &order->bibita);
    if (order->bibita == 1)
        order->conto += 2.5;
    
    fflush(stdin);
    return order;
}

void printOrders(Ordine** orders, int n){
    
    for(int i = 0; i < n; i++){
        printf("Ordine %d\nAntipasto: %d\nPizze:\n",i + 1, orders[i]->antipasto);
        printPizze(orders[i]->pizza, orders[i]->numPizze);
        orders[i]->bibita == 1 ? printf("Bibita\n\n") : printf("No bibita\n");
    }
}

int takeOrders(Ordine** orders, int index){
    orders[index] = takeOrder(orders[index]);
    index =+ 1;
    orders = xrealloc(orders, (index + 1) * sizeof(Ordine*));
    return index;
}

void conto(Ordine** orders){
    int tavolo = 0;
    printf("Indicare tavolo ");
    scanf("%d", &tavolo);
    fflush(stdin);
    printf("Il conto del tavolo %d e' %g\n", tavolo, orders[tavolo-1]->conto);
}

void selector(){
    int choice = 0;
    int index = 0;
    Ordine ** orders = xmalloc(sizeof(Ordine*));
    
    do{
        printf("1 - Prendi ordine\n2 - Mostra comande\n3 - Richiedi conto tavolo\n4 - Esci\nScelta: ");
        scanf("%d", &choice);
        fflush(stdin);
        if (choice == 1){
            index  += takeOrders(orders, index);
        }
        if (choice == 2)
            printOrders(orders, index);
        if (choice == 3)
           conto(orders);
    }while(choice < 4);
    printf("Chiusura in corso\n");
    free(orders);
}

Pizza** inputPizze(){
    menuPizze = xmalloc(sizeof(Pizza*) * NPIZZE);
    //PIZZA 1
    for(int i = 0; i <NPIZZE; i++){
        menuPizze[i] = xmalloc(sizeof(Pizza));
    }
    menuPizze[0]->nome = "Margherito";
    menuPizze[0]->cottura = "Normale...ceh ma che cazzo vuoi";
    menuPizze[0]->ingredienti ="Mozzarello, Pomodor*, e altre cose che diamo per scontato ma che sono importanti tipo il sale e l'olio";
    menuPizze[0]->farina = "Reference alla cocaina generica";
    menuPizze[0]->prezzo = 3.5;
    //PIZZA 2
    menuPizze[1]->nome = "Sinfonia di piedini";
    menuPizze[1]->cottura = "One word: PIEDIH :Q__";
    menuPizze[1]->ingredienti ="PIEDIPIEDIPIEDIPIEDIPIEDI";
    menuPizze[1]->farina = "Reference alla cocaina generica";
    menuPizze[1]->prezzo = 5.5;
    //PIZZA 3
    menuPizze[2]->nome = "TNT VIllage";
    menuPizze[2]->cottura = "Fritto...purtroppo";
    menuPizze[2]->ingredienti ="Questo elenco e' stato posto sotto sequestro da parte della polizia italiana mondiale (Ma ci pensate che la postale e' la polizia mentale di 1984. Il mondo e' alla frutta ormaiaiutijghbtjrymnyn";
    menuPizze[2]->farina = "Reference alla cocaina generica";
    menuPizze[2]->prezzo = 7.3;
    return menuPizze;
}

int main(void){
    Pizza** menuPizze = inputPizze();
    selector();
}