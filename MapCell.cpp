#include "MapCell.h"
#include <iostream>

MapCell::MapCell(){
	id = '0';
}
bool MapCell::cellIsBlocked(){
	if(id == '|'){
		return true;
	}else{
		return false;
	}
}
