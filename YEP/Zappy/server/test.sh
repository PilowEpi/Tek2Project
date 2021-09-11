#!/bin/bash

for i in {1..1000}
do
    echo -en 'test\nFork\n' | nc localhost 4242 &
done


