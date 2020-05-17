#ifndef GAMEPAD_H
#define GAMEPAD_H
#include "MapCell.h"
class GamePad
{
	public:
		GamePad();
		MapCell* playerCell;
		MapCell cells[15][10];
		bool isGameOver;
		void draw();
		bool setPlayerCell(int,int);
		void cargarArchivoTexto();
		void cargarPortada();
		void cargarVictoria();
		bool getWin();
	private:
		bool win;
};

#endif
