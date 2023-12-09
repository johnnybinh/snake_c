main: main.cpp
	g++ main.cpp -I/opt/homebrew/opt/ncurses/include -o main -L/opt/homebrew/opt/ncurses/lib -lform -lncurses