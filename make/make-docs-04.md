## 4 Writing rules

A rule says when and how to remake certain files, called rule's _targets_.

It lists the other files that are prerequisites of the target.

It gives the recipe to use to create or update the target.

The order is not significant, except for determining the _default_ goal (the first one).

We usually write the makefile so that the first rule is the one for compiling the entire program or all the programs described by the makefile (target `all`).

### Syntax

Rules look like:

```makefile
targets : prerequisites
    recipe
    ...
```

Targets are file names, separated by spaces. Wildcard characters may be used.

Recipe lines start with a tab character (can be set with `.RECEIPEPREFIX`).

To determine if a target is out of date is specified in terms of the prerequisites, which are file names separated by spaces (wildcards are valid too).

A target is out of date if it does not exist or if it is older than any of the prerequisites (by comparison of last-modification time).

How to update is specified by a _recipe_. This is one or more lines to be executed by the shell.

### Types of prerequisites

Two types: normal and order-only.

Normal prerequisites makes two statements:

1. It imposes an order in which recipes will be invoked. The recipes for all prerequisites of a target will be completed before the recipe for the target is run.

2. It imposes a dependency relationship: if any prerequisite if newer than the target, then the target is out of date, and has to be rebuilt.

Order-only are specified by placing a pipe symbol `|` in the prerequisites list, those to the left are normal and to the right are order-only.

If you were to want your targets to be placed in a separate directory that may not exist before `make` is run. You can have the directory be created before any targets are placed into it.

Because the timestamps on directories change whenever a file is added, removed or renamed, we don't want to rebuild all the targets whenever the directory's timestamp changes.

We can manage that we order only prerequisites: make the directory an order-only prerequisite on all the targets:

```makefile
OBJDIR := objdir
OBJS := $(addprefix $(OBJDIR)/,foo.o bar.o baz.o)

$(OBJDIR)/%.o : %.c
    $(COMPILE.c) $(OUTPUT_OPTION) $<

all: $(OBJS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
    mkdir $(OBJDIR)
```

Now the rule to create the `objdir` directory will be run, if needed, before any `.o` isbuilt, but no `.o` will be built because the `objdir` directory timestamp changed.

## Using wildcard characters in file names

A file name can specify many files using _wildcards_, these are: `*`, `?`, `[...]` -the same as Bourne shell-.

`~` at the beginning of a file: if alone or followed by a dash it represents the home directory: `~/bin` expands to `/home/you/bin`.

If followed by a word, represents the home directory of the user named by that word: `~john/bin` expands to `/home/john/bin`.

In windwos you can use the environment variable _HOME_.

### Examples

In the recipe of a rule, wildcards are expanded by the shell.

```makefile
clean:
    rm -f *.o
```

In the prerequisites of a rule:

```makefile
print: *.c
    lpr -p $?
    touch print
```

The above example prints all the `.c` files that have changed since the last print.

The _automatic variable_ `$?` is used to print only files that have changed.

Wildcard expansion does not happen when defining variables. However if you use a variable with wildcards in a target or prerequisite, expansion will take place:

```makefile
objects = *.o
```

To set the variable to the expansion, instead use:

```makefile
objects := $(wildcard *.o)
```

### Pitfalls


