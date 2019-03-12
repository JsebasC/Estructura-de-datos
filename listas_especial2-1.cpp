#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct listas
{
	int salon;
	int codigo;
	listas *ap1;
	listas *ap2;
}
*cab, *Nodo, *Fin, *p1, *p2, *cabn, 
*Finn, *Nodo_new; // variable para la nueva lista
// despues de declarar las librerias y la estructura
// se define variable globales

void capturar_ordenar(void)
{
	//Creamos una nueva lista tomando Lista Ordenada
	//tomando como base la lista tipo cola
	
	if (!cab)
	{ cout<<" No existe una lista";
	}
	else
	{
		cabn = NULL; // Iniciamos la lista Nueva 
		Nodo = cab;	// iniciamos el recorrido de la Lista Pito COLA desde cab
	    while ( Nodo != NULL)
	    {
            Nodo_new = new(listas); //Creamos un nuevo NODO para la nueva LISTA
            Nodo_new->codigo = Nodo->codigo; 
            // copiamos el contenido del Nodo de la COLA al nuevo Nodo
	        if(!cabn)
	        {
		      cabn = Nodo_new;
		      Finn = Nodo_new;
		      cabn->ap1 = NULL;
		      cabn->ap2 = NULL;
		      cout<<"creo 1";
		      Nodo = Nodo->ap1; // avanzamos en la Lista Cola
	        }
	        else
	        { 
		       if (cabn->codigo >= Nodo_new->codigo)
		       {
			      Nodo_new->ap1  = cabn;
			      cabn->ap2  = Nodo_new;
			      cabn = Nodo_new;
			      cabn->ap2  = NULL;
			      cout<<"creo inicio 2";
			      Nodo = Nodo->ap1; // avanzamos en la Lista Cola
	        	}
		        else
		    	{
			    	if (Nodo_new->codigo >= Finn->codigo)
		    		{
			    		Finn->ap1 = Nodo_new;
				    	Nodo_new->ap2 = Finn;
						Finn = Nodo_new;
						Finn->ap1 = NULL;
						cout<<"creo fin 3";
						Nodo = Nodo->ap1; // avanzamos en la pila
			    	}
					else
					{
			    		p1 = cabn;
			    		p2 = cabn->ap1;
				    	char insertar='n';
				    	while (insertar == 'n')
				  		{
					    	if(Nodo_new->codigo <= p2->codigo)
					    	{
					    		Nodo_new->ap1 = p2;
					    		Nodo_new->ap2 = p1;
						   		p1->ap1 = Nodo_new;
						    	p2->ap2 = Nodo_new;
						    	cout<<"creo inter 4";
						    	insertar='s';
						    	Nodo = Nodo->ap1; // avanzamos en la pila
					   		}	 
					    	else
				    		{
					    		p1=p2;
						    	p2=p1->ap1;
					   		}
						}
					}
				}
			}
		}
	}
}

void capturar_cola(void)
{
	if(!cab) //Lista tipo Cola
	{
		Nodo = new(listas);
		cout << "Digite una cifra:";
		cin >> Nodo->codigo;
		
		Nodo->ap1=NULL;
		Nodo->ap2=NULL;		
		cab = Nodo;
		Fin = Nodo;
	}
	else
	{
		Nodo = new(listas);
		cout << "Digite una cifra:";
		cin >> Nodo->codigo;
		
		Nodo->ap2 = Fin;
        Nodo->ap1 = NULL;
        Fin->ap1 = Nodo;
		Fin = Nodo;
	}
}

void mostrar_ascendente(void)
{
	if (!cabn)
	{cout <<"no existe lista1";
	}
	else
	{
        system("cls");  //  comando para limpiar pantalla
        cout <<" Los elementos de la lista son : \n";
		Nodo=cabn;  // iniciamos la lista desde la cabecera
		cout<<"lista Ascendente : "<<'\n';
		while(Nodo != NULL)
		{
			cout << Nodo->codigo<<"  ";	 
			Nodo=Nodo->ap1;  // el avance es ascendente hacia la izquierda
		}
	}
	cout <<"\n\n Emter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla
}

void mostrar_descendente(void)
{
	if (!cabn)
	{cout <<"no existe lista1";
	}
	else
	{
        system("cls");  //  comando para limpiar pantalla
        cout <<" Los elementos de la lista son : \n";
		Nodo = Finn;  // iniciamos la lista desde el Finn 
		cout<<"lista Descendente: "<<'\n';
		while(Nodo != NULL)
		{
			cout << Nodo->codigo<<"  ";
			Nodo=Nodo->ap2;  // el avance es descendente hacia la izquierda
		}
	}
	cout <<"\n\n Emter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla
}

void mostrar_orden1(void)
{
	capturar_ordenar();
	mostrar_ascendente();
}

