#!/bin/bash

make

echo "################################################################"
echo "The original price table is :"
cat price.txt 
echo "################################################################"

echo "################################################################"
echo "test suit one"
echo "input is :"
cat testinput/input1.txt 
echo "output is :"
./supermarket < testinput/input1.txt
echo "################################################################"
echo ""

echo "################################################################"
echo "test suit two"
echo "input is :"
cat testinput/input2.txt 
echo "output is :"
./supermarket < testinput/input2.txt
echo "################################################################"
echo ""

echo "################################################################"
echo "test suit three"
echo "input is :"
cat testinput/input3.txt 
echo "output is :"
./supermarket < testinput/input3.txt
echo "################################################################"
echo ""

echo "################################################################"
echo "test suit four"
echo "input is :"
cat testinput/input4.txt 
echo "output is :"
./supermarket < testinput/input4.txt
echo "################################################################"
echo ""

exit 0
