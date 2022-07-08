#include "Hash.hpp"
#include <iostream>

using namespace std;

int
main ()
{
  HashTable h;
  int n = 1;
  int m;

  Initialize (&h);


  printf ("De um numero para a hash: (digite 0 para sair)\n");

  while (n != 0)
    {
      cin >> n;
      if (n != 0)
	Insert (&h, n);
    }


  cout << "\nDe um valor para ser buscado: \n";
  cin >> m;
  
  if (getValue(&h, m) != -1)
  cout << "chave de " << m << ": " << getValue(&h, m) << endl;
  
  else
  printf ("Não existe esse numero na Hash.\n");


  cout << "\nImprimindo Hash...\n";
  Imprime (&h);

  return 0;

}
