#Para escrever comentários ##
############################# Makefile ##########################
main:		img.o arg.o global.o main.o
		# O compilador faz a ligação entre os dois objetos
		gcc build/*.o -o steg
# Testes
test:
		./steg
		./steg -e
		./steg -e -i code.txt image/imgp3.ppm
		./steg -e -i code.txt image/imgp6.ppm
		./steg -e -i code.txt image/BMP.bmp
# Arquivos
img.o:		lib/img/*
		gcc -c lib/img/img.c -o build/img.o
arg.o:		lib/arg/*
		gcc -c lib/arg/arg.c -o build/arg.o
global.o:		lib/*
		gcc -c lib/global.c -o build/global.o
main.o:		main.c
		gcc -c main.c -o build/main.o
clean:
		rm -rf build/*.o
