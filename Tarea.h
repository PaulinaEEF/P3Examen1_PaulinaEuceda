#ifndef TAREA_H
#define TAREA_H
#include<iostream>

using std::string;

class Tarea
{
	public:
		Tarea();
		Tarea(string, int, int);
		
		string getDescripcion(); 
		void setDescripcion(string);
		
		int getNivel(); 
		void setNivel(int);
		
		int getCarga(); 
		void setCarga(int);
		void disminuirDias();
		
		~Tarea();
	protected:
		string descripcion; 
		int nivel, carga;
};

#endif
