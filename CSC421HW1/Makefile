#
# csc421 421 bytes and registers
# last-update:
#    24 aug 2023: bjr- 
#
#


RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m
O= out

test:
	make test1
	make test2
	make test3
	make test4
test1: 
	cc -o count-up count-up.c
	./count-up 27 > test1.$O
	diff test1.out test1.ref
	@echo "*** ${GREEN}PASSED test1 ${NC}***"

test2:
	cc -o parity-check parity-check.c
	(echo 0 1 2 3 16 48 28 | xargs -n1 ./parity-check) > test2.$O
	diff test2.out test2.ref
	@echo "*** ${GREEN}PASSED test2 ${NC}***"

test3:
	cc -o repetition-code-3 repetition-code-3.c
	(echo 0 1 2 3 4 5 6 7  | xargs -n1 ./repetition-code-3) > test3.$O
	diff test3.out test3.ref
	@echo "*** ${GREEN}PASSED test3 ${NC}***"

test4:
	cc -o hamming-7-4 hamming-7-4.c
	(echo 0 1 2 3 4 5 6 7  8 9 10 11 12 13 14 15  | xargs -n1 ././hamming-7-4) > test4.$O
	diff test4.out test4.ref
	@echo "*** ${GREEN}PASSED test4 ${NC}***"

clean:
	-rm count-up parity-check repetition-code-3 hamming-7-4
	-rm test1.out test2.out test3.out test4.out

