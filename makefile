main: main.o
	g++ -Wall -Wextra -Werror main.cpp -o main


ifdef OS
   RM = del /Q /S
   FixPath = $(subst /,\,$1)
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
   endif
endif

clean:
	$(RM) *.o main.exe
