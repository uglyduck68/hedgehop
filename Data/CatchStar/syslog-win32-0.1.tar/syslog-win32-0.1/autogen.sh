#!/bin/sh

aclocal
libtoolize --force
automake --add-missing --force
autoconf
./configure $@
