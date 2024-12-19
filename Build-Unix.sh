#!/bin/bash

if [ ! -d "Build" ]; then
  mkdir Build

cd Build
cmake ..
make ..
