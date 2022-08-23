runservice : build
	./linuxborderless &

run : build
	./linuxborderless


build : main.c
	sudo apt install xdo libxdo-dev
	gcc main.c -lxdo -o linuxborderless

stop :
	pkill linuxborderless