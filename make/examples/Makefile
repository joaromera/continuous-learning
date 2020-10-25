OBJDIR := objdir
OBJS := $(addprefix $(OBJDIR)/,main.o)

$(OBJDIR)/%.o : %.cpp
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

all: $(OBJS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJDIR)