# 2 Gyakorlat
## Feladatok
### Mérések algoritmusok bonyolultságára vonatkozóan
> 1. **[Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/P%C3%A1rhuzamos%20Algoritmusok/Gyakorlati%20Feladatok/2%20Gyakorlat/Mérések%20algoritmusok/1%20Feladat)**
> > - [x] ***Készítsen el egy programot, amellyel egy tömbben lévő számértékeket lehet beolvasni.***
> > - [x] ***Írjon egy függvényt az elemek összegének kiszámításához!***
> > - [x] ***Valósítsa meg a minimum és a maximum értékének a meghatározását külön függvényekben!***
> > - [x] ***Próbálja meg rekurzív függvényekkel is megoldani az előbbi számítási feladatokat!***
> > - [x] ***Mérje le, gyűjtse össze táblázatba és ábrázolja grafikonon az iteratív és a rekurzív változatok számítási idejét az elemszám függvényében!***
> > - [ ] ***Adjon felső becslést a futási időre vonatkozóan! (T(n) = O(?))***
> 2. **[Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/P%C3%A1rhuzamos%20Algoritmusok/Gyakorlati%20Feladatok/2%20Gyakorlat/Mérések%20algoritmusok/2%20Feladat)**
> > - [x] ***Generáljon egy tömböt úgy, hogy az elemek egész értékűek, és mindegyik különbözik!***
> > - [x] ***Vizsgálja meg a tömb generálásának számítási idejét az elemszám függvényében!***
> > - [x] ***0.5 valószínűséggel duplikáljon benne néhány elemet!***
> > - [x] ***Készítsen olyan függvényt, amely ellenőrzi, hogy a tömb minden eleme egyedi-e!***
> > - [x] ***Vizsgálja meg a függvény bonyolultságát!***
> 3. **[Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/P%C3%A1rhuzamos%20Algoritmusok/Gyakorlati%20Feladatok/2%20Gyakorlat/Mérések%20algoritmusok/3%20Feladat)**
> > - [x] ***Generáljon egy tömböt, amelyben az elemek lebegőpontos értékek, és szigorúan monoton növekvő sorozatot alkotnak!***
> > - [x] ***Készítsen függvényt a tulajdonság ellenörzéséhez!***
> > - [x] ***Definiáljon egy függvényt, amely bináris kereséssel keres egy elemet a tömbben!***
> > - - [x] ***Készítse el az iteratív és a rekurzív változatát!***
> > - [x] ***Véletlenszerűen kiválasztott és/vagy generált értékek keresése alapján mérje le a számítási idők eloszlását (adott elemszám mellett)!***
> > - [x] ***Hasonlítsa össze az iteratív és a rekurzív változat futási idejét az elemszám függvényében!***
> > - [x] ***Ábrázolja az egyes elemszámokhoz tartozó futási idők maximumát!***
> 4. **[Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/P%C3%A1rhuzamos%20Algoritmusok/Gyakorlati%20Feladatok/2%20Gyakorlat/Mérések%20algoritmusok/4%20Feladat)**
> > - [ ] ***Generáljon egy szöveges fájlt az angol ábécé kis és nagy betűiből, számjegyekből, szóközökből és sortörésekből véletlenszerűen!***
> > - [ ] ***A generáláshoz paraméterként használja a generálandó karakterek számát!***
> > - [ ] ***Készítsen egy függvényt, amelyik meghatározza, hogy mennyi sort tartalmaz a szöveges fájl!***
> > - [ ] ***Próbáljon rekurzív megoldást is adni a problémára!***
> > - [ ] ***Hasonlítsa össze az iteratív és a rekurzív változat futási idejét!***
> > - [ ] ***Határozza meg az üres sorok számát!***

