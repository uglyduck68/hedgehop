################################################
#	Use this file for making testing .exe file
################################################
test.exe : main.o
	g++ -ggdb -o test.exe main.o -Llibs -lReactor \
		-L$(FASTFORMAT_ROOT)/lib \
		-lpantheios.1.core.gcc43 -lpantheios.1.be.fprintf.gcc43 \
		-lpantheios.1.bec.fprintf.gcc43 \
		-lpantheios.1.fe.all.gcc43 -lpantheios.1.util.gcc43 \
		-L/usr/local/lib -losipparser2 -losip2 -lpthread
	mv test.exe main.o bins/
main.o : main.c
	g++ -ggdb -c main.c -I$(FASTFORMAT_ROOT)/include -I$(STLSOFT)/include -I/usr/local/include/osipparser2/\
		-I/usr/local/include/osip2/
clean:
	rm bins/test.exe bins/main.o

#################################################
#test.exe : main.o Reactor.o ReactorImpl.o
#	g++ -fPIC -o test.exe main.o Reactor.o ReactorImpl.o -L$(FASTFORMAT_ROOT)/lib \
#		-lpantheios.1.core.gcc43\
#		-lpantheios.1.be.fprintf.gcc43 -lpantheios.1.bec.fprintf.gcc43\
#		-lpantheios.1.fe.all.gcc43 -lpantheios.1.util.gcc43
#
#main.o : main.c
#	g++ -c main.c -I$(FASTFORMAT_ROOT)/include -I$(STLSOFT)/include
#Reactor.o : Reactor.c
#	g++ -c Reactor.c -I$(FASTFORMAT_ROOT)/include -I$(STLSOFT)/include
#ReactorImpl.o : ReactorImpl.c
#	g++ -c ReactorImpl.c -I$(FASTFORMAT_ROOT)/include -I$(STLSOFT)/include
#clean:
#	rm test.exe main.o Reactor.o ReactorImpl.o
##################################################
