#include "GamePad.h"
#include <iostream>
#include <fstream>

using namespace std;

GamePad::GamePad(){
	// Constructor de la clase GamePad
	playerCell = NULL;
	isGameOver = false;
	win = false;
}
void GamePad::draw(){
	for (int i=0; i<15; i++){
		for (int j=0; j<10; j++){
			cout<<cells[i][j].id;
		}
		cout<<endl;	
	}
	//cout<<playerY<<","<<playerX;
}
bool GamePad::setPlayerCell(int playerY, int playerX){
	//cout<<"Las coordenadas del jugador son: "<<playerX<<","<<playerY;
	if(cells[playerY][playerX].cellIsBlocked() == false){
		if(cells[playerY][playerX].id == '$' && win == false){
			GamePad::cargarVictoria();
			isGameOver = true;
			win = true;
			return true;
		}else{
			if(playerCell != NULL){
			playerCell->id = 0;
			}
			playerCell = &cells[playerY][playerX];
			playerCell->id = 3;
			
			return true;
		}
		
	}else{
		return false;
	}
	
}
void GamePad::cargarArchivoTexto(){
	/*
	ofstream file("mapaJuego.txt");
	if(file.is_open()){
		
	}else{
		cout<<"Error No se pudo crear el archivo :(";
	}
	*/
	string lectura;
	ifstream file;
	file.open("mapaJuego.txt",ios::in);
	int cont = 0;
	if(file.is_open()){
		while(!file.eof()){
			getline(file,lectura);
			for(int i=0; i<lectura.length();i++){
				if(lectura[i] == '0'){
					cells[cont][i].id = 0;
				}else{
					cells[cont][i].id = lectura[i];		
				}				
			}
			cont++;
			
		}
	
	}else{
		cout<<"Error no se pudo leer el archivo";
	}
}
void GamePad::cargarPortada(){
	string lecPortada;
	ifstream file1("nombre.txt");
	if(file1.is_open()){

		while(getline(file1,lecPortada)){
			cout<<lecPortada<<endl;
		}
		cin>>lecPortada;
	}else{
		cout<<"No se pudo abrir el archivo";
	}
	
}
void GamePad::cargarVictoria(){
	string lecPortada;
	ifstream file1("victoria.txt");
	if(file1.is_open()){

		while(getline(file1,lecPortada)){
			cout<<lecPortada<<endl;
		}
	}else{
		cout<<"No se pudo abrir el archivo";
	}
	
}
bool GamePad::getWin(){
	return win;
}