void mostrar_orden2(void)
{
	capturar_ordenar();
	mostrar_descendente();
}

void mostrar_cola(void)
{
	if(!cab)
	{
		cout << "Lista No Creada \n";
	}else
	{
        system("cls");  //  comando para limpiar pantalla
        cout <<" Los elementos de la lista son : \n";
		Nodo=cab;
		while(Nodo != NULL)
		{
			cout << Nodo->codigo; 
			cout << "\n";
			Nodo=Nodo->ap1;
		}
	}
	cout <<"Emter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla
}

void borrar(void)
{
	//buscamos el primer nodo de la lista Pito Cola y la retiramos 
	if(!cab)
	{
		cout << "Lista No Creada";
	}
	else
	{
		cout <<"\n\n se borro el Nodo con el Codigo : "<<cab->codigo;
		Nodo = cab;
		cab  = cab->ap1;
		delete Nodo;
	}
	cout <<"Emter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla
}

void borrar_especial(void)
{
	// borramos un nodo en cualquier parte de la lista
	// se busca y se retira
	int borrar_cod;    // se define variable local
	int seguir_borrar; // se define variable local
	
	if(!cab)
	{
		cout << "La lista no exite";
	}
	else
	{
		cout << "Digite la unidad que desea borrar: ";
		cin >> borrar_cod;
	
//		if(borrar_cod < cab->codigo || borrar_cod > Fin->codigo)
//		{
//			cout << "No Existe este numero \n";	
//		}
//		else
//		{
			p1 = cab; 
			int buscar=0; // variable que nos indica si encontro y borro un nodo la iniciamos o activamos en "0"
            seguir_borrar = 0; // esta variable se activa en "0" para permitir la busqueda en la lista			
//			while (p1->codigo <= borrar_cod && seguir_borrar == 0)
			while ( seguir_borrar == 0 )
			{
				if(p1->codigo == borrar_cod)
				{
					buscar=1;      // la variable buscar se activa en "1"
					               // indicando que encontramos al menos un nodo a borrar
					if(cab == p1 ) // cuando borremos el primer elemento
					{
						if (cab == Fin ) // En el momento que el primer elemento a borrar sea el unico de la lista 
		                {
		                	cab = NULL; // como borramos este nodo y es cab = Fin = p1  la lista queda en "NULL"
		                	delete p1;
		                	seguir_borrar = 1; //como borramos el ultimo Nodo 
							                   //no seguimos buscando mas nodos desactivamos la variable "seguir_borrar" 						    
						}				
						else
						{ 	cab = p1->ap1; // como el elemento aborrar es el primero la variable cabecera "cab"
						                 // se posiciona en el siguiente "nodo"
						    delete p1;   // borramos el nodo encontrado
						    p1 = cab;
						    seguir_borrar = 1;
						}
					}
					else
					{
						if (Fin == p1) // en el momento que borremos el ultimo registro
						{	
						    Fin = p2;       // retrocedemos el FIN al nodo anterior "p2"
						    p2->ap1 = NULL;  // Como llegamos al ultimo el siguiente es NULL
							delete p1;
						    seguir_borrar = 1; //como borramos el ultimo Nodo 
							                   //no seguimos buscando mas nodos desactivamos la variable "seguir_borrar" 						    
							seguir_borrar = 1;							                   
						}
						else 
						{
							p2->ap1 = p1->ap1;					
    					    delete p1;
	    				    p1 = p2->ap1;
	    				    seguir_borrar = 1;
						}					    						
					}
				}
				else
				{	p2 = p1;  // en este bloque avanzamos en la lista con las variable "p1" y "p2" 
					p1 = p1->ap1;  // para seguir en la busqueda
				}
			}
			
			if(buscar == 0)
			{
				cout << "No existe este Numero \n";
			}
			else
			{
				cout <<"se retiro el Nodo \n";
			}
//		}
	}
	cout <<"Emter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla
}

void Menu()
{
	int op;  // se define una variable local 
	         // la cual opera dentro de este bloque "menu"
	op=0;
	while(op!=7)
	{
		system ("cls");
		cout << "1. Crear cola" << "\n";
		cout << "2. Mostrar" << "\n";
		cout << "3. Borrar" << "\n";
		cout << "4. Borrar especial" << "\n";
		cout << "5. Mostrar 1 " << "\n";
		cout << "6. Mostrar 2" << "\n";
		
		cout << "7. Salir" << "\n";
		cin >> op;
		
		switch(op)
		{
			case 1: capturar_cola(); break;
			case 2: mostrar_cola(); break;
			case 3: borrar(); break;
			case 4: borrar_especial();break;
			case 5: mostrar_orden1();break;
			case 6: mostrar_orden2();break;
			
			default: cout << "Adios";
		}
	}
}

int main()
{
	Menu();
    return 0;
}
