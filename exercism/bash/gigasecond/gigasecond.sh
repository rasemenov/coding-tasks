#! /bin/bash -


FMT='%Y-%m-%dT%H:%M:%S'
GIGASECOND=1000000000


function calculate_with_date() {
    [ "$#" -eq 1 ] || { echo "Wrong arguments $@" >&2 ; exit 1 ; }
    local start_date=$1
    local ts=$(date -d ${start_date} --utc +'%s')
    echo $(date --utc -d @$((GIGASECOND + ts)) +${FMT})
}


function main() {
    calculate_with_date "$@"
}

main "$@"
