CFLAGS=-I. -Wall
OUTPUT=day1 day2

default:
	@echo "Please run make day<n>"

day1: day1.c
	$(CC) $(CFLAGS) $^ -o $@

day4: day4.c hashmap.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OUTPUT)
