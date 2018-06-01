#Makefile
#watching Убери conios.h совсем без замены на conio.h
#Сборка проекта
#СС указатель на компилятор для сборки
CC=gcc
#FLAGS Флажки для компиляции
CFLAGS=-Wall -Werror -std=c99

src=src/
build=build/
build_t=build_t/
bin=bin/

OBJECTS=$(addprefix $(build), main.o conios.o add_tem.o checkfile.o)
OBJECTS_T=$(addprefix $(build_t), add_tem.o main_test.o)
EXE=bin/main

.PHONY: all clean test


all: build build_t txt Tests bin $(EXE) test

test: $(bin)main_test
	$(bin)main_test

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(build)main.o: $(src)main.c
	$(CC) $(CFLAGS) -c $(src)main.c -o $@

$(build)conios.o: $(src)conios.c $(src)conios.h
	$(CC) $(CFLAGS) -c $(src)conios.c -o $@

$(build)add_tem.o: $(src)add_tem.c $(src)add_tem.h
	$(CC) $(CFLAGS) -c $(src)add_tem.c -o $@

$(build)checkfile.o: $(src)checkfile.c $(src)checkfile.h
	$(CC) $(CFLAGS) -c $(src)checkfile.c -o $@

$(bin)main_test: $(OBJECTS_T)
	$(CC) $(CFLAGS) $(OBJECTS_T) -o $@

$(build_t)main_test.o: test/main.c thirdparty/ctest.h $(src)add_tem.h
	$(CC) $(CFLAGS) -I thirdparty -I src -c test/main.c -o $@

$(build_t)add_tem.o: $(src)add_tem.c $(src)add_tem.h
	$(CC) $(CFLAGS) -c $(src)add_tem.c -o $@

build:
	mkdir build
build_t:
	mkdir build_t
src:
	mkdir src
txt:
	mkdir txt
bin:
	mkdir bin
Tests:
	mkdir Tests
	touch Tests/Tests.txt
clean:
	-rm -rf build build_t bin Tests
clear:
	-rm -rf txt