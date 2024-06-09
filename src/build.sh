#! /bin/bash

if [ ! -d "../build" ]
then mkdir ../build
fi

options="-std=gnu99 -Wall -Wpedantic -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast -Wno-format"
out="../build/mfsh"

gcc $options main.c -o $out
ok=$?

if [ $ok = 0 ]
then
  if [ "$1" = "run" ]
  then
    shift
    chmod u+x $out
    $out $@
  fi
else echo "build failed"
fi
