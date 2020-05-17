#ifndef PLAYER_H
#define PLAYER_H
//Clase jugador 
class Player
{
	public:
		Player();
		void callInput();
		void setPlayerPositionSafe();
		int getX();
		int getY();
		int getLastX();
		int getLastY();
	private:
		int x, y;
		int lastX, lastY;
};

#endif
