#! /bin/bash

exec 3> >(while read -r line; do stdbuf -i0 -o0 -e0 echo -e "$(tput sgr0) \e[01;32m Int>> $line\e[0m" 1>&2; done)
exec 4> >(while read -r line; do stdbuf -i0 -o0 -e0 echo -e "$(tput sgr0) \e[01;32m Sol<< $line\e[0m" 1>&2; done)
exec 5> >(while read -r line; do stdbuf -i0 -o0 -e0 echo -e "$(tput sgr0) \e[01;31m   IntDEBUG>> $line\e[0m" 1>&2; done)
exec 6> >(while read -r line; do stdbuf -i0 -o0 -e0 echo -e "$(tput sgr0) \e[01;31m   SolDEBUG<< $line\e[0m" 1>&2; done)

JUDGE=$1
SOLVER=$2

shift 2

echo "$@" > .temp

tput sgr0
coproc $JUDGE 1>&3 2>&5 < .temp; $SOLVER <&p >&p 1>&4 2>&6
