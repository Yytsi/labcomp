# Testausdokumentti

Yksikkötestien kattavuusreportin [löydät täältä](https://app.codecov.io/gh/Yytsi/labcomp/tree/main/src) avaamalla minkä tahansa
muun tiedoston kuin main.cpp (joka vain käynnistää testit) tai heap_benchmarking.cpp (joka suorittaa suuria testejä lokaalisti).

Yksikkötesteissä on varmistettu, että keko (toistaiseksi vain binäärikeko) toteuttaa toiminnallisuudet oikein.
Lähinnä satunnaisten lukujen ja mutkikkaiden tapauksien syöttämistä sekä reunatapauksia, joissa esimerkiksi
tyhjästä keosta koitetaan ottaa minimi (jonka pitäisi nostaa virhe).

Testaukseen on käytetty Google Test kirjastoa ja kattavuuden muodostamiseen [gcovr](https://gcovr.com/en/stable/) työkalua.

Erikseen on testattu isoja syötteitä (toistaiseksi vain 1) ja mitattu kauan suorituksessa kestää.

Testit (sekä yksikkötestit, että isot testit) voi suorittaa käyttöohjeessa ilmoitetulla tavalla.