# 6. Hét [[Vissza](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/Programoz%C3%A1s%20Alapjai/Szorgalmi%20Feladatok)]

## Feladatok
> 1. **[Feladat]()**
> > - [ ] **Írjon C programot!**
> > - ***Inicializáljon egy sztringet, egy másikat pedig olvasson be a scanf() megengedett karaktereket felsoroló változatával.***
> > - ***Próbálja ki a string.h standard függvényeit (sztring hosszának meghatározása, sztring másolás, sztring hozzáfűzés, karakter keresése sztringben, rész-sztring keresés, két sztring összehasonlítása)!***
----
> 2. **[Feladat]()**
> > - [ ] **Szókitaláló játék**
> > - ***Inicializáljon egy sztringtömböt.***
> > - ***Ebből véletlenszerűen kiválasztva egyet, keverje össze a betűit és mutassa meg a felhasználónak.***
> > - ***A feladat kitalálni az összekevert betűkből az eredeti szót.***
> > - ***A felhasználó mondjon tippeket, a program válaszoljon:***
> > - - ***hányadik karakter helyét találta el (a Mesterlogika játék mintájára).***
> > - ***A játék végén írja ki a helyes szót és azt, hogy hány tipp után találta ki a felhasználó.***
----
> 3. **[Feladat]()**
> > - [ ] **Írjon C programot!**
> > - ***Olvasson be egy mondatot (az utolsó karakter ‘.’, ‘?’, vagy ‘!’).***
> > - ***Keresse meg, hogy a mondatban:***
> > - - ***a) a mondatkezdő karakteren kívül van-e nagybetű és az hányadik,***
> > - - ***b) van-e speciális karakter vagy szám, és az hányadik.***
----
> 4. **[Feladat]()**
> > - [ ] **Írjon C programot!**
> > - ***Töltsön fel egy 10 elemű tömböt 10 és 100 közé eső véletlenszámokkal.***
> > - ***Keresse meg ebben a tömbben:***
> > - - ***a) a legkisebb prímszámot,***
> > - - ***b) a legnagyobb négyzetszámot.***
----
> 5. **[Feladat]()**
> > - [ ] **Írjon C programot!**
> > - ***Keresse meg az Interneten a férfi teniszezők világranglistáját (csökkenően rendezett sorozat).***
> > - ***Tárolja el a pontszámokat tömbben és végezzen kereséseket.***
> > - ***Implementálja a lineáris keresés és a logaritmikus keresés algoritmusait.***
> > - ***Próbálja ki a standard C bsearch() függvényt.***
> > - - ***1. C kód***
----

### 1. C kód
```c
// Összehasonlító függvény növekvő int sorozat esetén
int comparefunction(const void * a, const void * b)
{
    return *(int*)a - *(int*)b;
}

// bsearch() használata int sorozat esetén
int* item = (int*)bsearch(&searchkey, array, size, sizeof(int), comparefunction);

if( item != NULL )
    printf("Keresett elem: %d, sorszáma: %d\n", *item, item - array + 1);
else
    printf("Nem talált\n");
```