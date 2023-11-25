# Testausdokumentti

Yksikkötestien kattavuusreportin [löydät täältä](https://app.codecov.io/gh/Yytsi/labcomp/tree/main/src).

Yksikkötesteissä on varmistettu, että keot toteuttavat toiminnallisuudet oikein.
Lähinnä satunnaisten lukujen ja mutkikkaiden tapauksien syöttämistä sekä reunatapauksia, joissa esimerkiksi
tyhjästä keosta koitetaan ottaa minimi (jonka pitäisi nostaa virhe).

Testaukseen on käytetty Google Test kirjastoa ja kattavuuden muodostamiseen [gcovr](https://gcovr.com/en/stable/) työkalua.

Erikseen on testattu isoja syötteitä (lisään niistä tarkemmin myöhemmin, vielä ei ole ehtinyt) ja mitattu kauan suorituksessa kestää.

Testien suorittaminen (sekä yksikkötestit, että isot testit) ja kattavuusreportin muodostaminen onnistuvat käyttöohjeessa ilmoitetulla tavalla.

<img width="526" alt="image" src="https://github.com/Yytsi/labcomp/assets/20990023/bf656605-de67-4118-8af1-b5f0d861110e">


## Suorituskykytestaus
Projektin `src` kansiosta löytyy Python- tiedosto (`generate_custom_test.py`), jonka avulla voi luoda C++ suorituskykytestausohjelman käsiteltäväksi haluamansa kokoisen testitiedoston. Sen avulla näkee miten eri keot pärjäävät. Kekojen tehokkuus riippuu syötteen rakenteesta, joten tätä pitää testata myöhemmin kattavemmin.

[Käyttöohjeessa ohjeet](https://github.com/Yytsi/labcomp/blob/main/dokumentaatio/kaytto-ohje.md) suorituskykytestaukseen
