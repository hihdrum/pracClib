#!/bin/bash -x

if [ $# -ne 2 ]; then

  echo "Usage : $(basename $0) ライブラリトップ(インストール元) インストール先"
  exit 1

fi

src=${1}
dst=${2}

cp ${src}/middle.h ${dst}/inc
cp ${src}/libMiddle.a ${dst}/lib
cp ${src}/libMiddle.so ${dst}/lib
