if [ x$1 = x ] ; then
    g++ -I ../ -I sorter \
    -o main.out -std=c++11 -L ../macos_lib -lgtest *.cpp
elif [ x$1 = x--DEBUG ] ; then
    g++ -I ../ -I sorter -DDEBUG \
    -o main.out -std=c++11 -L ../macos_lib -lgtest *.cpp
fi
