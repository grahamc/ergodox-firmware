#!/bin/bash

set -e
set -x

sudo apt-get update
sudo apt-get -y install gcc-avr binutils-avr avr-libc make git-core

cd /vagrant
[[ -z $(git status -s) ]]

git clean -dfx

cd src
make

