# (Ei valmis) Toteutusdokumentti

ChatGPT:tä (3.5) on käytetty toistaiseksi CMakeLists.txt luonnissa (projektin rakennus),
github actions tiedoston konfiguroimiseen ja testien laadun varmistamiseen. Muuhun ei ole.

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
| Binomiaalikeko| O(log n) amortisoitu | O(log n) | O(log n)       | O(1), O(1), O(1)                          |
| D-ary keko    | O(log n)           | O(1)   | O(log n)           | O(1), O(1), O(1)                          |
| Parituskeko   | Amortisoitu O(1)   | O(1)   | Amortisoitu O(log n) | O(1), O(1), O(log n)                    |

## Suorituskykyvertailu
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
