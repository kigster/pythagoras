# pythagoras

Super simple C++ calculator that computes either a hypothenuse from the equal cathet, or vice versa.

## Compiling

```bash
❯ make clean && make install

rm -rvf ./build/objects/*
./build/objects/src/cathetus.d
./build/objects/src/cathetus.o
./build/objects/src
rm -rvf ./build/apps/*
./build/apps/pythagoras
mkdir -p "./build/apps" "./build/objects"
clang++ -g -std=c++20 -pedantic-errors -Wall -Wextra -Werror -Iinclude/ -c src/cathetus.cpp -MMD -o build/objects/src/cathetus.o
clang++ -g -std=c++20 -pedantic-errors -Wall -Wextra -Werror -o ./build/apps/pythagoras build/objects/src/cathetus.o -L/usr/lib -lstdc++ -lm
install -m 755 build/apps/pythagoras /usr/local/bin/pythagoras
install -m 755 build/apps/pythagoras /usr/local/bin/hypotenuse
install -m 755 build/apps/pythagoras /usr/local/bin/triangle
```


## Running

```bash
❯ triangle

USAGE:
	pythagoras: -h | --help
 	pythagoras: -d | --diagonal FLOAT
 	pythagoras: -c | --catheti FLOAT [ FLOAT ]


                |\
   cathetus1 ➜  | \ ⬅︎ hypotenuse
                |  \
                |___\
               cathetus2


❯ triangle -d 9
Right Triangle:
 c1-[6.36]-•-hyp-[9.00]-•-c2-[6.36]

❯ triangle -c 3 4
Right Triangle:
 c1-[3.00]-•-hyp-[5.00]-•-c2-[4.00]
```

