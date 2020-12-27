SRCS	= $(shell /bin/ls mystring_*.cpp)
OBJS	= $(SRCS:.cpp=.o)
PROGS	= mystring


$(PROGS): $(OBJS)
		g++ -o $@ $(OBJS)

$(SRCS):	ll_cnode.h mystring.h



clean:
	/bin/rm -f $(PROGS) $(OBJS) *~
