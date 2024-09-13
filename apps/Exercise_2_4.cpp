#include <stdio.h>

int main()
{
  // int a = 5;
  // int &b; // Feil: alle referansevariabler må alltid være initialisert. Tomme referansevariabler er ikke lov, og gir heller ikke mening.
  // int *c;
  // c = &b;
  // *a = *b + *c; // Feil: 'a' og 'b' er ikke pointere, og kan dermed ikke de-references.
  // &b = 2; // Feil: kan ikke modifisere minne-lokasjonen til en referansevariabel.

  // Hensikten med disse linjene er ikke tydelig.
  // Følgende er kun en minimalt omformet versjon som gjør at linjene kan kompileres og kjøres.

  int a = 5;
  int b = 0;
  int *c;
  c = &b;
  a = b + *c;
  b = 2;

  printf("a [%p]: %d\n", (void *)&a, a);
  printf("b [%p]: %d\n", (void *)&b, b);
  printf("c [%p]: %p\n", (void *)&c, (void *)c);
}