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
	
}*cab,*nodo,*fin,*p1,*p2,*p3,*p4;
void borrar_salon();
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
/*Agregro*/		if(nodo->salon==cab->salon){ // el segundo viene aca si es igual ala cabecera cuando solo hay un elemento 
/*Agregro*/			nodo->ap2=p1->ap2;
/*Agregro*/			p1->ap2=nodo;
/*Agregro*/			cout<<"Se agrego en el salon "<<nodo->salon<<" ya existente";
/*Agregro*/			getch();
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
	}
}

void mostrar_salon(){
	if(!cab){
		cout<<"No existen elementos ";	
	}else{
		system("cls");
		cout<<"----------Salon----------"<<"\n";
		nodo=cab;
		while(nodo!=NULL){
		cout<<"\t   ";	cout<<nodo->salon;cout<<"\n";
			nodo=nodo->ap1;
		}
	}
	cout <<"\nEmter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla	
}
void borrar(){
		//buscamos el primer nodo de la lista Pila Cola y la retiramos 
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


void borrar_buscar(){
	int borrar; int seguir;
	cout<<"digite salon a borrar = ";
	cin>>borrar;
	if(!cab){
		cout<<"La lista no existe";
	}else{
		p1=cab;
		int buscar;
		seguir=0;
		while(p1->salon<=borrar && seguir==0){
			if(p1->salon==borrar && borrar<=p1->salon){
				buscar=1;
				if(cab==p1){
					if(cab==fin){ // cuando la cabecera esta sola
						cab=NULL;
						delete p1;
						seguir=1;
					}else{
						cab=p1->ap1; // la cabecera pasa al segundo lugar
						delete p1;
						p1=cab;
					}
				}else{
					if(fin==p1){ // fin se devuelve a p2
						fin=p2; 
						p2->ap1=NULL;
						delete p1;
						seguir=1;
					}else{
						p2->ap1=p1->ap1; // si esta en la mitad conecta con los otros
						delete p1;
						p1=p1->ap1;
					}
				}
			}else{
				p2=p1;
				p1=p1->ap1;	
			}	
		}
		if(buscar==0){
			cout<<"No existe salon ";
		}else{
			cout<<"Se retiro del nodo ";
		}	
	}
	cout <<"\nEnter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla
}
void mostrar(){
	if(!cab){
		cout<<"No existen elementos ";
	}else{
		system("cls");
		cout<<"-----------------------------------\n";
		cout<<"Salones registrados con codigo : "<<"\n";
		int seguir=1;
		p1=cab;
		while(p1!=NULL ){
			p2=p1;
			cout<<"-----------------------------------\n";
			cout<<"Salon : ";cout<<p2->salon<<"\n";
			while(p2!=NULL){
				
					cout<<" Codigo : ";cout<<p2->codigo;cout<<"\n";
					p2=p2->ap2;
			}
			p1=p1->ap1;
		}
	}
	cout <<"\nEmter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla
}


void borrar_salon(){ // el CODIGO PUEDE ESTAR EN CUALQUIER SALON
	if(!cab){
		cout<<"No existen elementos ";	
	}else{
		system("cls");
		int verificar;
		int borrar;
		cout<<"Codigo a buscar = \n";
		cin>>borrar;
		int encontrado=0;
		p1=cab;
		p3=cab;
		while(encontrado==0 && p1!=NULL){
				if(p1->codigo==borrar){
					verificar=1;
					if(cab==p1){
						if(cab->ap1==NULL && cab->ap2==NULL){// la cabecera es el unico elemento
							cab=NULL;
							delete p1;	
							encontrado=1;
						}else{
							if(cab->ap2==NULL){ // si cab no tiene elmentos abajo, cabecera sera el del lado
								cab=cab->ap1;	
								delete p1;
								encontrado=1;
							}else{ //cab pasara a ser el de abajo
							
								p1=cab;
								cab=cab->ap2;
								encontrado=1;
								cab->ap1=p1->ap1;
							}
						}	
					}else{
						if(fin==p1){
							if(fin->ap2==NULL){ // si fin no tiene elementos abajo este se devolvera
									fin=p4;
									p4->ap1=NULL;
									delete p1;
									encontrado=1;
							}else{ // si fin tiene elementos abajo pues este pasara hacer cabecera de	
								fin=fin->ap2;
								p3=fin;
								encontrado=1;
								p4->ap1=fin;
								fin=p3->ap1;
							}
						}else{ // si encuentra en la mitad
							if(p1->ap2==NULL && p1==p3){ // si enuentra en la mitad pero no hay nada abajo	
								p4->ap1=p3->ap1;
								delete p1;
								p3=p3->ap1;
								encontrado=1;
							}else{
								if(p1==p3){// si es elemento de la mitad pero hay elemtnos abajo este pasa hacer incio								
								p1=p1->ap2;
								p1->ap1=p3->ap1;
								encontrado=1;
								p4->ap1=p1;	
								}else{ // se borra si encuentra verticalmente pero no al inicio
									p2->ap2=p1->ap2;
									delete p1;
									p1=p1->ap2;
									encontrado=1;	
								}
							}
						}
					}
				}else{
					// movimiento
						if(p1->ap2==NULL){ 
							p4=p3;
							p3=p3->ap1;
							p1=p3;
						}else{
							p2=p1;
							p1=p1->ap2;			
						}
				}
		}
		if(verificar==0){
			cout<<"No existe Codigo ";
		}else{
			cout<<"Se retiro del nodo ";
		}
	}	
	cout <<"\nEmter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla
}

void borrar_salon_codigo(){	//BORRAR EL CODIGO QUE ENCUENTRE EN EL SALON
	if(!cab){
		cout<<"No existen elementos ";
	}else{
		system("cls");
		int verificar;
		int borrar,salon;
		cout<<"Salon a buscar = \n";
		cin>>salon;
		cout<<"Codigo a buscar = \n";
		cin>>borrar;
		int encontrado=0;
		p1=cab;
		p3=cab;
		while(encontrado==0 && p1!=NULL){
				if(p1->codigo==borrar && p1->salon==salon){ //CONDICION PARA ENCONTRAR EL CODIGO EN SU SALON
					verificar=1;
					if(cab==p1){
						if(cab->ap1==NULL && cab->ap2==NULL){// la cabecera es el unico elemento
							cab=NULL;
							delete p1;
							encontrado=1;
						}else{
							if(cab->ap2==NULL){ // si cab no tiene elmentos abajo, cabecera sera el del lado
								cab=cab->ap1;	
								delete p1;
								encontrado=1;
							}else{ //cab pasara a ser el de abajo	
								p1=cab;
								cab=cab->ap2;
								encontrado=1;
								cab->ap1=p1->ap1;
							}
						}
					}else{
						if(fin==p1){
							if(fin->ap2==NULL){ // si fin no tiene elementos abajo este se devolvera
									fin=p4;
									p4->ap1=NULL;
									delete p1;
									encontrado=1;
							}else{ // si fin tiene elementos abajo pues este pasara hacer cabecera de		
								fin=fin->ap2;
								p3=fin;
								encontrado=1;
								p4->ap1=fin;
								fin=p3->ap1;
							}
						}else{ // si encuentra en la mitad
							if(p1->ap2==NULL && p1==p3){ // si enuentra en la mitad pero no hay nada abajo	
								p4->ap1=p3->ap1;
								delete p1;
								p3=p3->ap1;
								encontrado=1;
							}else{
								if(p1==p3){// si es elemento de la mitad pero hay elemtnos abajo este pasa hacer incio								
								p1=p1->ap2;
								p1->ap1=p3->ap1;
								encontrado=1;
								p4->ap1=p1;			
								}else{ // se borra si encuentra verticalmente pero no al inicio
									p2->ap2=p1->ap2;
									delete p1;
									p1=p1->ap2;
									encontrado=1;	
								}
							}
						}
					}
				}else{
						if(p1->ap2==NULL){
							p4=p3;
							p3=p3->ap1;
							p1=p3;
						}else{
							p2=p1;
							p1=p1->ap2;				
						}
				}
	}
		if(verificar==0){
			cout<<"No existe Codigo ";
		}else{
			cout<<"Se retiro del nodo ";
		}
}	
	cout <<"\nEmter Para Continuar \n";
	getch();  //comando de espera mientras se presiona una tecla
}

void menu(){
system ("color 0b" );
	int op;
	while(op!=8){
		system ("cls");
		cout<<"----------Digite----------"<<"\n";
		
		cout<<"1: Capturar "<<"\n";
		cout<<"2: Mostrar salones registrados "<<"\n";
		cout<<"3: Mostrar todo "<<"\n";
		cout<<"4: Borrar salon por orden"<<"\n";
		cout<<"5: Buscar salon a borrar "<<"\n";
		cout<<"6: Buscar codigo a borrar "<<"\n";
		cout<<"7: Buscar salon con codigo para borrar "<<"\n";
		cout<<"8: Salir "<<"\n";
		cout<<"----------Opcion----------"<<"\n";
		cout<<"\t    ";cin>>op;
		
		switch(op){
			case 1: capturar(); break;
			case 2: mostrar_salon();break;
			case 3: mostrar();break;
			case 4: borrar();break;
			case 5: borrar_buscar();break;
			case 6: borrar_salon(); break;
			case 7: borrar_salon_codigo(); break;			
		}
	}
}

int main(){
	menu();
}


