# Each rule contains the name of target file, dependencies, and the command to be executed

# Building the executable project10_roster by linking readline.o, student.o, and project10_roster.o 
project10_roster: readline.o student.o project10_roster.o
	gcc -o project10_roster project10_roster.o readline.o student.o

# Building readline.o by compiling readline.c
readline.o: readline.c student.h
	gcc -c readline.c

# Building student.o by compiling student.c
student.o: student.c readline.h
	gcc -c student.c

# Building project10_roster.o by compiling project10_roster.c 
project10_roster.o: project10_roster.c
	gcc -c project10_roster.c

# Clean
clean:
	rm project10_roster.o readline.o student.o