----
### Prefix számítás vizsgálata
> - *Tekintsük a prefix számítás esetében egységnyi idejűnek a  művelet elvégzését!*
> 1. **[Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/P%C3%A1rhuzamos%20Algoritmusok/Gyakorlati%20Feladatok/2%20Gyakorlat/Prefix%20sz%C3%A1m%C3%ADt%C3%A1s/1%20Feladat)**
> > - [ ] ***Készítsen egy programot, amely a CREW_PREFIX algoritmus végrehajtása során elvégzett hívásokat GraphViz segítségével egy hívási fában ábrázolja!***
> > - - [ ] ***A program a kimenetet egy szöveges fájl formájában adja meg!***
> > - - [ ] ***A megjelenítéshez használhat online gráf megjelenítőt, például: [GraphvizOnline](https://dreampuf.github.io/GraphvizOnline/)***
> > - - [ ] ***A csomópontokban tüntesse fel, hogy a hívás milyen intervallumra vonatkozott!***
> > - - [ ] ***Próbálja megoldani, hogy a program tetszőleges 'n' méretű bemenetre működjön!***
> 2. **[Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/P%C3%A1rhuzamos%20Algoritmusok/Gyakorlati%20Feladatok/2%20Gyakorlat/Prefix%20sz%C3%A1m%C3%ADt%C3%A1s/2%20Feladat)**
> > - [ ] ***Az EREW_PREFIX algoritmus vizsgálatához készítsen egy programot, amellyel vizsgálható a párhuzamosan elvégzett számítások során a munka, költség, gyorsítás és a hatékonyság mértéke!***
> > - - [ ] ***Egy szövegfájlba mentse le, hogy a számítások során a 't' időpillanatban mennyi számítási egység végzett éppen hasznos munkát! (Itt a sorok mutassák az időt, az oszlopok pedig, hogy melyik számítási egységről van szó! Jelölje '.' karakter, hogy ha nem történt hasznos számítás, '#' pedig hogy ha igen!)***
> > - - [ ] ***Határozza meg az említett 'W', 'C', 'S' és 'E' értékeket 'n = 100' bemenetméretig!***
> > - - [ ] ***Gyűjtse össze az adatokat egy táblázatba!***
> > - - [ ] ***Ábrázolja grafikonon a bemenet függvényében a gyorsítás és a hatékonyság mértékét!***
> 3. **[Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/P%C3%A1rhuzamos%20Algoritmusok/Gyakorlati%20Feladatok/2%20Gyakorlat/Prefix%20sz%C3%A1m%C3%ADt%C3%A1s/3%20Feladat)**
> > - [ ] ***Vizsgálja meg az OPTIMAL_PREFIX algoritmus működését!***
> > - - [ ] ***Írjon fel egy saját példát 'n = 16' bemenet esetére! Rajzolja fel az ehhez tartozó Gantt diagramot!***
> > - - [ ] ***Ábrázolja grafikonon, hogy 'n' méretű bemenet esetén mennyi processzorra van szükség a számításhoz!***
> > - - [ ] ***Karakter tömb segítségével ábrázolja (például fájlba kimentve), hogy a 't' időegységben végzett-e hasznos számítást a 'p' processzor!***
> > - - [ ] ***Határozza meg az említett 'W', 'C', 'S' és 'E' értékeket 'n = 100' bemenetméretig!***

----
### Hálózati topológiák
> 1. **[Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/P%C3%A1rhuzamos%20Algoritmusok/Gyakorlati%20Feladatok/2%20Gyakorlat/H%C3%A1l%C3%B3zati%20topol%C3%B3gi%C3%A1k/1%20Feladat)**
> > - [ ] ***Négyzetes rács topológia esetén végezze el a következő számításokat!***
> > - - [ ] ***Számítsa ki 'n = 50'-ig, hogy egy 'n x n' méretű rácsban mennyi csomópont és él van!***
> > - - [ ] ***Határozza meg ezek arányát 'n' függvényében, és ábrázolja a kapott eredményt grafikonon!***
> > - - [ ] ***Egy '12 x 12'-es méretű rács esetében határozza meg a pontok közötti távolságok eloszlását!***
> > - - [ ] ***Ábrázolja a kapott eredményt hisztogramon!***
> > - - [ ] ***Vizsgálja meg, hogy 'n = 24'-ig térbeli rács esetében hogyan változik a csomópontok és élek száma!***
> > - - [ ] ***Hasonlítsa össze, hogy 'n' függvényében hogyan alakul az élek száma síkbeli és térbeli rácsok esetében!***
> > - - [ ] ***Számítsa ki a csomópontok közötti távolságok eloszlását egy  méretű térrácsban!***
> 2. **[Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/P%C3%A1rhuzamos%20Algoritmusok/Gyakorlati%20Feladatok/2%20Gyakorlat/H%C3%A1l%C3%B3zati%20topol%C3%B3gi%C3%A1k/2%20Feladat)**
> > - [ ] ***Végezze el az előbbi számításokat tórusz topológia esetében!***
> 3. **[Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/P%C3%A1rhuzamos%20Algoritmusok/Gyakorlati%20Feladatok/2%20Gyakorlat/H%C3%A1l%C3%B3zati%20topol%C3%B3gi%C3%A1k/3%20Feladat)**
> > - [ ] ***Végezzen számításokat hiperkocka topológia esetében!***
> > - - [ ] ***Számítsa ki, hogy 30 dimenzióig hogyan változik a csomópontok és az élek száma!***
> > - - [ ] ***Határozza meg 8 dimenzióban a csomópontok közötti távolságok eloszlását!***
> > - - [ ] ***Ábrázolja a kapott eredményt hisztogramon!***
> > - - [ ] ***Számítsa ki 20 dimenzióig az átlagos távolságokat!***
> > - - [ ] ***Hasonlítsa össze ezeket a csomópontok száma alapján a síkbeli és térbeli rács topológiákkal!***