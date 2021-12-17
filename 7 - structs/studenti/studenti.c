#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENSTR 30
//this software store date about school marks of a certain number of students
//it will be used two struct
//  -student
//  -mark
//Every student has some personal infos and some other about school marks, we store it in array of mark struc elements
//Very macceronic english
typedef struct Mark {
    char* name;
    double grade;
}Mark;

typedef struct Student {
    char *name;
    char *surname;
    int nMarks;
    Mark *marks[];
}Student;

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

void readLine (char* str, int len){
    fgets(str, len, stdin);
    int newLen = strlen(str); 
    if (str[newLen - 1] == '\n')
        str[newLen - 1] = '\0';
}

char* readString(int len){
    char* str = xmalloc(len * sizeof(char));
    readLine(str, len);
    int newLen = strlen(str);
    str = xrealloc(str, newLen * sizeof(char));
    return str;
}

void printMarks(Mark** marks, int nMarks){
    for(int i = 0; i < nMarks; i++){
        printf("name: %s\ngrade: %g\n", marks[i]->name, marks[i]->grade);
    }   
    printf("\n"); 
}

void printStudents(Student** studenti, int n){
    
    for(int i = 0; i < n; i++){
        printf("STUDENT %d\n", i+1);
        fflush(stdin);
        printf("name: %s\nsurname: %s\n\nMarks:\n", studenti[i]->name, studenti[i]->surname);
        printMarks(studenti[i]->marks, studenti[i]->nMarks);
    }    
}

Mark* inputMark(){
    Mark* mark = xmalloc(sizeof(Mark));
    fflush(stdin);
    printf("Mark name? ");
    fflush(stdin);
    mark->name = readString(MAXLENSTR);
    fflush(stdin);
    do{
        printf("Input grade ");
        scanf("%lf", &mark->grade);
    }while(mark->grade > 10);
    fflush(stdin);
    return mark; 
}

Student* inputStudent(){
    int nMarks = 0;
    Student* student = xmalloc(sizeof(Student));
    fflush(stdin);
    printf("Student name ");
    fflush(stdin);
    student->name = readString(MAXLENSTR);
    fflush(stdin);
    printf("Student surname ");
    fflush(stdin);
    student->surname = readString(MAXLENSTR);
    do{
        printf("How many marks do you wanna save? (max 10 marks) ");
        scanf("%d", &student->nMarks);
        fflush(stdin);
    }while(student->nMarks > 10);
    for (int i = 0; i< student->nMarks; i++){
        fflush(stdin);
        student->marks[i] = inputMark(student->nMarks);
    }
    fflush(stdin);
    return student;
}


Student ** inputStudenti(int n){
    Student** studenti = xmalloc(sizeof(Student*) * n);
    
    for (int i = 0; i < n; i++){
        
        studenti[i] = inputStudent();
    }
    return studenti;
}

int inputStudentsNumber(){
    int n = 0;
    do{
        printf("Input number of students ");
        scanf("%d", &n);
        fflush(stdin);
    }while(n > 10);
    
    return n;
}

void main(void){
    int n = inputStudentsNumber();
    Student **studenti = inputStudenti(n);
    printStudents(studenti, n);
}