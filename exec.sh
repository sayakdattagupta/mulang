#!/bin/bash

gcc -o compiler main.c scan.c
./compiler in.txt
