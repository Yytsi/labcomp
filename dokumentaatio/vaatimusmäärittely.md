# Vaatimusmäärittely
## Ohjelmointikieli
Käytän projektissa C++:ssaa, mutta pystyn vertaisarvioimaan C++:aa, Javascriptia,
Pythonia, Rubya sekä Javaa.

## Toteutukset
Implementoin neljä keko-tietorakennetta: binäärikeko, binomikeko, D-keko ja paritettu keko.
Tämän projektin tarkoitukseen on syytä implementoida noista vain operaatiot: etsi pienin, poista pienin ja lisää luku x.

## Tehokkuuden mittaus ja vertailu
Toteutetuilla operaatioilla voi toteuttaa prioriteettijonon, jota
voi soveltaa lukuisiin ongelmiin, mutta olen valinnut kohteeksi Dijkstran algoritmin (tosin tätä voi muuttaa)
joka hyödyntää prioriteettijonoa etsiessään lyhyimpää polkua verkossa.

Valitsin kyseiset keot koska niiden suoritusaika tulisi riippua syötteiden muodoista, joten testien myötä
pitäisi suurin piirtein selvitä mihin tilanteisiin kukin tietorakenne sopii.

## Syöte
Sijoitan syötteet tekstitiedostoihin, jotka automaattisesti syötetään ohjelmaan testattavaksi.
Alustavasti Dijkstran algoritmin tapauksessa tulen antamaan verkkoja.

## Aikavaativuudet
Kuvassa Operation sarakkeen Binary vastaa binäärikekoa, Binomial binomikekoa ja Pairing puolestaan paritettua kekoa.
Paritetusta keosta poisto ja binomiaalisen kekoon lisäys (tosin binomiaalisen keon tapauksessa vain ensimmäisen lisäyksen jälkeen ketjussa olevat lisäykset) [amortisoituvat](https://stackoverflow.com/questions/200384/what-is-constant-amortized-time).

<img width="365" alt="image" src="https://github.com/Yytsi/labcomp/assets/20990023/dfaef998-070e-41d2-8e31-82f7ea112199">

Kuvakaappauksen lähde: [Wikipedia](https://en.wikipedia.org/wiki/Binary_heap)

D-ary keon aikavaativuudet:
 - Etsi pienin: O(1)
 - Poista pienin: O(d log_d n), jossa d on lapsien lukumäärä per solmu.
 - Lisäys: O(d log_d n), jossa d on lapsien lukumäärä per solmu.

## Lähteet
[D-ary keko](https://www.geeksforgeeks.org/k-ary-heap/)

[Keoista löytyi wikipediasta](https://en.wikipedia.org/wiki/Binary_heap)

## Kurssi
Tämä suoritus on osa tietojenkäsittelytieteen kanditaattia (TKT).

## Kielivalinnat
Suomi, mutta englanniksi koodi, kommentit ja koodin dokumentointi.
