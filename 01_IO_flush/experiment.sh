#!/bin/bash

# Компиляция программы
gcc main.c -o main

# Эксперименты с консолью
echo "[console] linebreaks=false, flush=false"
./main 0 0 0
echo -e "\n"

echo "[console] linebreaks=false, flush=true"
./main 0 1 0
echo -e "\n"

echo "[console] linebreaks=true, flush=false"
./main 1 0 0
echo -e "\n"

echo "[console] linebreaks=true, flush=true"
./main 1 1 0


echo "[output.txt] linebreaks=false, flush=false" >> output.txt
./main 0 0 1
echo -e "\n" >> output.txt

echo "[output.txt] linebreaks=false, flush=true" >> output.txt
./main 0 1 1
echo -e "\n" >> output.txt


echo "[output.txt] linebreaks=true, flush=false" >> output.txt
./main 1 0 1
echo -e "\n" >> output.txt

echo "[output.txt] linebreaks=true, flush=true" >> output.txt
./main 1 1 1
echo -e "\n" >> output.txt
