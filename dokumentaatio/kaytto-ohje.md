# Käyttöohje

Aluksi kloonaa repositorio `git clone` komennolla ja mene sen sisään

Asenna riippuvuudet:
```
sudo apt-get install cmake libgtest-dev gcovr lcov
```

Joissakin tapauksissa GTest vaatii manuaalisen kokoamisen. Se menee näin:
```
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib
```

Kokoa projekti:
```
cmake .
make
```

Suorita testit:
```
make test
```

Luo kattavuusreportti:
```
lcov --capture --directory . --output-file coverage.info
lcov --remove coverage.info '/usr/*' --output-file coverage.info
lcov --list coverage.info
genhtml coverage.info --output-directory out
```

Huom. Valitettavasti en ole testannut linuxilla (itse käytän macia). Korjaan tätä myöhemmin tarvittaessa.
