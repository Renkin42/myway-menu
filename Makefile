DEPS=gtkmm-3.0
CFLAGS=$(shell pkg-config --cflags $(DEPS))
LDFLAGS=$(shell pkg-config --libs $(DEPS))

%.o: %.cpp
	echo $(CC)
	g++ -c -o $@ $< $(CFLAGS)

myway-menu: main.o
	g++ -o $@ $^ $(LDFLAGS)
