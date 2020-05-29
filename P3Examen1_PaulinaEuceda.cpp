#include <iostream>
#include <vector>
#include "Empleado.cpp"
#include "Tarea.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char** argv) {
	bool salida = true;
	Empleado* objEmpleado =NULL;
	vector<Empleado> empleados;
	empleados.push_back(Empleado("Paulina", 18, 2, 54, 24));
	empleados.push_back(Empleado("Yuda", 21, 3, 71, 51));
	
	vector<Tarea> backlog;
	backlog.push_back(Tarea("Crear MYPIMES", 1, 4));
	backlog.push_back(Tarea("Crear Baleadas", 2, 8));
	
	bool salidaProyecto=false;
	
	while(salida){
		cout<<"1. Contratar empleado"<<endl
				<<"2. Despedir empleado"<<endl
				<<"3. Listar empleados"<<endl
				<<"4. Crear tarea"<<endl
				<<"5. Listar tareas"<<endl
				<<"6. Iniciar proyecto"<<endl
				<<"7. Salir"<<endl;
		
		int menuPrincipal;		
		cout<<"Ingrese la opcion que desea: ";
		cin >> menuPrincipal;
		
		switch(menuPrincipal){
			case 1:{
				//string nombre, int edad, int nivel, int habilidad, int pereza
				if(salidaProyecto==false){
					string nombreRegistro;
					int edad, nivel, habilidad, pereza;
				
					cout<<"Escriba su nombre: ";
					cin >> nombreRegistro;
					
					cout<<"Escriba su edad: ";
					cin >> edad;
					
					cout<<"Escriba su nivel [1-3]: ";
					cin >> nivel;
					
					while(nivel<1 || nivel>3){
						cout<<"Rangos incorrectos. Escriba su nivel [1-3]: ";
						cin >> nivel;
					}
					
					cout<<"Escriba la cantidad habilidad: ";
					cin >> habilidad;
					
					cout<<"Escriba la cantidad pereza: ";
					cin >> pereza;
					
					empleados.push_back(Empleado(nombreRegistro, edad, nivel, habilidad, pereza));
					
				}else{
					cout<<"Hay un proyecto en ejecucion"<<endl;
				}
				break;
			}
			case 2:{
				
				break;
			}
			case 3:{
				for(int i = 0; i<empleados.size(); i++){
					cout<< empleados[i].getNombre()<<empleados[i].getEdad()<<empleados[i].getNivel()<<empleados[i].getHabilidad()<<empleados[i].getPereza()<<endl;
				}
				
				break;
			}
			case 4:{
				if(salidaProyecto==false){
					string descripcion;
					int nivel, carga;
					
					cout<<"Escriba la descripcion: ";
					cin >> descripcion;
					
					cout<<"Escriba el nivel [1-3]: ";
					cin >> nivel;
					
					while(nivel<1 || nivel>3){
						cout<<"Rangos incorrectos. Escriba su nivel [1-3]: ";
						cin >> nivel;
					}
					
					cout<<"Escriba la carga de tareas: ";
					cin >> carga;
					
					backlog.push_back(Tarea(descripcion, nivel, carga));
					
				}else{
					cout<<"Hay un proyecto en ejecucion"<<endl;
				}
				
				break;
			}
			case 5:{
				for(int i = 0; i<backlog.size(); i++){
					cout<< backlog[i].getDescripcion()<<", "<<backlog[i].getNivel()<<", "<<backlog[i].getCarga()<<", "<<endl;
				}
				break;
			}
			case 6:{
				int N=0;
				for(int i = 0; i<backlog.size(); i++){
					N+=backlog[i].getCarga();
				}
				cout << N;
				salidaProyecto=true;
				int opcionProyecto;
				while(salidaProyecto){
					cout<<"1. Siguiente día"<<endl
						<<"2. Generar reporte"<<endl
						<<"3. Salir"<<endl
						<<"Ingrese la opcion que desea: ";
					cin >> opcionProyecto;
					
					switch(opcionProyecto){
						case 1:{
							
							break;
						}
						case 2:{
							
							break;
						}
						case 3:{
							salidaProyecto = false;
							break;
						}
					}
					
				}
				
				break;
			}
			case 7:{
				salida = false;
				break;
			}
		}
		cout<<endl;
		cout<<endl;
		
	}
	delete objEmpleado;
	return 0;
}
