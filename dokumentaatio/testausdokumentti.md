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
Tärkeä huomio, seuraavat testit, joissa binomiaalinen keko on mukana on tehty versiolla, jossa minimin hakeminen vei aikaa O(log n). Vaihdoin sen sittemmin O(1) toteutukseen, mutta eroa ei juurikaan ole, koska se lisäsi vakiokertoimen muihin operaatioihin (joissa kyllä pysyi omat vaativuudet samoina). Mainittakoon myös, että valitsin D-ary kekojen asteluvuksi D = 4, eli neljä lasta enintään solmua kohti.

### Satunnaiset operaatiot
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

### Vain lisäysoperaatiot
    
    1 M only additions
        Max: 100,000,000
        BinaryHeap: 0.055303 sekuntia
        DaryHeap: 0.047484 sekuntia
        PairingHeap: 0.168849 sekuntia
        BinomialHeap: 0.723102 sekuntia
    
    5 M only additions
        Max: 100,000,000
        BinaryHeap: 0.292657 sekuntia
        DaryHeap: 0.251329 sekuntia
        BinomialHeap: 3.66029 sekuntia
    
    10 M only additions
        Max: 100,000,000
        BinaryHeap: 0.586065 sekuntia
        DaryHeap: 0.506172 sekuntia
        BinomialHeap: 7.54771 sekuntia

Parituskekoa ei otettu viimeiseen mukaan muistin puutteen takia. Yritän tätä saada myöhemmin säädettyä toisella koneella, koska macilla on hankala muuttaa pinon muistirajaa.

![vertaus_add](https://github.com/Yytsi/labcomp/assets/20990023/3797d16f-3f29-4350-b660-a500ea2ef7d0)

### Sekoitetut lisäys ja poisto

    1 M add and delete
        Max: 100,000,000
        BinaryHeap: 0.123254 sekuntia
        DaryHeap: 0.132351 sekuntia
        PairingHeap: 0.246787 sekuntia
        BinomialHeap: 1.1159 sekuntia
    
    5 M add and delete
        Max: 100,000,000
        BinaryHeap: 0.71377 sekuntia
        DaryHeap: 0.750591 sekuntia
        PairingHeap: 1.23873 sekuntia
        BinomialHeap: 11.1068 sekuntia
    
    10 M add and delete
        Max: 100,000,000
        BinaryHeap: 1.47577 sekuntia
        DaryHeap: 1.56003 sekuntia
        PairingHeap: 2.54455 sekuntia
        BinomialHeap: 19.8731 sekuntia
    
    50 M add and delete
        Max: 100,000,000
        BinaryHeap: 7.71747 sekuntia
        DaryHeap: 8.00719 sekuntia
        PairingHeap: 12.6839 sekuntia

Binomiaalikekoa ei otettu viimeiseen testiin mukaan valtavan suoritusajan vuoksi. Lisäksi näissä testeissä keon koko ei ikinä ylitä 1 miljoonaa arvoa.

![vertaus_add_delete](https://github.com/Yytsi/labcomp/assets/20990023/362e5f59-cfb2-49df-9018-a10ce6fd1872)

## Johtopäätelmät
Binäärikeko ja D-ary-keko ovat selkeitä kilpailijoita kun taas binomiaali- sekä parituskeko eivät niin loista näiden primitiivisten operaatioiden (lisää, hae minimi, poista minimi) kanssa.

[Käyttöohjeessa ohjeet](https://github.com/Yytsi/labcomp/blob/main/dokumentaatio/kaytto-ohje.md) suorituskykytestaukseen
