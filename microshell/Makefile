# 
# Builds microshell program
#

IDIR = include
SDIR = sources
ODIR = release

CC = gcc
CFLAGS = -Wall -ansi -I $(IDIR)
SOURCES = $(wildcard $(SDIR)/*.c)
OBJS = $(patsubst $(SDIR)/%.c,$(ODIR)/%.o,$(SOURCES))
DEPS = $(patsubst $(SDIR)/%.c,$(ODIR)/%.d,$(SOURCES))

# DEBUG mode
ifdef DEBUG
	CFLAGS += -g -D DEBUG
endif

all: microshell
	#

-include $(DEPS)

# Compiling
$(ODIR)/%.o: $(SDIR)/%.c $(ODIR)/%.d
	@mkdir -p $(ODIR)
	@echo "Compiling..."
	@gcc -c $(CFLAGS) $(SDIR)/$*.c -o $@

# Dependency generation
$(ODIR)/%.d: $(SDIR)/%.c
	@mkdir -p $(ODIR)
	@echo "Dependencies..."
	@gcc -MM $(CFLAGS) -MP -MT $(ODIR)/$*.o $< > $(ODIR)/$*.d

# Linking
microshell: $(OBJS)
	@echo "Linking..."
	@gcc $^ -o $@
	@echo "Finished!"

# Cleaning
clean:

	@rm -fR $(ODIR) microshell *~
