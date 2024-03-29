# (Ei valmis) Toteutusdokumentti

ChatGPT:tä (3.5) on käytetty toistaiseksi CMakeLists.txt luonnissa (projektin rakennus),
github actions tiedoston konfiguroimiseen ja testien laadun varmistamiseen. Viimeiseksi myös käytetty kommenttien uudelleensanoittamiseen hankalemmissa tapauksissa. Muuhun ei ole.

## Ohjelman yleisrakenne
### Lähdekoodi (`src` kansio)
Sisältää toteutetut kekotyypit, pääohjelman sekä suorituskykytestingenerointiohjelman:
- `binary_heap.cpp`
- `binomial_heap.cpp`
- `d_ary_heap.cpp`
- `pairing_heap.cpp`
- `main.cpp`
- `generate_custom_test.py`

### Otsikkotiedostot (`include` kansio)
Keko-algoritmien määritelmät löytyvät täältä:
- `binary_heap.hpp`
- `binomial_heap.hpp`
- `d_ary_heap.hpp`
- `pairing_heap.hpp`

### Testit (`tests` kansio)
Yksikkötestit eri kekoalgoritmeille:
- `binary_heap_test.cpp`
- `binomial_heap_test.cpp`
- `d_ary_heap_test.cpp`
- `pairing_heap_test.cpp`
- `test_main.cpp`

### Build-järjestelmä
Projektin kokoamiseen käytettävä `CMakeLists.txt`.


## Aika- ja tilavaativuudet
| Keko          | Insert             | getMin | deleteMin          | Tilavaativuus (Insert, getMin, deleteMin) |
|---------------|--------------------|--------|--------------------|------------------------------------------|
| Binäärikeko   | O(log n)           | O(1)   | O(log n)           | O(1), O(1), O(1)                          |
| Binomiaalikeko| O(log n) amortisoitu | O(1) | O(log n)       | O(1), O(1), O(1)                          |
| D-ary keko    | O(log n)           | O(1)   | O(log n)           | O(1), O(1), O(1)                          |
| Parituskeko   | Amortisoitu O(1)   | O(1)   | Amortisoitu O(log n) | O(1), O(1), O(log n)                    |

## Suorituskykyvertailu

