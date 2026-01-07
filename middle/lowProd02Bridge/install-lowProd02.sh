#!/bin/bash -x
#----------------------------------
# 注 : スクリプトの場所は移動不可
#----------------------------------
if [ $# -ne 1 ]; then

  echo "Usage : $(basename $0) インストール先"
  exit 1

fi

src=$(dirname $0)
dst=${1}

cp ${src}/lowProd02.h ${dst}/inc
cp ${src}/libLowProd02.a ${dst}/lib
cp ${src}/libLowProd02.so ${dst}/lib
