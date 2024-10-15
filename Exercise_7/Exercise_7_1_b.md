## Forklaring av "5 - 3 - fraction1 - 7 - fraction2"

I c++ blir større minus-uttrykk behandlet kronologisk fra venstre mot høyre. I eksempeluttrykket "5 - 3 - fraction1 - 7 - fraction2", vil da "5 - 3" bli regnet ut først.

Utregningen følger dermed denne sekvensen:
1. _5 - 3 = 2_
2. _2 - fraction1 = f1_
3. _f1 - 7 = f2_
4. _f2 - fraction2 = f3_

Variablene f1, f2, og f3 er bare plassholdere som gjør det lettere å forklare sekvensen siden vi ikke vet verdien av fraction1 og fraction2.

### Hvilke versjoner av operatoren '-' som blir brukt
Her er en liste over alle funksjonene som brukes i hvert utregnings-steg:
1. Minus-operatoren innebygget i c++-kompilatoren.
2. Minus-operatoren som er definert utenfor Fraction-klassen.
   - _Fraction operator-(int number, const Fraction &other)_
3. Minus-operatoren som er definert innenfor Fraction-klassen.
   - _Fraction Fraction::operator-(int number) const_
4. Minus-operatoren mellom to instanser av Fraction.
   - _Fraction Fraction::operator-(const Fraction &other) const_
