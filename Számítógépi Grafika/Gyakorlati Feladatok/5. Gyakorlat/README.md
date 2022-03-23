# 5. Gyakorlat [[Vissza](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/Sz%C3%A1m%C3%ADt%C3%B3g%C3%A9pi%20Grafika/Gyakorlati%20Feladatok)]

## Blender
> ***A modellek szerkesztéséhez Blender-t értdemes használni: https://www.blender.org/***\
> ***A modell exportálásánál figyelni kell arra, hogy***\
> - ***a modell csak háromszögeket tartalmazzon (Triangle faces kapcsoló),***
> - ***a felfele irány megfelelően legyen megadva (általában Z szokott lenni),***
> - ***a modell a normálvektorokat és a textúrakoordinátákat is tartalmazza (ez alapértelmezés szerint jól van),***
> - ***csak a kijelölt vagy az összes objektumot el kell-e menteni (részemről inkább a kijelöltre hagyatkozom).***\
> ***A modellek előkészítéséről és használatáról itt található egy videó: https://www.uni-miskolc.hu/~matip/_downloads/grafika/animals.ogv***

## Statikus Library 
> **[OBJ loader statikus library használata](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/Sz%C3%A1m%C3%ADt%C3%B3g%C3%A9pi%20Grafika/Gyakorlati%20Feladatok/5.%20Gyakorlat/utils/obj)**
> > ***Keressük meg az me-courses repository-ban a utils nevű mappát!***\
> > ***A statikus library a utils/obj jegyzékben van.***\
> > ***Lépjünk be a jegyzékbe, és adjuk ki a make parancsot.***\
> > ***Létre fog jönni egy libobj.a fájl. Ezt másoljuk be a fordító lib jegyzékébe.***\
> > ***A utils/obj/include jegyzékben lévő header fájlokat másoljuk be a fordító include/obj nevű jegyzékébe. (Az obj nevű jegyzék nem létezik, azt létre kell hozni.)***

## Feladatok
> 1. **[Feladat](https://github.com/OraveczJozsef/Miskolci_Egyetem/tree/main/Sz%C3%A1m%C3%ADt%C3%B3g%C3%A9pi%20Grafika/Gyakorlati%20Feladatok/4.%20Gyakorlat/1%20Feladat)**
> > - [x] ***Töltsük le és nézzük át a 'origin' példát az 'me-courses' repository-ból, majd végezzük el az alábbi módosításokat!***
> > - [x] ***Oldjuk meg, hogy a kamerát függőlegesen is lehessen mozgatni felfelé és lefelé 'q' és 'e' billentyűk segítségével!***
> > - [x] ***Állítsuk be a 'j' és 'l' billentyűkre a kamera balra és jobbra forgatását!***
> > - [x] ***Az egységkockán belül jelenítsünk meg egy színes háromszöget, melynek sárga, cián és magenta színűek a sarkai!***
> > - [ ] ***Jelenítsünk meg egy szürke (tesszellált) gömböt az egységkockán belül!***
> > - [ ] ***Válasszuk kicsire a tesszelláció mértékét, és forgassuk meg a gömböt egyenletes sebességgel valamelyik tengely körül!***
> > - [ ] ***Írjuk át a kamera kezelését úgy, hogy a Google Maps-hez hasonlóan lehessen forgatni a nézetet!***
> > - [x] ***Rajzoljunk ki egy sakktábla mintát az egységkockánk x-y síkjába (ahol z értéke 0)!***
> > - [ ] ***Rajzoljuk ki egy henger és egy kúp közelítését! Használjuk hozzá a triangle strip és triangle fan primitíveket!***