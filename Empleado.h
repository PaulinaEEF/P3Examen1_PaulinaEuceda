#ifndef EMPLEADO_H
#define EMPLEADO_H
#include<iostream>
#include "Tarea.h"

using std::string;

class Empleado
{
	public:
		Empleado();
		Empleado(string, int, int, int, int, int);
		
		string getNombre(); 
		void setNombre(string);
		int getEdad(); 
		void setEdad(int);
		int getNivel(); 
		void setNivel(int);
		int getHabilidad(); 
		void setHabilidad(int);
		int getPereza(); 
		void setPereza(int);
		int getEstado(); 
		void setEstado(int);
		Tarea getTarea();
		void setTarea(Tarea tarea);
		void ReducirDiasTarea();
		
		~Empleado();
	protected: 
	string nombre;
	int edad, nivel, habilidad, pereza, estado;
	Tarea tarea;
};

#endif
