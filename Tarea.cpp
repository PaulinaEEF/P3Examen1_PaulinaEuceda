#include "Tarea.h"

Tarea::Tarea()
{
}
Tarea::Tarea(string descripcion, int nivel, int carga){
	this->descripcion=descripcion;
	this->nivel= nivel;
	this->carga=carga;
}
		
string Tarea::getDescripcion(){
	return this->descripcion;
}
void Tarea::setDescripcion(string descripcion){
	this->descripcion=descripcion;
	
}

int Tarea::getNivel(){
	return this->nivel;
}
void Tarea::setNivel(int nivel){
	this->nivel= nivel;
	
}

int Tarea::getCarga(){
	return this->carga;
}
void Tarea::setCarga(int carga){
	this->carga=carga;
}

Tarea::~Tarea()
{
}
