#!/bin/bash

mkdir -p png

INPUT_FILE="$1"

./ProgLangLab1 "$INPUT_FILE"

for dot_file in *.dot; do
    if [ -f "$dot_file" ]; then
        png_file="png/${dot_file%.dot}.png"
        dot -Tpng "$dot_file" -o "$png_file"
        echo "Converted: $dot_file -> $png_file"
    fi
done