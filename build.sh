#!/bin/bash

set -e
set -x

sudo apt-get update
sudo apt-get -y install gcc-avr binutils-avr avr-libc make git-core

cd /vagrant

for i in `git clean -ndX | grep -v vagrant | cut -d" " -f3`; do
  rm $i;
done

cd src
make LAYOUT="graham"

