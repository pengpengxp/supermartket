.PHONY:a.out tags
a.out:obj
	cc main.c function.o list.o item.o
	./a.out
obj:function.c item.c list.c
	cc -c function.c list.c item.c
tags:
	etags *.[ch]
clean:
	rm -rfv a.out *.o

