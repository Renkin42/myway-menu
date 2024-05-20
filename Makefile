CC=g++
DEPS=gtkmm-3.0 gtk-layer-shell-0 tomlplusplus
CFLAGS=$(shell pkg-config --cflags $(DEPS))
LDFLAGS=$(shell pkg-config --libs $(DEPS))

%.o: %.cpp
	echo $(CC)
	$(CC) -c -o $@ $< $(CFLAGS)

myway-menu: main.o mw-menu.o
	$(CC) -o $@ $^ $(LDFLAGS)
