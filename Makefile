CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Student.cpp Main.cpp
value_typeS=$(SOURCES:.cpp=.o)
EXECUTABLE=Main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(value_typeS)
	$(CC) $(LDFLAGS) $(value_typeS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
