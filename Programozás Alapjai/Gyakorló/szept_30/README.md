1. Ellenőrzött módon olvasson be egy időintervallumot (2 évszámot, mindkét végén zárt intervallum) és számolja meg,
hány szökőév volt az adott időszakban.

2. Olvasson be ellenőrzött módon egy intervallumot. Ebben az intervallumban állítson elő automatikusan számpárokat
ismétlődés nélkül (azaz (2,3) és (3,2) ugyanaz a pár; és (2,2) nem számpár). Számolja meg és írja ki a párokat.

3. 1 és N között határozza meg a számok szorzatát és mértani átlagát.
N-et ellenőrzött módon olvassa be (N>1).
Mértani átlag számítása: a számokat össze kell szorozni és az eredményből annyiadik gyököt kell vonni,
ahány átlagolandó szám van. A szorzatképzéshez használja az összegzés alapalgoritmust.
Hatványozáshoz használja a math.h double pow(double alap, double kitevo) függvényét.

4. N oldalú négyzet (oldalai N db. *-ból állnak) egyik átlója, és az alatta/felette lévő terület rajzolása.

5. Rajzoljon ki a képernyőre csillagokból egy E betűt!
A betű magasságát kérje be és ellenőrizze, hogy a megadott szám pozitív páratlan szám legyen.

6. Az E betű tükrözésével rajzoljon ki csillagokból 3-ast a képernyőre!

7. Rajzoljon ki # karakterekből egy paralelogrammát. A magasságát és a szélességét olvassa be!

8. Egyenlőszárú, N magasságú háromszög kirajzolása.

BE: magasság
sor := 1
AMÍG sor <= magasság ADDIG
i := 1
AMÍG i <= magasság-sor ADDIG
KI: üres karakter
i := i + 1
CIKLUS vége
i := 1
AMÍG i <= ((sor*2)-1) ADDIG
KI: *
i := i+1
CIKLUS vége
KI: sortörés
sor := sor+1
CIKLUS vége

9. Módosítsa az előző algoritmust: csak háztetőt, illetve csak a háromszög keretét rajzolja ki!

10. Csúcsára állított egyenlőszárú, N magasságú háromszög kirajzolása.

BE: magasság
sor := 1
AMÍG sor <= magasság ADDIG
i := 1
AMÍG i <= sor-1 ADDIG
KI: üres karakter
i := i + 1
CIKLUS vége
i := 1
AMÍG i <= (magasság*2)-(sor*2)+1 ADDIG
KI: *
i := i+1
CIKLUS vége
KI: sortörés
sor := sor+1
CIKLUS vége

11. Keresse meg és írassa ki az első N db. prímszámot!
N értékének beolvasása ellenőrzéssel történjen!

12. Keresse meg és írassa ki 1 és 100 között az összes négyzetszámot!

13. Ellenőrzött adatbeolvasással adjon meg egy intervallumot (alsóhatár < felsőhatár).
Majd olvasson be N darab számot és számolja meg,
hogy a megadott számok közül hány darab esik az intervallumba.

14. Három megadott számról döntse el, hogy lehetnek-e egy háromszög oldalai!

15. Rajzoljon ki a képernyőre *-okból a felhasználó által megadott magasságú N és Z betűket!
A betűk szélessége egyenlő a megadott magassággal. Végezzen input ellenőrzést: a magasság min. 3!

16. Rajzoljon ki a képernyőre *-okból a felhasználó által megadott magasságú L, T és H betűket!
Végezzen input ellenőrzést: a magasság páratlan szám legyen, legalább 5.
A szélességet a program számítja: magasság-2.