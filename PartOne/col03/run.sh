filename=$1
prog="${filename%%.*}"
clang -Wall -o $prog $filename -lm && time ./$prog
