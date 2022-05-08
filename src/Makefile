DEBUG=-g
CC=gcc 
WFLAGS=-Wall -Wextra -Werror #-fsanitize=address
COV=--coverage
LFLAGS=-c
LCHECK= `pkg-config --libs check`
S1=parse
S2=stack
S4=test
EXE1=$(S4).out
BD = ../build/

.PHONY: all install uninstall clean dvi tests gcov_report lint leaks git cpp

all: build

build: clean mk replication
	cd $(BD); qmake SmartCalc.pro
	make -C $(BD)
	cd $(BD); rm -rf *.c *.h *.cpp *.ui *.o

replication: 
	cp SmartCalc.pro $(BD)
	cp *.c *.h *.cpp *.ui $(BD)

install: build
	mkdir $(HOME)/Desktop/SmartCalc_v1.0/
	cp -rf $(BD)SmartCalc.app $(HOME)/Desktop/SmartCalc_v1.0/
	make clean

uninstall:
	rm -rf $(HOME)/Desktop/SmartCalc_v1.0/

dvi: 
	open -a "Google Chrome" description.html

$(S1).a: $(S1).o $(S2).o
	ar r $(S1).a $(S2).o

$(S2).a: $(S1).o $(S2).o
	ar r $(S2).a $(S1).o

$(S1).o:
	$(CC) -c $(S1).c -o $(S1).o

$(S2).o:
	$(CC) -c $(S2).c -o $(S2).o

tests: clean $(S4)
	./$(EXE1)

$(S4): $(S1).a $(S2).a $(S4).o
	$(CC) $(S4).o $(S1).a $(S2).a -o $(EXE1) $(LCHECK)

$(S4).o:
	gcc -c $(S4).c -o $(S4).o

gcov_report: tests
	$(CC) --coverage $(S1).c $(S2).c $(S4).c -o test $(LCHECK)
	./test
	lcov -t "test" -c -d . -o test.info
	genhtml test.info -o report
	open -a "Safari" report/index.html


clean:
	rm -f *.a *.gcda *.gcno *.o *.info *.out *.gcov *.cfg ../.DS_Store
	rm -f -r report* *.dSYM
	rm -rf ./test && rm -rf ./gcov_report
	rm -rf $(BD)*
	rm -rf $(BD)

cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem $(S1).c $(S1).h

leaks: tests
	CK_FORK=no leaks -atExit -- ./$(EXE1)

lint:
	cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py --extensions=c *.c
	rm -f CPPLINT.cfg

mk:
	mkdir ../build
