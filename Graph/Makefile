include Rules.make

MODULES := ../DynamicArray

.PHONY: subdirs $(MODULES)

INC = -I../DynamicArray

modules: $(MODULES)

OBJS = Graph.o \
       main.o

ARRAY = Array.o

Graph.o: Graph.c
	$(CC) $(CFLAGS) $(INC) -c -o Graph.o Graph.c
main.o : main.c
	$(CC) $(CFLAGS) $(INC) -c -o main.o main.c

$(MODULES):
	$(MAKE) all -C $@

all: modules $(OBJS)
	cp ../DynamicArray/Array.o .
	$(CC) $(CPPFLAGS) -o $(TARGET) $(ARRAY) $(OBJS)

clean:
	find -name "*.o" -exec rm {} \;
	@rm -v -f $(TARGET)

distclean: clean
	@for i in $(MODULES); do \
		echo "Clearing in $$i..."; \
		(cd $$i; $(MAKE) distclean); \
		(cd $$i; $(MAKE) clean); \
	done
