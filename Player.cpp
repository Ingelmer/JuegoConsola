#include <iostream>
#include "Player.h"
using namespace std;
Player::Player(){
	x = 1;
	y = 1;
	lastX=1;
	lastY=1;
}
void Player::callInput(){
	char entrada = ' ';
	lastX =x;
	lastY = y;
		cin >> entrada;
		switch (entrada){
		case 'w':
			
			y-=1;		
			break;
		case 'd':
			
			x+=1;			
			break;
		case 'a':
			
			x-=1;			
			break;
		case 's':
	
			y+=1;			
			break;
		default:
			break;
		}
}
void Player::setPlayerPositionSafe(){
	x = lastX;
	y = lastY;
}
int Player::getX(){
	
	return x;
}
int Player::getY(){
	
	return y;
}
int Player::getLastX(){
	
	return lastX;
}
int Player::getLastY(){
	return lastY;
}
