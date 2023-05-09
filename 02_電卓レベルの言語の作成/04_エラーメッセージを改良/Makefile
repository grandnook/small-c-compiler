CFLAGS=-std=c11 -g -static
SRC=02_cc

$(SRC): $(SRC).c

test: $(SRC)
	bash test.sh

debug: $(SRC)
	bash -x test.sh

clean:
	rm -f $(SRC) tmp*

.PHONY: test debug clean