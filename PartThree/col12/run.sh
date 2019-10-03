filename=$1
prog="${filename%%.*}.o"
clang -Wall -o $prog $filename && time ./$prog
