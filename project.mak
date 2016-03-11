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

# Include directories
INCLUDE_DIRS := ../include
INCLUDES = $(addprefix -I, $(INCLUDE_DIRS))

# STD ?= 11

ifeq "$(STD)" "11"
     CXXFLAGS += -std=gnu++11
else ifeq "$(STD)" "98"
     CXXFLAGS += -std=gnu++98
else ifeq "$(STD)" "c11"
     CXXFLAGS += -std=c++11
else ifeq "$(STD)" "c98"
     CXXFLAGS += -std=c++98
endif

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

