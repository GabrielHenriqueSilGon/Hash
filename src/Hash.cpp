#include "Hash.hpp"


void
Initialize (HashTable * h)
{
  h->tam = MAXTAM;
  h->chei = 0;
  for (int i = 0; i < h->tam; i++)
    {
      h->table[i].key = -1;
      h->table[i].value = 0;
    }

  h->coli = 0;

}


void
Imprime (HashTable * h)
{
  for (int i = 0; i < h->tam; i++)
    if (h->table[i].key != -1)
      printf ("KEY:%d - VALUE:%d\n", h->table[i].key, h->table[i].value);

  printf ("COLISOES:%d\n", h->coli);
}


int
getValue (HashTable * h, int value)
{
  int idx = HashFun (h, value);
  int aux = idx;

  while (h->table[idx].value != value)
    {
      idx = HashFun (h, idx + 1);

      if (idx == aux)
	{
	  printf ("Nao existe esse numero na Hash\n");

	  return 0;
	}
    }

  return h->table[idx].key;
}

void
Insert (HashTable * h, int value)
{
  int idx = HashFun (h, value);
  int aux = idx;

  while (h->table[idx].key != -1)
    {
      idx = HashFun (h, idx + 1);
      h->coli++;

      if (idx == aux)
	{
	  printf ("HASH TA CHEIA!\n");

	  return;
	}
    }


  h->table[idx].key = idx;
  h->table[idx].value = value;
  h->chei = h->chei + 1;

}

int
HashFun (HashTable * h, int value)
{
  return value % h->tam;
}
