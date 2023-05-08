SRC1=testIsspace
SRC2=testIsdigit

test: $(SRC1) $(SRC2)
	./$(SRC1)
	./$(SRC2)

$(SRC1): $(SRC1).c

$(SRC2): $(SRC2).c

clean:
	rm -f $(SRC1) $(SRC2)

.PHONY: test clean
