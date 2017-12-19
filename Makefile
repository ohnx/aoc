CFLAGS=-I. -Wall -g
OUTPUT=day1p1 day1p2 day4p1

default:
	@echo "Please run make day<n>"

%: %.c
	$(CC) $(CFLAGS) $^ -o $@

day4p1: day4p1.c hashmap.c

.PHONY: clean
clean:
	rm -f $(OUTPUT)
