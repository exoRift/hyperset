g++ test/datagen.cpp -o gen
g++ test/parity.cpp src/*.cpp comparison/*.cpp -o parity
g++ test/hyper.cpp src/*.cpp comparison/*.cpp -o hyper
g++ test/regular.cpp src/*.cpp comparison/*.cpp -o regular