#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 15  // Ukuran maksimum stack
typedef char infotype; // Tipe data untuk elemen stack

// Struktur untuk stack
struct stack {
    infotype info[MAX_SIZE]; // Array untuk menyimpan elemen stack
    int Top; // Indeks teratas dari stack
};

// Prototipe fungsi
void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype x);
int pop(stack &S);
void printInfo(stack S);

#endif
