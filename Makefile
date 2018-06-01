#Makefile
#watching Убери conios.h совсем без замены на conio.h
#Сборка проекта
#СС указатель на компилятор для сборки
CC=gcc
#FLAGS Флажки для компиляции
CFLAGS=-Wall -Werror -std=c99

src=src/
build=build/
bin=bin/

OBJECTS=$(addprefix $(build), main.o conios.o)
EXE=bin/main

.PHONY: all clean

all: build bin $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(build)main.o: $(src)main.c
	$(CC) $(CFLAGS) -c $(src)main.c -o $@

$(build)conios.o: $(src)conios.c $(src)conios.h
	$(CC) $(CFLAGS) -c $(src)conios.c -o $@

build:
	mkdir build
src:
	mkdir src
bin:
	mkdir bin
clean:
	-rm -rf build bin