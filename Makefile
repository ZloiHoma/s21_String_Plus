CC=gcc
CFLAGS= -Wall -Werror -Wextra -std=c11
LIB = s21_string.a
GCOV=-fprofile-arcs -ftest-coverage
TESTS = test.c
OS = $(shell uname)
C_FILES = s21*.c
H_FILES = *.h
O_FILES = *.o

ifeq ($(OS), Darwin)
	LC=-lcheck
else
	LC=-lcheck -lsubunit -pthread -lrt -lm  
endif

all: $(LIB)

s21_string+: $(LIB)

$(LIB): 
	$(CC) $(CFLAGS) -c $(C_FILES)    
	ar rc $(LIB) $(O_FILES)
	ranlib $(LIB)
	rm -rf $(O_FILES)

test: clean $(LIB) 
	$(CC) $(CFLAGS) $(GCOV) $(C_FILES) $(TESTS) -o test $(LC)
	./test 

gcov_report: clean test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info    
	open ./report/index.html

style:
	clang-format -style=Google -n $(C_FILES) $(H_FILES) $(TESTS)

get_style:
	clang-format -style=Google -i $(C_FILES) $(H_FILES) $(TESTS)

clean:   
	rm -rf $(O_FILES) *.a *.gcda *.gcno
	rm -rf *.info *.gcov *.html
	rm -rf *.dSYM *.info *.log
	rm -rf test report .check debug 

rebuild: clean all
