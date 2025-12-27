#!/usr/bin/bash
#-----------------------------------------
# 簡易的なライブラリインストールスクリプト
#-----------------------------------------
destDir="../../../prodB/build/"

make

cp com.h ${destDir}/inc
cp libCom.a ${destDir}/lib
cp libCom.so ${destDir}/lib
