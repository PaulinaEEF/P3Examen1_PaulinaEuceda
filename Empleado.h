#ifndef EMPLEADO_H
#define EMPLEADO_H
#include<iostream>

using std::string;

class Empleado
{
	public:
		Empleado();
		Empleado(string, int, int, int, int);
		
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
		
		~Empleado();
	protected: 
	string nombre;
	int edad, nivel, habilidad, pereza;
};

#endif
