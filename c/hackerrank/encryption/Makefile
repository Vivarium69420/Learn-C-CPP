CC=gcc
CFLAGS=-Wall -Werror
LDFLAGS=-lcunit -lm
OUTDIR = build
SRCS = encryption.c encryption-test.c 
OBJS = $(SRCS:%.c=$(OUTDIR)/%.o)
TARGET = $(OUTDIR)/main

$(shell mkdir -p $(OUTDIR))

$(OUTDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

.PHONY: test
test: $(TARGET)
	./build/main

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -rf $(OUTDIR)