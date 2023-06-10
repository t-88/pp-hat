#!/bin/bash
set -e

gcc example.c -o example
./example
rm example