# Workspace Makefile, add all projects
ifndef config
	config = debug
endif

# For Every project directory add a new variable with the
# Name_config to configure

ifeq ($(config),release)
	ArgParser_config = release
else ifeq ($(config),optimize)
	ArgParser_config = optimize
else ifeq ($(config),debug)
	ArgParser_config = debug
endif	

#Add All project names
PROJECTS := ArgParser

.PHONY: all clean $(PROJECTS) uninstall install clean

all: $(PROJECTS)
# add static and shared libs before

ArgParser: 
	@echo "==== Building ($@) ($(ArgParser_config)) ===="
	@$(MAKE) --no-print-directory -C $@ -f Makefile config=$(ArgParser_config)

# Rule name should be same as directrory

#add Extra rules with the same format

# add for every project
clean:
	@${MAKE} --no-print-directory -C ArgParser -f Makefile clean
