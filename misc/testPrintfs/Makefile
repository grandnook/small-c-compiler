SRC1=testPrintf
SRC2=testSprintf
SRC3=testFprintf
SRC4=testFprintfToPrintf
SRC5=testVfprintf_v1
SRC6=testVfprintf_v2

test: $(SRC1) $(SRC2) $(SRC3) $(SRC4) $(SRC5) $(SRC6)
	./$(SRC1)
	./$(SRC2)
	./$(SRC3)
	cat tmp.txt
	./$(SRC4)
	./$(SRC5)
	./$(SRC6)

$(SRC1): $(SRC1).c

$(SRC2): $(SRC2).c

$(SRC3): $(SRC3).c

$(SRC4): $(SRC4).c

$(SRC5): $(SRC5).c

$(SRC6): $(SRC6).c

clean:
	rm -f $(SRC1) $(SRC2) $(SRC3) tmp.txt $(SRC4) $(SRC5) $(SRC6)

PHONY: test clean