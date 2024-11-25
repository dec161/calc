_src = src
_out = out
_include = $(_src)/include

$(_out)/main:
	g++ -std=c++98 $(_src)/main.cpp -o $(_out)/main

clean:
	rm -r $(_out)

