# Testausdokumentti

Yksikkötestien kattavuusreportin [löydät täältä](https://app.codecov.io/gh/Yytsi/labcomp/tree/main/src) avaamalla minkä tahansa
muun tiedoston kuin main.cpp (joka vain käynnistää testit) tai heap_benchmarking.cpp (joka suorittaa suuria testejä lokaalisti).

Yksikkötesteissä on varmistettu, että keko (toistaiseksi vain binäärikeko) toteuttaa toiminnallisuudet oikein.
Lähinnä satunnaisten lukujen ja mutkikkaiden tapauksien syöttämistä sekä reunatapauksia, joissa esimerkiksi
tyhjästä keosta koitetaan ottaa minimi (jonka pitäisi nostaa virhe).

Testaukseen on käytetty Google Test kirjastoa ja kattavuuden muodostamiseen [gcovr](https://gcovr.com/en/stable/) työkalua.

Erikseen on testattu isoja syötteitä (toistaiseksi vain 1) ja mitattu kauan suorituksessa kestää.

Testien suorittaminen (sekä yksikkötestit, että isot testit) ja kattavuusreportin muodostaminen onnistuvat käyttöohjeessa ilmoitetulla tavalla.

<img width="417" alt="image" src="https://github.com/Yytsi/labcomp/assets/20990023/f8b89005-4981-4855-947d-8edf13af390d">

<img width="454" alt="image" src="https://github.com/Yytsi/labcomp/assets/20990023/94652c73-97b2-4c46-ac11-1b25af8ee653">
