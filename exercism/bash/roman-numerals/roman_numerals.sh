#!/usr/bin/env bash


NUM_MAP=([1]="I" [4]="IV" [5]="V" [6]="VI" [7]="VII" [8]="VIII" [9]="IX"
         [10]="X" [40]="XL" [50]="L" [60]="LX" [70]="LXX" [80]="LXXX" [90]="XC"
         [100]="C" [400]="CD" [500]="D" [600]="DC" [700]="DCC" [800]="DCCC"
         [900]="CM" [1000]="M")


function main() {
    for arabic in "${!NUM_MAP[@]}" ; do
        echo "${arabic}"
    done
}

main "$@"
