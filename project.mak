# Build directory (where executables reside), must expand immediately
BLDDIR := ../bin

TARGETS := $(addprefix $(BLDDIR)/, $(TARGETNAMES))

all: $(TARGETS)

# Order-only prerequisite (denoted by |): 
# BLDDIR must exist before any targets are built.
# However, the timestamp of BLDDIR is not checked.
$(TARGETS): | $(BLDDIR)

# This is invoked only if BLDDIR doesn't exist, 
# so theoretically, there is no need for -p.
# However, -p might prevent a race condition in some rare cases.
$(BLDDIR):
	mkdir -p $(BLDDIR)

$(BLDDIR)/%: %.o
	$(LINK.cpp) $^ -o $@

# Include directories
INCLUDE_DIRS := ../include
INCLUDES = $(addprefix -I, $(INCLUDE_DIRS))

# Default to GNU variety of C++ 11
STD ?= gnu++11
CXXFLAGS += -std=$(STD)

# Compile/link flags
CXXFLAGS += -g -Wall 
CPPFLAGS += $(INCLUDES)

# CLEANUP SECTION ================

.PHONY: clean

clean:
	$(QUIET)rm -f $(TARGETS)
	$(QUIET)rm -f *.o *.d *.tmp

distclean: clean
	$(QUIET)rm -rf $(BLDDIR)
	$(QUIET)rm -f $(LIBS)
	$(QUIET)rm -f $(LIBOBJ)

