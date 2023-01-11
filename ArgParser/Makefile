# ==== Project Makefile Configurtation
# Static Lib Version (.a)

# Compiler and Compiler options
CXX = g++
CXXFLAGS = -Wall -I./include
LDFLAGS = 

#Directory user to install lib
INSTALLDIR=/usr/local/lib
# Desired lib name, get prefixed with lib and appened with .a
APPNAME = argParser

# Optimization modes
ifndef config
	config=debug
endif

ifeq ($(config),debug)
	CXXFLAGS += -g
else ifeq ($(config),optimize)
	CXXFLAGS += -O3
else ifeq ($(config),release)
	CXXFLAGS += -O3
	CXXFLAGS += -s
endif

# Source and Destination Directorys for all files
BIN = ../lib$(APPNAME).a
OBJDIR = ../obj/$(APPNAME)
SRCDIR = src

# Sourcing the locations for Sources, Object, and dependency files
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=%.d)

# ALL rule
all: $(BIN)

# FINAL Compilation set, produces final lib
$(BIN): $(OBJ)
	ar rcs $@ $^

# Generates Dependency Files
%.d: $(SRCDIR)/%.cpp
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

# Maps all includes
-include $(DEP)

# Compiles all translation units, does each one individually
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# Uninstall Step, remove if not needed
uninstall:
	@echo "==== Uninstalling ($(APPNAME))"
	rm -f $(INSTALLDIR)/$(APPNAME)

# install step, remote if not needed
install: all
	@echo "==== Installing ($(APPNAME)) ($(config))"
	cp -f $(BIN) $(INSTALLDIR)/lib$(APPNAME).a
	chmod 755 $(INSTALLDIR)/lib$(APPNAME).a
	
# Clean all Object, dependencies, and the Binary file for a new clean compilation
clean:
	rm -f $(OBJ) $(DEP) $(BIN)	
