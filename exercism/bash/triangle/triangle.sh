#!/bin/bash -x

function main() {
    local expected=$1
    [ $# -ne 4 ] && { echo "Wrong arguments $@" >&2 ; exit 1 ; }
    if [ "$(echo "$2 + $3 + $4 == 0" | bc -l)" -eq 1 ] ; then
        echo false
        exit 0
    fi
    local sides=( $(echo -ne "$2\n$3\n$4" | sort -g) )
    if [ "$(echo "${sides[0]} + ${sides[1]} < ${sides[2]}" | bc -l)" -eq 1 ] ;
    then
        echo false
        exit 0
    fi
    declare -A types=( [equilateral]=false [isosceles]=false [scalene]=false )
    local prev_side=
    for side in ${sides[@]} ; do
        if [ -z $prev_side ] ; then
            prev_side=$side
            types[scalene]=true
            continue
        fi
        if [ $prev_side = $side ] ; then
            if [ ${types[isosceles]} = true ] ; then
                types[equilateral]=true
                continue
            fi
            if [ ${types[scalene]} = true ] ; then
                types[scalene]=false
                types[isosceles]=true
            fi
        else
            types[equilateral]=false
        fi
        prev_side=$side
    done
    echo ${types[$expected]}
}

main "$@"
