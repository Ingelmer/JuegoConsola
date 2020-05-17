#include <iostream>
#include "Player.h"
#include "MapCell.h"
#include "GamePad.h"
using namespace std;
int main() {
	system("color 1F");
	GamePad map;
	Player Hero;
	
	map.cargarArchivoTexto();
	map.cargarPortada();
	cout<<"Use las teclas 'w' 'a' 's' 'd' para moverse.."<<endl;
	while(map.isGameOver == false){
		Hero.callInput(); //Con esta funcion estoy modificando la posicion del jugador
		//Antes de mover al jugador debemos ver si esta disponible la celda
		
		//Aqui voy a obtener esas modificaciones
		if(map.setPlayerCell(Hero.getY(),Hero.getX()) && map.getWin()==false){
			//cout<<"Las coordenadas pasadas son: "<<Hero.lastY<<","<<Hero.lastX<<endl;
			//Aqui dibujo el mapa actualizado
			map.draw();	
		}
		if(map.setPlayerCell(Hero.getY(),Hero.getX()) == false){
			//cout<<"Tus coordenadas actuales son : "<<Hero.y<<","<<Hero.x<<endl;
			//cout<<"Te voy a posicionar a: "<<Hero.lastY<<","<<Hero.lastX<<endl;
			Hero.setPlayerPositionSafe();
			map.draw();
		}
		
	}
	system("pause");
	return 0;
}
