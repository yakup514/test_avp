CFLAGS = -Wall -Werror -Wextra
ARCH = $(shell arch)
ifeq "$(ARCH)" "i386"
MYFLAGS = -lm -lgtest
endif
ifeq "$(ARCH)" "x86_64"
MYFLAGS =-L/usr/lib -lm -lgtest
endif

all: clean test

test: *.cpp
	g++ -std=c++17 $(CFLAGS) test.cpp testovoe_avp.cpp  $(MYFLAGS) -o  test
	./test
	
clean:
	
	rm -f test

style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.cpp
	clang-format -n *.h
	
git:
	git add *.cpp *.h
	git add Makefile
	
