# Viikkoraportti 4

Käytetty aika: 13h

## Puuhailut
Tällä viikolla koodasin muut keot (paritus, D-ary, binomiaalinen) vertaisarviointia varten. Koodi on kommentoitua
ja jokseenkin siistiä, tosin parannettavaa kommentoinnin puolesta on. En ole ehtinyt testaamaan isoja testejä kummemmin
mutta nyt projektissa on mukana testigeneraattori, jonka avulla voi luoda suuria testejä ja vertailla miten eri
keot pärjää. Cppcheckstylen ilmoittamat koodinlaatupuutteet on otettu huomioon. Yksikkötestit ovat samat
jokaiselle keolle.

Opin tällä viikolla turvallisien osoittimien (shared_ptr) käytöstä joka helpottaa muistinhallintaa C++:ssa. Myös eri kekojen
rakenteita tuli opeteltua ja gdb:n (debuggeri) käyttöä tuli harjoiteltua entistä enemmän.

Vaikeuksia tuotti tällä viikolla binomiaalisen keon virheetön toteutus. Muuten meni ihan hyvin.

Seuraavaksi aion testata kekoja kattavasti eri syöterakenteilla, koska siten kekojen erot tulevat esiin. Toistaiseksi
olen käyttänyt suuria satunnaisia testejä. Testaus- ja toteutusdokumentteja pitää jatkaa. Muutan binäärikeon toteutuksen jos se nopeuttaa sitä.
