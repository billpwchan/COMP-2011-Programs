SRCS	= $(shell /bin/ls mystring_*.cpp)
OBJS	= $(SRCS:.cpp=.o)
PROGS	= mystring


$(PROGS): $(OBJS)
		g++ -o $@ $(OBJS)

$(SRCS):	mystring.h



clean:
	/bin/rm -f $(PROGS) $(OBJS) *~
