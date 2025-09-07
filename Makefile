# Debian-only Makefile for building tests against lib/libtree.so

# The C compiler to use
CC       := gcc

# Compiler warnings, C standard, debug info, and header search path.
# _POSIX_C_SOURCE=200809L requests features from the 2008 POSIX standard.
# In this code, we need it so that functions like strdup(), getline(), and
# other POSIX-specific functions are declared in system headers on Linux.
# Without it, the compiler might warn that these functions are “implicit”
# or “undeclared” because they are hidden by default in strict C mode.
CFLAGS   := -Wall -Wextra -std=c11 -g -Iinclude -D_POSIX_C_SOURCE=200809L

# Linker flags:
#  -Wl, : pass the following to the linker
#  -rpath,'$$ORIGIN/../lib' :
#       embed a runtime library search path so the program can find libtree.so
#       at run time, relative to the executable location:
#       $$ORIGIN means "the folder containing the executable" (escaped for Make)
#  -Llib  : also look in ./lib when linking
LDFLAGS  := -Wl,-rpath,'$$ORIGIN/../lib' -Llib

# Ask pkg-config where the Check unit test headers and libraries are.
# The `2>/dev/null` hides error messages if Check is not installed,
# so the Makefile doesn't fail just because pkg-config can't find it.
# This means that if Check isn't present, these variables will simply be empty.
CHECK_CFLAGS := $(shell pkg-config --cflags check 2>/dev/null)
CHECK_LIBS   := $(shell pkg-config --libs   check 2>/dev/null)

# Where to put the compiled test executable
BIN_DIR  := bin

# Source files for the test program.  
SRC      := tests/test_tree.c src/treedata.c

# Final output
TARGET   := $(BIN_DIR)/test_tree

# "all", "clean", and "test" are not files; they are commands
.PHONY: all clean test

# Default target: build the test program.  
# it is what is called when you type make with no other words
all: $(TARGET)

# Ensure the bin/ directory exists before we try to place the binary there
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Link rule: build $(TARGET) from the sources.
# $@ is the thing we're building (bin/test_tree)
# We compile+link in one step for simplicity (OK for small projects).
$(TARGET): $(BIN_DIR) $(SRC)
	$(CC) $(CFLAGS) $(CHECK_CFLAGS) -o $@ $(SRC) $(LDFLAGS) -ltree $(CHECK_LIBS)

# Run the unit tests
test: $(TARGET)
	@echo "==> Running unit tests"
	@./$(TARGET)

# Clean out build artifacts
clean:
	rm -rf $(BIN_DIR)

# Picks the right .so inside the cis2750 container for A0.  
# this target is only needed for A0
setup-lib:
	@arch=$$(dpkg --print-architecture 2>/dev/null || uname -m); \
	if [ "$$arch" = "amd64" ] || [ "$$arch" = "x86_64" ]; then \
		cp lib/libtree-linux-amd64.so lib/libtree.so; \
		echo "Using libtree-linux-amd64.so"; \
	else \
		cp lib/libtree-linux-arm64.so lib/libtree.so; \
		echo "Using libtree-linux-arm64.so"; \
	fi