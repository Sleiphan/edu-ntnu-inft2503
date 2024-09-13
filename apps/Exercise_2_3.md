# Øving 2

## Oppgave 3

```cpp
1: char text[5];
2: char *pointer = text;
3: char search_for = 'e';
4: cin >> text;
5: while (*pointer != search_for) {
6:   *pointer = search_for;
7:   pointer++;
8: }
```

På linje 4, er det fare for å overskrive data utenfor arrayet 'text'.

I while-løkken på linjene 5-8, vil programmet begynne å overskrive data utenfor arrayet 'text' dersom brukeren ikke skriver inn en eneste 'e'-bokstav.

Dette programmet er svakt for stack-smashing-angrep. I mange tilfeller vil det kræsje på grunn av segmentation fault.
