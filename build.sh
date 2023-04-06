#!/bin/bash

# Usage: ./build.sh basic-tutorial-3

# $1 is the tutorial name, eg: basic-tutorial-3
gcc "$1".c -o $1 $(pkg-config --cflags --libs gstreamer-1.0)
