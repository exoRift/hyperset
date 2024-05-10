g++ test/datagen.cpp -O3 -std=c++11 -o gen
g++ test/sanity.cpp -O3 -std=c++11 src/*.cpp comparison/*.cpp -o sanity
g++ test/parity.cpp -O3 -std=c++11 src/*.cpp comparison/*.cpp -o parity
g++ test/hyper.cpp -O3 -std=c++11 src/*.cpp comparison/*.cpp -o hyper
g++ test/regular.cpp -O3 -std=c++11 src/*.cpp comparison/*.cpp -o regular