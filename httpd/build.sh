#!/usr/bin/env bash

set -x
set -e

srcdir="${PWD}/httpd-2.4.12"
builddir="${PWD}/build"
installdir="${PWD}/install"
archive="httpd-2.4.12.tar.bz2"

wget -c "http://apache.mirror.iweb.ca/httpd/${archive}"
tar -xf "${archive}"

mkdir -p "${builddir}" "${installdir}"

pushd "${builddir}"

"${srcdir}/configure" CFLAGS="-g3 -O0" --prefix="${installdir}"

make -j 4

make install

popd
