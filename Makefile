# Values
CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lyaml
TARGET = pyaml
SRC = pyaml.c
PREFIX = /usr/local

# Rules
all: compile

compile: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

install: $(TARGET)
	@if [ -e $(PREFIX)/bin/$(TARGET) ]; then \
		echo "$(PREFIX)/bin/$(TARGET) already exists. Installation aborted."; \
	else \
		install -m 0755 $(TARGET) $(PREFIX)/bin/; \
		echo "$(TARGET) installed to $(PREFIX)/bin/"; \
	fi

uninstall:
	@if [ -e $(PREFIX)/bin/$(TARGET) ]; then \
		rm $(PREFIX)/bin/$(TARGET); \
		echo "$(TARGET) removed from $(PREFIX)/bin/"; \
	else \
		echo "$(PREFIX)/bin/$(TARGET) does not exist. Nothing to do."; \
	fi

clean:
	rm -f $(TARGET)

.PHONY: all compile install uninstall clean
