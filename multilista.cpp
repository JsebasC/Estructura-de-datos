#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct lista{
	int salon;
	int codigo;
	lista *ap1;
	lista *ap2;
	
}*cab,*nodo,*fin,*p1,*p2;

void capturar(){
	system ("cls");
	nodo=new lista;
	cout<<"Digite Salon = ";
	cin>>nodo->salon;
	cout<<"Digite Codigo = ";
	cin>>nodo->codigo;
	nodo->ap1=NULL;
	nodo->ap2=NULL;
	
	
	if(!cab){ // el primer elemento se agrega aca
		cab=nodo;
		fin=nodo;
	
		
	}else{
		if(cab->salon>nodo->salon){ // se re ubica si es menor
			nodo->ap1=cab;
			cab=nodo;
					
		}else{
			if(nodo->salon>fin->salon){ // se posiciona en el fin
				fin->ap1=nodo;
				
				fin=nodo;
				
			}else{
				
				
					p1=cab;
					
					int insertar=0;
					p2=cab->ap1;
					
					while(insertar==0){ // se posiciona en la mitad
						if(p1==cab && p1->salon==nodo->salon){
								system("pause");
								nodo->ap2=p1->ap2;
								p1->ap2=nodo;
								cout<<"Se agrego cab en el salon "<<nodo->salon<<" ya existente";
								insertar=1;
								getch();
						}else{
							
							if(nodo->salon<p2->salon){
								
								if(nodo->salon==p1->salon){
									nodo->ap2=p1->ap2;
									p1->ap2=nodo;
									cout<<"Se agrego en el salon "<<nodo->salon<<" ya existente";
									insertar=1;
									getch();
								}else{
									nodo->ap1=p2;
									p1->ap1=nodo;
									insertar=1;
								}
							}else{
								
								p1=p2;
								p2=p1->ap1;
							}
						
							if(p1==fin && p1->salon==nodo->salon){ // el ultimo elemento repetido se agrega aca
								nodo->ap2=p1->ap2;
								p1->ap2=nodo;
								cout<<"Se agrego en el salon "<<nodo->salon<<" ya existente";
								insertar=1;
								getch();
							}
						}		
					}
					
				
			}
		}
	}
	
}

void mostrar_salon(){
	if(!cab){
		cout<<"No existen elementos ";
		
	}else{
		system("cls");
		cout<<"----------Salon----------"<<"\n";
	

		
		int salir=0;
			
		nodo=cab;	
	while(nodo!=NULL ){
		cout<<"\t   ";	cout<<nodo->salon;cout<<"\n";
	
	//	cout<<"Salon : ";cout<<nodo->salon;cout<<" Codigo : ";cout<<nodo->codigo;cout<<"\n";
		
		nodo=nodo->ap1;
	
	

	}
	
		
	}
	cout <<"\nEmter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla
	
}




void borrar(){
		//buscamos el primer nodo de la lista Pito Cola y la retiramos 
	if(!cab)
	{
		cout << "Lista No Creada";
	}
	else
	{
		cout<<"\nEl Salon -> ";cout<<cab->salon;cout<<" <- Se borro de la lista ";
		nodo = cab;
		cab  = cab->ap1;
		delete nodo;
	}
	cout <<"\nEnter Para Continuar \n";
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
	

			p1 = cab; 
			int buscar=0; 
            seguir_borrar = 0;			
			while ( seguir_borrar == 0 )
			{
				if(p1->salon == borrar_cod)
				{
					buscar=1; 
					               // indicando que encontramos al menos un nodo a borrar
					if(cab == p1 ) // cuando borremos el primer elemento
					{
						if (cab == fin ) // En el momento que el primer elemento a borrar sea el unico de la lista 
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
						if (fin == p1) // en el momento que borremos el ultimo registro
						{	
						    fin = p2;       // retrocedemos el FIN al nodo anterior "p2"
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

	}
	cout <<"Emter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla
}


void mostrar(){
	if(!cab){
		cout<<"No existen elementos ";
		
	}else{
		system("cls");
		cout<<"-----------------------------------\n";
		cout<<"Salones registrados con codigo : "<<"\n";
		cout<<"-----------------------------------"<<"\n";
		
		
		nodo=cab;
		while(nodo!=NULL ){// muestran el primer elemento
		
				
			cout<<"Salon : ";cout<<nodo->salon;cout<<" Codigo : ";cout<<nodo->codigo;cout<<"\n";
			nodo=nodo->ap1;	

			
		}
		cout<<"\n";
		cout<<"-----------------------------------";
		cout<<"\nCodigo por cada salon\n";
		cout<<"-----------------------------------\n";
		
			nodo=p1;
		
		while(nodo!=NULL){
			if(nodo!=NULL){					
					
					if(nodo->ap2!=NULL){
							nodo=nodo->ap2;
							cout<<"Salon : ";cout<<nodo->salon;cout<<" Codigo : ";cout<<nodo->codigo;cout<<"\n";
						
					}	else{
							nodo=nodo->ap2;
					}
						
					
				
			}else{
					
				nodo=nodo->ap1;
			}
				
		}	
		
	}
	cout <<"\nEmter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla
}



void menu(){
system ("color 0b" );
	int op;
	while(op!=6){
		system ("cls");
		cout<<"----------Digite----------"<<"\n";
		
		cout<<"1: Capturar "<<"\n";
		cout<<"2: Mostrar salones "<<"\n";
		cout<<"3: Mostrar salones con codigo "<<"\n";
		cout<<"4: Borrar salon  "<<"\n";
		cout<<"5: Buscar salon borrar "<<"\n";
		cout<<"6: Salir "<<"\n";
		cout<<"----------Opcion----------"<<"\n";
		cout<<"\t    ";cin>>op;
		
		switch(op){
			case 1: capturar(); break;
			case 2: mostrar_salon();break;
			case 3: mostrar();break;
			case 4: borrar();break;
			case 5: borrar_especial(); break;
			
			
						
		}
	}
}


int main(){
	menu();
}


