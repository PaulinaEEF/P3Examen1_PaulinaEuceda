#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
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
	empleados.push_back(Empleado("Paulina", 18, 2, 54, 24, 0));
	empleados.push_back(Empleado("Yuda", 21, 3, 71, 51, 0));
	
	vector<Tarea> backlog;
	backlog.push_back(Tarea("Crear MYPIMES", 1, 4));
	backlog.push_back(Tarea("Crear Baleadas", 2, 8));
	backlog.push_back(Tarea("Crear Choripanes", 3, 1));
	
	bool salidaProyecto=false, inicioProyecto=false;
	
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
				if(inicioProyecto==false){
					string nombreRegistro;
					int edad, nivel, habilidad, pereza;
				
					cout<<"Escriba su nombre: ";
					cin >> nombreRegistro;
					
					cout<<"Escriba su edad: ";
					cin >> edad;
					
					while(edad<=0){
						cout<<"No es un valor valido. Escriba su edad: ";
						cin >> edad;
					}
					
					cout<<"Escriba su nivel [1-3]: ";
					cin >> nivel;
					
					while(nivel<1 || nivel>3){
						cout<<"Rangos incorrectos. Escriba su nivel [1-3]: ";
						cin >> nivel;
					}
					
					cout<<"Escriba el porcentaje de habilidad: ";
					cin >> habilidad;
					
					while(habilidad<0 || habilidad>100){
						cout<<"No es un valor valido. Escriba el porcentaje de habilidad: ";
						cin >> habilidad;
					}
					
					cout<<"Escriba el porcentaje pereza: ";
					cin >> pereza;
					
					while(pereza <0 || pereza > 100){
						cout<<"No es un valor valido. Escriba el porcentaje de pereza: ";
						cin >> pereza;
					}
					
					empleados.push_back(Empleado(nombreRegistro, edad, nivel, habilidad, pereza, 0));
					
				}else{
					cout<<"Hay un proyecto en ejecucion"<<endl;
				}
				break;
			}
			case 2:{
				for(int i = 0; i<empleados.size(); i++){
					cout<< i <<") "<<empleados[i].getNombre()<<", "<<empleados[i].getEdad()<<", "<<empleados[i].getNivel()<<", "<<empleados[i].getHabilidad()<<", "<<empleados[i].getPereza()<<endl;
				}
				int despedirPos;
				cout <<endl <<"Elija a quien quiere despedir: ";
				cin >> despedirPos;
				while(despedirPos >= empleados.size()){
					cout <<endl <<"Valor no valida. Elija a quien quiere despedir: ";
					cin >> despedirPos;
				}
				empleados.erase(empleados.begin() + despedirPos);
				break;
			}
			case 3:{
				for(int i = 0; i<empleados.size(); i++){
					cout<< empleados[i].getNombre()<<empleados[i].getEdad()<<empleados[i].getNivel()<<empleados[i].getHabilidad()<<empleados[i].getPereza()<<endl;
				}
				
				break;
			}
			case 4:{
				if(inicioProyecto==false){
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
					
					while(carga<=0){
						cout<<"Ese numero no es valido. Escriba la carga de tareas: ";
						cin >> carga;
					}
					
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
				if(backlog.size()>0){
					
					int N=0;
					for(int i = 0; i<backlog.size(); i++){
						N+=backlog[i].getCarga();
					}
					int diasEsperados;
					diasEsperados = N + N*0.2;
					cout << "Dias esperados del proyecto: "<<diasEsperados<<endl;
					
					salidaProyecto=true, inicioProyecto=true;
					int opcionProyecto;
					
					int numeroRandom, tareasRealizadas=0, tareasIniciales = backlog.size();
					srand((unsigned)time(0));
					
					int logrosEmpleados=0 ,fallosEmpleados=0, perezaEmpleados=0, tareasProgreso=0;
					
					while(salidaProyecto){
						cout<<endl<<endl;
						cout<<"---Proyecto---"<<endl;
						cout<<"1. Siguiente día"<<endl
							<<"2. Generar reporte"<<endl
							<<"3. Salir"<<endl
							<<"Ingrese la opcion que desea: ";
						cin >> opcionProyecto;
						
						switch(opcionProyecto){
							case 1:{
								logrosEmpleados=0 ,fallosEmpleados=0, perezaEmpleados=0, tareasProgreso=0;
								for(int i=0; i<empleados.size(); i++){
									for(int j=0; j<backlog.size(); i++){
										if(empleados[i].getEstado() == 0){
											if(empleados[i].getNivel() >= backlog[j].getNivel()){
												empleados[i].setTarea(backlog[j]);
												backlog.erase(backlog.begin() + j);
												empleados[i].setEstado(1);
												break;
											}
										}else{
											break;
										}
									}
								}
								for(int i=0; i<empleados.size(); i++){
									numeroRandom = rand() % 100;
									if(empleados[i].getTarea().getCarga() != 0){
									
										if(empleados[i].getPereza() < numeroRandom){
											
											if(empleados[i].getHabilidad()>=numeroRandom){
												logrosEmpleados++;
												
												empleados[i].ReducirDiasTarea();
												
												cout<<"Habilidad: "<<empleados[i].getHabilidad()<<" Porcentaje: "<<numeroRandom<<endl;
												
												if(empleados[i].getTarea().getCarga() == 0){
													tareasRealizadas++;
													empleados[i].setEstado(0);
													cout<<endl<< "Se completo una tarea"<<endl;
												}
											}else{
												fallosEmpleados++;
												cout<<"Habilidad: "<<empleados[i].getHabilidad()<<" Porcentaje: "<<numeroRandom<<endl;
											}
											
										}else{
											cout<<"Pereza: "<<empleados[i].getPereza()<<" Porcentaje: "<<numeroRandom<<endl;
											perezaEmpleados++;
										}
										tareasProgreso++;
									}
								}
								cout<<endl<<endl;
								cout<<"Dias para terminar el proyecto: " << diasEsperados--<<endl;
								break;
							}
							case 2:{
								cout<<"Tareas en backlog: "<<backlog.size()<<endl
									<<"Tareas en progeso: "<<tareasProgreso<<endl
									<<"Empleados perezosos: "<<perezaEmpleados<<endl
									<<"Empleados que fallaron: "<<fallosEmpleados<<endl
									<<"Empleados que lograron el dia: "<<logrosEmpleados<<endl;
								
								cout<<endl<<endl;
								cout<<"Dias para terminar el proyecto: " << diasEsperados--<<endl;
								break;
							}
							case 3:{
								salidaProyecto = false;
								break;
							}
								
						}
						if(backlog.size()==0 && tareasRealizadas==tareasIniciales){
							salidaProyecto = false;
							cout<<"Adiosito"<<endl;
						}
						
					}
				}else{
					cout<<"No hay proyectos"<<endl;
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
