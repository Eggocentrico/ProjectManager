all:
	gcc ProjectManager.c -o pm -lsqlite3

debug:
	gcc ProjectManager.c -g -o pm -lsqlite3
