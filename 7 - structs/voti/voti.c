#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENSTR 30

typedef struct Studente{
    char* nome;
    char* cognome;
    double voto;
}Studente;

void* xmalloc (size_t size){
    void* p = malloc(size);
    if (!p){
        printf("Allocation failed\n");
        return NULL;
    }
    return p;
}

void* xrealloc (void* p, size_t size){
    p = realloc(p, size);

    if (!p){
        printf("Allocation failed\n");
        return NULL;
    }

    return p;
}

int numberOfStudents(){
    int n = 0;
    do{
        printf("Fornire numero di studenti (MAX 10 Studenti) ");
        scanf("%d", &n);
        fflush(stdin);
    }while(n > 10);
    return n;
}

void inputVoto(Studente* student){
    do{
        printf("Fornire voto (18 <--> 30): ");
        scanf("%lf", &student->voto);
        fflush(stdin);
    }while (student->voto < 18 || student->voto > 30);
}

void readLine(char* str){
    fgets(str, MAXLENSTR, stdin);
    fflush(stdin);
    int len = strlen(str); 
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
}

char* readString(int len){
    char *str = xmalloc(len);
    readLine(str);
    int newLen = strlen(str);
    str = xrealloc(str, newLen);
    return str;
}

double media(Studente** students, int n){
    double media = 0;
    for(int i = 0; i < n; i++){
        media += students[i]->voto;
    }
    return (media / n);
}

void printStudents(Studente** students, int n){
    for(int i = 0; i < n; i++){
        printf("\nStudente %d\nnome: %s\ncognome: %s\n", (i + 1),students[i]->nome, students[i]->cognome);
    }
    printf("Media voti della classe: %g\n",media(students, n));
}

Studente* inputStudente(Studente* student){
    student = xmalloc(sizeof(Studente));
    printf("Fornire nome: ");
    student->nome = readString(MAXLENSTR);
    printf("Fornire cognome: ");
    student->cognome = readString(MAXLENSTR);
    inputVoto(student);
    return student;
}

Studente** inputStudenti(Studente** students, int n){
    for(int i = 0; i < n; i++){
        printf("\nStudente %d\n", i + 1);
        students[i] = inputStudente(students[i]);
    }
    return students;
}

Studente** searchByCognome(Studente** students, Studente** studentsCopy, int n, int* nN){
    printf("Fornire cognome ");
    char* cognome = readString(MAXLENSTR);
    studentsCopy = xmalloc(sizeof(Studente*));
    for(int i = 0; i < n; i++){
            if (strcmp(students[i]->cognome, cognome) == 0){
                studentsCopy[*nN] = students[i];
                *nN += 1;
                studentsCopy = xrealloc(studentsCopy, sizeof(Studente*) * (*nN + 1));
            }
    }
    return studentsCopy;
}

void freeAll(Studente** students, int n){
    for(int i = 0; i < n; i++)
        free(students[i]);
}

int main(void){
    int n = numberOfStudents();
    Studente** students = xmalloc(sizeof(Studente*) * n); 
    printf("Popolamento registro studenti\n");
    students = inputStudenti(students, n);
    
    int choice = 0;
    do{
        printf("1 - Calcola media della classe\n2 - Crea sottoelenco per cognome\n3 - Esci o frat\nScelta: ");
        scanf("%d", &choice);
        fflush(stdin);
        if (choice == 1)
            printStudents(students, n);
        if (choice == 2){
            int nN = 0;
            Studente** studentiByCog = searchByCognome(students, studentiByCog,  n, &nN);
            printStudents(studentiByCog, nN);
        }
    }while(choice < 3);
    
    freeAll(students, n);
}