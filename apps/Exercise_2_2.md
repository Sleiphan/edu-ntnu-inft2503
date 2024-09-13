# Øving 2

## Oppgave 2

```cpp
int main() {
  char *line = nullptr;
  strcpy(line, "Dette er en tekst");
}
```

Dette programmet vil kræsje pga segmentation fault, ettersom programmet prøver å modifisere data som er read-only.

I C++ genereres det en exception som kalles "Access violation". Siden kodesnutten ikke fanger denne opp, vil programmet kræsje.
