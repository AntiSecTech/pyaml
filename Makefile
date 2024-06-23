CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lyaml
TARGET = pyaml
SRC = pyaml.c
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
MANDIR = $(PREFIX)/share/man/man1

# Rules
all: compile

compile: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

install: $(TARGET) $(TARGET).1
	@if [ -e $(BINDIR)/$(TARGET) ]; then \
		echo "$(TARGET) already exists in $(BINDIR). Installation aborted."; \
	else \
		install -m 0755 $(TARGET) $(BINDIR)/; \
		echo "$(TARGET) installed to $(BINDIR)/"; \
	fi
	@if [ -e $(MANDIR)/$(TARGET).1 ]; then \
		echo "$(TARGET).1 already exists in $(MANDIR). Installation aborted."; \
	else \
		install -m 0644 $(TARGET).1 $(MANDIR)/; \
		echo "$(TARGET).1 installed to $(MANDIR)/"; \
	fi

uninstall:
	@if [ ! -e $(BINDIR)/$(TARGET) ]; then \
		echo "$(TARGET) does not exist in $(BINDIR). Nothing to uninstall."; \
	else \
		rm $(BINDIR)/$(TARGET); \
		echo "$(TARGET) removed from $(BINDIR)/"; \
	fi
	@if [ ! -e $(MANDIR)/$(TARGET).1 ]; then \
		echo "$(TARGET).1 does not exist in $(MANDIR). Nothing to uninstall."; \
	else \
		rm $(MANDIR)/$(TARGET).1; \
		echo "$(TARGET).1 removed from $(MANDIR)/"; \
	fi

clean:
	rm -f $(TARGET)

.PHONY: all compile install uninstall clean
