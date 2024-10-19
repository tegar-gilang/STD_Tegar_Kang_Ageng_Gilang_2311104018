#ifndef LIST_H 
#define LIST_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address next;
};

struct List {
    address first;
};

// Primitif List
void createList(List &L);
address allocate(infotype X);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void printInfo(List L);

#endif
