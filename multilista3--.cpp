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
	lista *ap3;
}*cab,*nodo,*fin,*p1,*p2,*cabn,*finn,*nodo_new;

void capturar_ordenar(){

	
	if(!cab){ // el primer elemento se agrega aca
		cout<<" No existe una lista";
	
		
	}else{
		cabn=NULL;
		nodo=cab;
		while(nodo!=NULL){
			nodo_new=new lista;
			nodo_new->salon =nodo->salon; 
			nodo_new->codigo =nodo->codigo;
			
			if(!cabn){
			   cabn =nodo_new;
		      finn = nodo_new;
		      cabn->ap1 = NULL;
		      cabn->ap2 = NULL;
		      	nodo->ap3 = NULL;
		      cout<<"creo 1";
		      nodo = nodo->ap1; // avanzamos en la Lista Cola
			}else{
				   if (cabn->salon > nodo_new->salon)
		       {
			      nodo_new->ap1  = cabn;
			      //cabn->ap2  = Nodo_new;
			      cabn = nodo_new;
			      //cabn->ap2  = NULL;
			      cout<<"creo inicio 2";
			      nodo = nodo->ap1; // avanzamos en la Lista Cola
	        	}
		        else
		    	{
			    	if (nodo_new->salon > finn->salon)
		    		{
			    		finn->ap1 = nodo_new;
				    	nodo_new->ap3 = finn;
						finn = nodo_new;
						finn->ap1 = NULL;
						cout<<"creo fin 3";
						nodo = nodo->ap1; // avanzamos en la pila
			    	}
					else
					{
			    		p1 = cabn;
			    		p2 = cabn->ap1;
				    	char insertar='n';
				    	while (insertar == 'n')
				  		{
					    	if(nodo_new->salon < p2->salon)
					    	{
					    			if(nodo_new->salon==p1->salon){
										nodo_new->ap2=p1->ap2;
										p1->ap2=nodo_new;
										cout<<"Se agrego en el salon "<<nodo->salon<<" ya existente";
										insertar=1;
										getch();
									}else{
										nodo_new->ap1=p2;
										p1->ap1=nodo_new;
										insertar=1;
									}
							
					    	/*	nodo_new->ap1 = p2;
					    		Nodo_new->ap2 = p1;
						   		p1->ap1 = Nodo_new;
						    	p2->ap2 = Nodo_new;
						    	cout<<"creo inter 4";
						    	insertar='s';
						    	Nodo = Nodo->ap1; // avanzamos en la pila*/
					   		}	 
					    	else
				    		{
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
	
}

void capturar()
{

	
	if(!cab) //Lista tipo Cola
	{
		system ("cls");
		nodo=new lista;
		cout<<"Digite Salon = ";
		cin>>nodo->salon;
		cout<<"Digite Codigo = ";
		cin>>nodo->codigo;
		nodo->ap1=NULL;
		nodo->ap2=NULL;
		nodo->ap3 = NULL;
			
		cab = nodo;
		fin = nodo;
	}
	else
	{
		nodo=new lista;
		cout<<"Digite Salon = ";
		cin>>nodo->salon;
		cout<<"Digite Codigo = ";
		cin>>nodo->codigo;
		nodo->ap1=NULL;
		nodo->ap2=NULL;
		nodo->ap3 = fin;
		
        fin->ap1 = nodo;
		fin = nodo;
		
			p1=cab;
				
				if(nodo->salon==cab->salon){ // el segundo viene aca si es igual ala cabecera cuando solo hay un elemento 
					nodo->ap2=p1->ap2;
					p1->ap2=nodo;
					cout<<"Se agrego en el salon "<<nodo->salon<<" ya existente";
					getch();
				}else{ 
				
					p1=cab;
					p2=cab->ap1;
					int insertar=0;
					
					while(insertar==0){ // se posiciona en la mitad
					
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

void mostrar_ascendente(){
	if(!cabn){
		cout<<"No existen elementos ";
		
	}else{
		system("cls");
		cout<<"----------Salon----------"<<"\n";
	

		nodo=cabn;
		while(nodo!=NULL){
		
		
		cout<<"\t   ";	cout<<nodo->salon;cout<<"\n";
		
		
			nodo=nodo->ap1;
				
				
			
		}
	}
	cout <<"\nEmter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla
	
}

void mostrar_descendente()
{
	if (!cabn)
	{cout <<"no existe lista1";
	}
	else
	{
        system("cls");  //  comando para limpiar pantalla
        cout <<" Los elementos de la lista son : \n";
		nodo = finn;  // iniciamos la lista desde el Finn 
		cout<<"lista Descendente: "<<'\n';
		while(nodo != NULL)
		{
			cout<<"\t   ";	cout<<nodo->salon;cout<<"\n";
		
			nodo=nodo->ap3;  // el avance es descendente hacia la izquierda
		}
	}
	cout <<"\n\n Emter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla
}

void mostrar_orden1()
{
	capturar_ordenar();
	mostrar_ascendente();
}

void mostrar_orden2()
{
	capturar_ordenar();
	mostrar_descendente();
}

void mostrar_cola()
{
	if(!cab)
	{
		cout << "Lista No Creada \n";
	}else
	{
        system("cls");  //  comando para limpiar pantalla
        cout <<" Los elementos de la lista son : \n";
		nodo=cab;
		while(nodo != NULL)
		{
				cout<<"\t   ";	cout<<nodo->salon;cout<<"\n";
		
			cout << "\n";
			nodo=nodo->ap1;
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
			
			while(nodo->ap2!=NULL){
						
				
				//	cout<<"Aca 1 ";
				//	getch();
				nodo=nodo->ap2;
					cout<<"Salon : ";cout<<nodo->salon;cout<<" Codigo : ";cout<<nodo->codigo;cout<<"\n";
					
					
				
			
			}
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

void menu(){
system ("color 0b" );
	int op;
	while(op!=7){
		system ("cls");
		cout<<"----------Digite----------"<<"\n";
		
		cout<<"1: Capturar "<<"\n";
		cout<<"2: Mostrar salones registrados "<<"\n";
		cout<<"3: Mostrar orden 1 "<<"\n";
		cout<<"4: Mostrar orden 2 "<<"\n";
		cout<<"5:  "<<"\n";
		cout<<"6:  "<<"\n";
		cout<<"7: Salir "<<"\n";
		cout<<"----------Opcion----------"<<"\n";
		cout<<"\t    ";cin>>op;
		
		switch(op){
			case 1: capturar(); break;
			case 2: mostrar_cola();break;
			case 3: mostrar_orden1();break;
			case 4: mostrar_orden2();break;
		
						
		}
	}
}


int main(){
	menu();
}


