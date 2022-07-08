#ifndef HASH_HPP 
#define HASHT_HPP

#include<stdio.h>
#include<stdlib.h>

#define MAXTAM 43

typedef struct DataTable DataTable;
typedef struct HashTable HashTable;

struct DataTable{
	int key;
	int value;
};


struct HashTable{
    int tam;
	DataTable table[MAXTAM];
	int coli;
	int chei;
};


void Initialize(HashTable *h);
void Imprime(HashTable *h);
int getValue(HashTable *h, int value);
int HashFun(HashTable *h, int value);
void Insert(HashTable *h, int value);

#endif