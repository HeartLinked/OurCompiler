# Compiler and Linker
CC          := clang++-14
# The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := src
BUILDDIR    := build
TARGETDIR   := .
TARGET      := $(TARGETDIR)/compiler
SRCEXT      := cpp

# Flags, Libraries and Includes
CFLAGS      := -g -Wall -O3 -I$(BUILDDIR) -Isrc -MMD -MP
LIB         := 
INC         := -I$(SRCDIR)

#---------------------------------------------------------------------------------
# DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------

SOURCES     := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DEPS        := $(OBJECTS:.o=.d)

# Defining a rule for flex and bison
LEX         := flex
YACC        := bison
LEXFILE     := $(SRCDIR)/sysy.l
YACCFILE    := $(SRCDIR)/sysy.y
LEXOBJ      := $(BUILDDIR)/lex.yy.o
YACCOBJ     := $(BUILDDIR)/sysy.tab.o
LEXHEADER   := $(BUILDDIR)/lex.yy.h
YACHEADER   := $(BUILDDIR)/sysy.tab.hpp

# Targets
all: directories $(YACHEADER) $(LEXOBJ) $(OBJECTS) $(TARGET)

$(TARGET): $(OBJECTS) $(LEXOBJ) $(YACCOBJ)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " Compiling $<..."; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(LEXOBJ): $(LEXFILE) $(YACHEADER)
	$(LEX) -o $(BUILDDIR)/lex.yy.c $(LEXFILE)
	$(CC) $(CFLAGS) -c $(BUILDDIR)/lex.yy.c -o $(LEXOBJ)

$(YACCOBJ): $(YACCFILE) $(YACHEADER)
	$(CC) $(CFLAGS) -c $(BUILDDIR)/sysy.tab.c -o $(YACCOBJ)

$(YACHEADER): $(YACCFILE)
	$(YACC) -d -o $(BUILDDIR)/sysy.tab.c --defines=$(YACHEADER) $(YACCFILE)

directories: 
	@echo " Creating directories"
	@mkdir -p $(BUILDDIR)

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Include dependencies
-include $(DEPS)

# Non-File Targets
.PHONY: all remake clean
