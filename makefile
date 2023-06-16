CC = g++
CFLAG = -std=gnu++17 -Wall -Wextra -O2
SRCS = $(shell find *.cpp)
OBJS = $(SRCS:%.cpp=%.o)
BUILDDIR = ./build

ALL : $(OBJS)
	$(CC) $(CFLAG) -o $(BUILDDIR)/main $(addprefix $(BUILDDIR)/,$(OBJS))

%.o: %.cpp
	mkdir -p build
	$(CC) $(CFLAG) -o $(BUILDDIR)/$@ -c $<

clean :
	rm -rf $(BUILDDIR)