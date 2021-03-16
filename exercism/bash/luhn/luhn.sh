#!/usr/bin/env bash

function exit_false() {
    echo false
    exit 0
}

function validate_to_luhn() {
    [ ${#1} -le 1 ] && exit_false
    local number="${1// /}"
    local len=${#number}
    local current=
    local sum=
    [ -n "${number//[0-9]/}" ] && exit_false
    [ ${number} = 0 ] && exit_false
    for ((indx=$(( ${len} - 1 )) ; indx >= 0; indx-=1)) ; do
        current=${number:indx:1}
        if [ $(( (len - indx - 1) % 2 )) -eq 1 ] ; then
            let current*=2
            if [ ${current} -gt 9 ] ; then
                let current-=9
            fi
        fi
        let sum+=${current}
    done
    if [ $(( sum % 10 )) -eq 0 ] ; then
        echo true
    else
        echo false
    fi
}

validate_to_luhn "$@"
