cmp = g++
cmpFlags = -std=c++98

obj = bin/obj/main.o \
			bin/obj/CommonParser.o \
			bin/obj/ReverseParser.o \
			bin/obj/Lexer.o \
			bin/obj/ReferenceCounter.o \
			bin/obj/SingleOperationMode.o \
			bin/obj/InteractiveMode.o

.PHONY: all init clean

all: init bin/calc


bin/calc: $(obj)
	$(cmp) $(cmpFlags) -o bin/calc $(obj)


bin/obj/main.o: src/main.cpp src/include/Lexer.hpp src/include/parsers.hpp src/include/modes.hpp
	$(cmp) $(cmpFlags) -MMD -c -o bin/obj/main.o src/main.cpp

bin/obj/CommonParser.o: src/CommonParser.cpp src/include/parsers.hpp
	$(cmp) $(cmpFlags) -MMD -c -o bin/obj/CommonParser.o src/CommonParser.cpp

bin/obj/ReverseParser.o: src/ReverseParser.cpp src/include/parsers.hpp
	$(cmp) $(cmpFlags) -MMD -c -o bin/obj/ReverseParser.o src/ReverseParser.cpp

bin/obj/Lexer.o: src/Lexer.cpp src/include/Lexer.hpp src/include/functors.hpp
	$(cmp) $(cmpFlags) -MMD -c -o bin/obj/Lexer.o src/Lexer.cpp

bin/obj/ReferenceCounter.o: src/ReferenceCounter.cpp src/include/ReferenceCounter.hpp
	$(cmp) $(cmpFlags) -MMD -c -o bin/obj/ReferenceCounter.o src/ReferenceCounter.cpp

bin/obj/SingleOperationMode.o: src/SingleOperationMode.cpp src/include/modes.hpp
	$(cmp) $(cmpFlags) -MMD -c -o bin/obj/SingleOperationMode.o src/SingleOperationMode.cpp

bin/obj/InteractiveMode.o: src/InteractiveMode.cpp src/include/modes.hpp
	$(cmp) $(cmpFlags) -MMD -c -o bin/obj/InteractiveMode.o src/InteractiveMode.cpp


init:
	if ! [ -d "bin" ]; then mkdir bin; fi
	if ! [ -d "bin/obj" ]; then mkdir bin/obj; fi

clean:
	if [ -d "bin" ]; then rm -r bin; fi

-include bin/obj/*.d
