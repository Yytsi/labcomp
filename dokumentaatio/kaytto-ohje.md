# Käyttöohje

## Yksikkötestien suorittaminen ja kattavuusreportti

Aluksi kloonaa repositorio `git clone` komennolla ja mene sen sisään

Asenna riippuvuudet:
```
sudo apt-get update
sudo apt-get install cmake g++ libgtest-dev python3-pip
```

Joissakin tapauksissa GTest vaatii manuaalisen kokoamisen. Se menee näin:
```
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib
```

Asenna gcovr:
```
pip3 install gcovr
```

Rakenna ja käännä testit:
```
cmake -DCMAKE_BUILD_TYPE=Debug .
make
```

Suorita testit:
```
./runUnitTests
```

Jos saat virheen äskeisestä, niin poista .gcda tiedostot projektista (varmista, että olet projektin juurikansiossa!):
```
find . -name "*.gcda" -delete
```

Jos äskeinen ei toimi tai muuten vain haluaa nähdä että kaikki testit ylipäätään menee läpi:
```
make test
```

Luo kattavuusreportti:
```
gcovr -r . --html --html-details -o coverage.html
```

Avaa coverage.html tiedosto.

## Suorituskykytestit
Huom: varmista, että olet suorittanut yksikkötesteihin kuuluvat komennot.

Käännä suorituskykytestiohjelma:
```
cmake .
make benchmark
```

Suorita suorituskykytestiohjelma syötteellä (toistaiseksi ainut):
```
./benchmark < benchmark_tests/big.txt
```

## Koodinlaadun analysointi
Huom: varmista, että olet suorittanut yksikkötesteihin kuuluvat komennot.

Asenna cppcheck
```
sudo apt-get install cppcheck
```

Perustarkastus:
```
cppcheck --enable=warning src/ include/
```

Laajempi tarkastus:
```
cppcheck --enable=all --inconclusive --std=c++11 --suppress=missingIncludeSystem src/ include/
```

Tulosten tallennus:
```
cppcheck src/ include/ 2> cppcheck_results.txt
```

Nyt tulokset löytyvät cppcheck_results.txt tiedostosta.

Huom. Valitettavasti en ole vielä testannut linuxilla (itse käytän macia), mutta pitäisi toimia. Korjaan tätä myöhemmin tarvittaessa.
