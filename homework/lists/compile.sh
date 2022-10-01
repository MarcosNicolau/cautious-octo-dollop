echo "What exercise do you want to build? (1, 2, 3)"
read EX
g++ ./$EX.cpp -o build
./build