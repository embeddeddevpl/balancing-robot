#!/bin/bash

docker run --rm -v $PWD:/home/build -w /home/build docker-gcc-arm-none-eabi make all
