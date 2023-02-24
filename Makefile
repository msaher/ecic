bin = main
srcdir := src
objdir := obj
srcs := $(wildcard $(srcdir)/*.c)
objs := $(patsubst $(srcdir)/%.c, $(objdir)/%.o, $(srcs))
CCFLAGS = -Wall -Wextra

$(bin): $(objs)
	$(CC) $(CCFALGS) $(objs) -o $(bin)

$(objdir)/%.o: $(srcdir)/%.c $(srcdir)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(objdir)/%.o: $(srcdir)/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

run: $(bin)
	"./$(bin)"

clean:
	rm -f $(bin) $(objs)
