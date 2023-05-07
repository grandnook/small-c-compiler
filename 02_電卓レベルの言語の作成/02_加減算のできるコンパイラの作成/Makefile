CFLAGS=-std=c11 -g -static
SRC=02_cc

$(SRC): $(SRC).c

test: $(SRC)
	bash test.sh

clean:
	rm -f $(SRC) tmp*

.PHONY: test clean