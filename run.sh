#!/bin/bash
set -e

gcc main.c -o main
./main
rm main