# 3 Gyakorlat
## Feladatok
### POSIX szálak
> 1. **[Feldat]()**
> > - [ ] ***Készítsünk olyan programot, amelynél a fő szál 8 másodpercnyi számítást végez el, míg az általa indított csak 4-et! Vizsgáljuk meg a fordított esetet is!***
> 2. **[Feldat]()**
> > - [ ] ***Készítsünk olyan programot, amelynél a fő szál 8 másodpercnyi számítást végez el, míg az általa indított csak 4-et! Vizsgáljuk meg a fordított esetet is!***
> 3. **[Feldat]()**
> > - [ ] ***Készítsünk egy programot, amelyik 10 szál segítségével meghatározza, hogy mennyi prímszám van a [0, 99], [100, 199], … intervallumokon! A szálaknak adja át az intervallumok indexét, majd az eredményt így írják közvetlenül egy globális tömbbe!***
> 4. **[Feldat]()**
> > - [ ] ***Vizsgáljuk meg, hogy mi történik, hogy ha egy szálban futás idejű hiba keletkezik!***
----

### Algoritmusok párhuzamosítása
> 1. **[Feladat]() Készítsen egy programot, amely egy tömb elemeinek összegét számítja ki több szál felhasználásával!**
> > - [ ] ***Oldja meg, hogy a program működjön tetszőleges méretű tömbökre is!***
> > - [ ] ***Írjon egy programot, amely a tömböt közel egyenlő részekre oszt oldja meg az összegzést!***
> > - [ ] ***Írjon egy programot, amely rekurzív felosztásra épül!***
> > - [ ] ***A programban a szálak száma paraméterként szerepeljen!***
> > - [ ] ***Hasonlítsa össze a '(p = 1)' esetet a szekvenciális változattal futási idő tekintetében!***
> > - [ ] ***Mérje le a futási időket különböző 'p' értékek és különböző bemenetméretek mellett!***
> > - [ ] ***Adjon becslést a 'T(n, p)' függvényre (ahol 'n' a bemeneti tömb mérete,  pedig a szálak száma).***
> > - [ ] ***Adjon becslést a gyorsításra (mint 'S(p)' függvényre)!***
> > - [ ] ***A kapott eredményeket foglalja össze táblázatban, és ábrázolja grafikonon!***
----
> 2. **[Feladat]() Készítsen olyan programokat, amelyek meghatározzák, hogy bizonyos tulajdonságú elemből mennyi található egy sorozatban. Ilyen tulajdonság lehet például, hogy...**
> > - [ ] ***egész értékek esetén páros vagy páratlan számok-e,***
> > - [ ] ***0 értékűek-e,***
> > - [ ] ***előjelesek-e,***
> > - [ ] ***lebegőpontos számok esetén 1-nél kisebb abszolút értékűek-e, vagy hogy***
> > - [ ] ***adott intervallumba esnek-e.***
> > - *A feladat megoldásánál használjon*
> > - - *nagy méretű, véletlenszerűen generált adatokat,*
> > - - *dinamikusan allokált tömböket.*
> > - *Hasonlítsa össze a szekvenciális és a többszálú megvalósítást!*
> > - - *Mérje le a futási időket a bemenet méretének és a szálak számának függvényében!*
> > - - *Összesítse a kapott eredményeket táblázatos formában!*
> > - - *Ábrázolja az eredményeket grafikonok!*
----
> 2. **[Feladat]() Készítsen programot egy tömb prefixeinek a kiszámításához!**
> > - [ ] ***Adja meg a szekvenciális változatot!***
> > - [ ] ***Implementálja a CREW_PREFIX algoritmust!***
> > - [ ] ***Implementálja az EREW_PREFIX algoritmust!***
> > - [ ] ***Implementálja az OPTIMAL_PREFIX algoritmust!***
> > - [ ] ***Mérje le a futási időket különböző számú szál és különböző bemenetméretek mellett!***
> > - [ ] ***Adjon becslést a gyorsításra (mint  függvényre)!***
> > - [ ] ***A kapott eredményeket foglalja össze táblázatban, és ábrázolja grafikonon!***