1. Inicializáljon egy sztringet, egy másikat pedig olvasson be a scanf() megengedett karaktereket
felsoroló változatával. Próbálja ki a string.h standard függvényeit (sztring hosszának
meghatározása, sztring másolás, sztring hozzáfűzés, karakter keresése sztringben, rész-sztring
keresés, két sztring összehasonlítása)!

2. Szókitaláló játék
Inicializáljon egy sztringtömböt. Ebből véletlenszerűen kiválasztva egyet, keverje össze a betűit és
mutassa meg a felhasználónak. A feladat kitalálni az összekevert betűkből az eredeti szót.
A felhasználó mondjon tippeket, a program válaszoljon: hányadik karakter helyét találta el
(a Mesterlogika játék mintájára).
A játék végén írja ki a helyes szót és azt, hogy hány tipp után találta ki a felhasználó.

3. Olvasson be egy mondatot (az utolsó karakter ‘.’, ‘?’, vagy ‘!’).
Keresse meg, hogy a mondatban:
a) a mondatkezdő karakteren kívül van-e nagybetű és az hányadik,
b) van-e speciális karakter vagy szám, és az hányadik.

4. Töltsön fel egy 10 elemű tömböt 10 és 100 közé eső véletlenszámokkal.
Keresse meg ebben a tömbben:
a) a legkisebb prímszámot,
b) a legnagyobb négyzetszámot.

5. Keresse meg az Interneten a férfi teniszezők világranglistáját (csökkenően rendezett sorozat).
Tárolja el a pontszámokat tömbben és végezzen kereséseket.
Implementálja a lineáris keresés és a logaritmikus keresés algoritmusait.
Próbálja ki a standard C bsearch() függvényt.

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