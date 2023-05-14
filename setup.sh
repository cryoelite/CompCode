#!/bin/bash
REF="${1//\//}"
NEW="${2//\//}"
echo "Creating new directory $NEW"
mkdir $NEW
if [ -d $NEW ] && [ -d $REF ]; then
    cp "$REF"/* $NEW
    cd "$NEW/"
    rm -f *.exe
    if [ -f "$REF.cpp" ]; then
        mv "$REF.cpp" "$NEW.cpp"
    else
        touch "$NEW.cpp"
    fi
fi
