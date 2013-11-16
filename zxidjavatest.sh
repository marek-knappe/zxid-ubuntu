#!/bin/sh
# 20131116, sampo@synergetics.be
#
# If this test does not work, you may want to play with
# 1. LD_LIBRARY_PATH to make sure libzxidjni.so is found
# 2. Move libzxidjni.so or zxidjni.dll to a system location
#    where dynalic link libraries are searched by default.
# 3. Playing with -classpath and -Djava.library.path may
#    help in locating the .class files that make up
#    the zxidjava package

#java zxidjavatest
LD_LIBRARY_PATH=./zxidjava java zxidjavatest
#LD_LIBRARY_PATH=./zxidjava java -classpath . -Djava.library.path=zxidjava zxidjavatest
#LD_LIBRARY_PATH=./zxidjava java -classpath .:zxidjava -Djava.library.path=zxidjava zxidjavatest

#EOF