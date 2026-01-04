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

cp ${src}/lowProd01.h ${dst}/inc
cp ${src}/libLowProd01.a ${dst}/lib
cp ${src}/libLowProd01.so ${dst}/lib
