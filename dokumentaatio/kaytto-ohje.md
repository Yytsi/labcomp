# Käyttöohje

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

Luo kattavuusreportti:
```
gcovr -r . --html --html-details -o coverage.html
```

Avaa coverage.html tiedosto.

Huom. Valitettavasti en ole vielä testannut linuxilla (itse käytän macia), mutta pitäisi toimia. Korjaan tätä myöhemmin tarvittaessa.
