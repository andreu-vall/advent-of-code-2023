#!/bin/bash

part1=0
cardsNumber=0
scratchcardsCount=()
while IFS= read -r line; do
    #myArray=()
    unset mySet # The set is not cleared by default
    declare -A mySet
    separator=false
    matchingCount=0
    wordCount=0
    scratchcardsCount[cardsNumber]=$((scratchcardsCount[cardsNumber] + 1))
    for word in $line; do
        word=$(echo "$word" | tr -d '\r') # Good job, Windows. Again \n problems
        wordCount=$((wordCount + 1))
        if [ $wordCount -le 2 ]; then
            continue
        fi
        if [ "$word" == "|" ]; then
            separator=true
        else
            if [ "$separator" == false ]; then
                mySet[$word]=1
                #myArray+=("$word")
            else
                if [ ${mySet[$word]} ]; then
                    matchingCount=$((matchingCount + 1))
                fi
                # for numb in "${myArray[@]}"; do
                #     if [ $numb -eq $word ]; then
                #         matchingCount=$((matchingCount + 1))
                #     fi
                # done
            fi
        fi
    done
    #echo "matchingCount: $matchingCount"
    if [ $matchingCount -eq 0 ]; then
        matchingExponent=0
    else
        matchingExponent=$((2 ** (matchingCount - 1) ))
    fi
    part1=$((part1 + matchingExponent))
    for ((i=1; i<=matchingCount; i++)); do
        scratchcardsCount[cardsNumber+i]=$((scratchcardsCount[cardsNumber+i] + scratchcardsCount[cardsNumber]))
    done
    cardsNumber=$((cardsNumber + 1))
done
echo "Part 1: " $part1

part2=0
for ((i=0; i<=cardsNumber; i++)); do
    part2=$((part2 + scratchcardsCount[i]))
done
echo "Part 2: $part2" # input: [1 2 4 8 14 1]