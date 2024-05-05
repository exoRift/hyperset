g++ test/datagen.cpp -o gen
g++ test/sanity.cpp -std=c++11 src/*.cpp comparison/*.cpp -o sanity
g++ test/parity.cpp src/*.cpp comparison/*.cpp -o parity
g++ test/hyper.cpp src/*.cpp comparison/*.cpp -o hyper
g++ test/regular.cpp src/*.cpp comparison/*.cpp -o regular