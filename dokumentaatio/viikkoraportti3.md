# Viikkoraportti 3

Käytetty aika: 6h

## Puuhailut
Tällä viikolla korjasin github actionsin, joka vaati yrittämistä. Vaikeus johtui
epäsopivan työkalun (lcov) käyttämisestä. `gcovr` toimii paljon paremmin. Nyt on koodipohja, jolla voi suorittaa
suurempia lokaaleja testejä, mutta muutan sitä vielä myöhemmin. Nyt voi toteuttaa muut keot ja sijoittaa samaan tiedostoon
ja mitata niiden aikaa samoilla lokaaleilla testeillä. Myös checkstyle on nyt paikallaan, tosin koodi ei saa täysiä pisteitä.

Lisäsin yksikkötestien määrää ja nyt niiden suorittaminen myös lokaalisti pitäisi toimia mukavasti.

En ole vielä toteuttanut muita kekoja taikka ohjelmoinut osoittimilla binäärikekoa, mutta nyt on hyvä koodipohja ja kaikki toimii.

Opin tällä viikolla Github Actionsista, Codecovista, cppcheck-koodinlaatutyökalusta, gcovr-työkalusta sekä jaetuista osoittimista (C++ tietorakenne).

Github actions tuotti aluksi vaikeuksia, mutta se on nyt selvitetty.

Seuraavaksi toteutan muita kekoja.
