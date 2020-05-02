#! /bin/bash -


declare -A nucleos=( [A]=0 [C]=0 [G]=0 [T]=0 )


function print_result() {
    for tide in ${!nucleos[@]} ; do
        echo $tide: ${nucleos[$tide]}
    done
}


function main() {
    local strand="$1"
    local tide_cnt=0
    local cropped=
    [ $# -eq 0 -o -z "$strand" ] && { print_result ; exit 0 ; }
    if [ -n "${strand//[ACGT]/}" ] ; then
        echo Invalid nucleotide in strand
        exit 1
    fi
    for tide in ${!nucleos[@]} ; do
        cropped=${strand//$tide}
        tide_cnt=$(( ${#strand} - ${#cropped} ))
        nucleos[$tide]=$tide_cnt
    done
    print_result
}

main "$@"
