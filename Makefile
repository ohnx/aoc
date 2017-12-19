CFLAGS=-Isrc/ -Wall -g
OUTPUT=day/*

default:
	@echo "Please run make day<n>"

day/%: src/day%.c
	@mkdir -p day/
	$(CC) $(CFLAGS) $^ -o $@

day/4p1: src/day4p1.c src/hashmap.c

.PHONY: clean
clean:
	rm -f $(OUTPUT)
