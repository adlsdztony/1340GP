cc = g++
prom = game
deps = *.h
obj = main.o format.o display.o keyboard.o object.o window.o notice.o
flag = -pthread

$(prom): $(obj)
	$(cc) -o $(prom) $(flag) $^
 
%.o: %.c %.h
	$(cc) -c $< -o $@
 
clean:
	rm -rf $(obj) $(prom)
