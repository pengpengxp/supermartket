.PHONY:a.out tags
a.out:obj
	cc -o supermarket main.c function.o list.o item.o price.o
obj:function.c item.c list.c price.c
	cc -c function.c list.c item.c price.c
tags:
	etags *.[ch]
clean:
	rm -rfv a.out *.o supermarket

