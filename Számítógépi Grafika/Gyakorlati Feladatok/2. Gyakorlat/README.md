# 2. Gyakorlat [[Vissza](https://github.com/OraveczJozsef/ME_BRZGJZ/tree/main/Sz%C3%A1m%C3%ADt%C3%B3g%C3%A9pi%20Grafika/Gyakorlati%20Feladatok)]
## Feladatok
> **[1. Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/Sz%C3%A1m%C3%ADt%C3%B3g%C3%A9pi%20Grafika/Gyakorlati%20Feladatok/2.%20Gyakorlat/1%20Feladat)** (*Szakaszok rajzolása*)
> > - [x] ***Definiáljunk egy szakasz (Line) nevű struktúrát, amelyik tartalmazza a szakasz végpontjait és a kirajzoláshoz használt színt! (A szín lehet index vagy karakter szerint megadott, vagy RGB komponensekkel is. Utóbbi esetben célszerű definiálni egy külön Color struktúrát.)***
> > - [x] ***Nézzünk utána, hogy hogyan kezelhető SDL-ben az egéresemény! Kérdezzük le az egérkurzor pozícióját és írassuk ki a szabványos kimenetre!***
> > - [x] ***Készítsünk egy szakasz rajzoló programot, amellyel egérkattintással lehet megadni a szakaszok végpontjait! (Feltételezzük, hogy legfeljebb MAX_LINE_COUNT számú szakasz tárolható és jeleníthető meg egyszerre.)***
> > - [x] ***Készítsünk egy palettát, ahonnan kattintással kiválasztható az adott szakasz megjelenítéséhez használt színt!***
> > - [x] ***Készítsünk egy olyan változatot, melyben a szakaszok helyett beszínezett téglalapok vannak!***\
> **[2. Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/Sz%C3%A1m%C3%ADt%C3%B3g%C3%A9pi%20Grafika/Gyakorlati%20Feladatok/2.%20Gyakorlat/2%20Feladat)** (*Kör közelítése*)
> > - [x] ***Az examples/circle példában szereplő Circle struktúrát egészítsük ki egy szín attribútummal!***
> > - [ ] ***A szakasz kirajzolásához használt függvény segítségével készítsünk egy olyan programot, amely a körvonalat szakaszokkal közelíti!***
> > - [ ] ***Vizsgáljuk meg azon eseteket, amikor a közelítést a felosztáshoz használt lépések számával, a lépések szögével illetve a kirajzolt szakaszok maximális hosszával adhatjuk meg!***
> > - [x] ***Készítsünk egy programot, amellyel különböző színű köröket lehet megjeleníteni!***
> > - [x] ***Oldjuk meg, hogy az egér segítségével új köröket is meg lehessen adni! (A számukat itt is maximalizálhatjuk, például egy MAX_CIRCLE_COUNT értékkel.)***
> > - [x] ***Az egéresemények kezelésével rajzoljunk be egy + vagy x jelet azon körökbe, amely felett van éppen a kurzor. (Egyidejűleg több felett is lehet.)***
> > - [x] ***Oldjuk meg, hogy a kirajzolt köröket az egér segítségével lehessen mozgatni!***\
> **[3. Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/Sz%C3%A1m%C3%ADt%C3%B3g%C3%A9pi%20Grafika/Gyakorlati%20Feladatok/2.%20Gyakorlat/3%20Feladat)** (*Mátrixok, transzformációk*)
> > - [x] ***Nézzük át a Számítógépi grafika jegyzet 28. oldalától a koordináta transzformációkat!***
> > - [x] ***Töltsük le és nézzük át a matrices példát a grafika repository-ból!***
> > - [ ] ***Végezzük el a kódban az alábbi bővítéseket!***
> > > - [x] ***Definiáljunk egy init_identity_matrix függvényt, amelyik az egységmátrixot inicializálja!***
> > > - [x] ***Definiáljunk függvényt a mátrix skalárral való szorzásához!***
> > > - [x] ***A multiply_matrices függvényben implementáljunk a mátrix szorzást!***
> > > - [x] ***Definiáljuk a transform_point függvényt, amelyik egy síkbeli, homogén koordinátákkal adott pontra végzi el a paraméterben kapott mátrix által leírt transzformációt!***
> > > - [x] ***Írjunk 3 függvényt a transzformációkhoz, amelyik módosítja az első paraméterében kapott transzformációs mátrixot! A függvények neve legyen scale, shift, rotate! A skálázás és a forgatás origó középpontú legyen!***
> > > - [x] ***Készítsünk példát minden elkészített függvény használatára vonatkozóan!***\
> **[4. Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/Sz%C3%A1m%C3%ADt%C3%B3g%C3%A9pi%20Grafika/Gyakorlati%20Feladatok/2.%20Gyakorlat/4%20Feladat)** (*Kiegészítő feladatok*)
> > - [ ] ***Készítsünk egy verem struktúrát, amelynek az elemei transzformációs mátrixok!***
> > - [ ] ***Valósítsuk meg a push_matrix és pop_matrix műveleteket!***
> > - [ ] ***Készítsünk példát, amelyben ennek a segítségével „visszavonhatóak” lesznek a műveletek!***