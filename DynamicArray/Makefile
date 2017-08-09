include Rules.make

MODULES := ../Common

.PHONY: subdirs $(MODULES)

INC = -I../Common

modules: $(MODULES)

OBJS = Array.o \
       main.o

BOOK = Book.o

main.o : main.c
	$(CC) $(CFLAGS) $(INC) -c -o main.o main.c

$(MODULES):
	$(MAKE) -C $@

all: modules $(OBJS)
	cp ../Common/Book.o .
	$(CC) $(CPPFLAGS) -o $(TARGET) $(BOOK) $(OBJS)

clean:
	find -name "*.o" -exec rm {} \;
	@rm -v -f $(TARGET)

distclean:
	@for i in $(MODULES); do \
		echo "Clearing in $$i..."; \
		(cd $$i; $(MAKE) distclean); \
	done
