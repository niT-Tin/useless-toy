#!/bin/bash

echo -e "\e[1;40m";
clear;
while :;
do
  echo $LINES $COLUMNS $(( $RANDOM % $COLUMNS )) $(( $RANDOM % 72 ));
  # echo $LINES $COLUMNS $(( arr[$RANDOM % 3] )) $(( $RANDOM % 72 ));
  # echo $LINES $COLUMNS 40 $(( $RANDOM % 72 ));
  sleep 0.05;
  # sleep 0.5;
done
