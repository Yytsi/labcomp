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
Kekoja on testattu toistaiseksi satunnaisilla syötteillä (src/generate_custom_test.py). Tässä tuloksia nopeuksista (suoritettu Macbook air 13 M1 kannettavalla):


![vertaus](https://github.com/Yytsi/labcomp/assets/20990023/0aa9730c-1e9d-4473-9e82-3aae5cc7aaef)

    600 M random
        Max: 100,000,000
        BinaryHeap: 98.6772 sekuntia
        DaryHeap: 101.245 sekuntia
        PairingHeap: 137.009 sekuntia

    200 M random
        Max: 12,345,678
        BinaryHeap: 26.9437 sekuntia
        DaryHeap: 27.8651 sekuntia
        PairingHeap: 44.4189 sekuntia

    20 M random
        Max: 12,345,678
        BinaryHeap: 2.32896 sekuntia
        DaryHeap: 2.44041 sekuntia
        PairingHeap: 4.38843 sekuntia
        BinomialHeap: 29.2028 sekuntia

    5 M random
        Max: 100,000,000
        BinaryHeap: 0.523176 sekuntia
        DaryHeap: 0.559004 sekuntia
        PairingHeap: 1.09814 sekuntia
        BinomialHeap: 5.39302 sekuntia

Huomioi, ettei binomiaalikekoa ole otettu suurempiin (200M ja 600M) testeihin mukaan, koska sen suoritusaika on liian pitkä. Kuten 20 miljoonan operaation testi näyttää, binomiaalikeolla kestää moninkertainen aika muihin verrattuna.

[Käyttöohjeessa ohjeet](https://github.com/Yytsi/labcomp/blob/main/dokumentaatio/kaytto-ohje.md) suorituskykytestaukseen
