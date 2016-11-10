src += main.cc
src += question.cc
src += circle.cc
src += rectangle.cc
src += square.cc

target = main
cc = g++

obj = $(src:%.cc=%.o)

$(target):$(obj)
	$(cc) $^ -o $@
%.o:%.cc
	$(cc) -c $< -o $@
.phony:clean
clean:
	rm -rf *.o $(target)
