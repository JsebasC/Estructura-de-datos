#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct pila{
	int codigo;
	pila *siguiente;
	
}*cab,*nodo;


void capturar(){
	if(!cab){
		nodo= new (pila);
		cout<<"\n Digite elemento = ";
		cin>>nodo->codigo;
		nodo->siguiente=NULL;
		cab=nodo;
	}else{
		nodo= new (pila);
		cout<<"\ Digite elemento = ";
		cin>>nodo->codigo;
		nodo->siguiente=cab;
		cab=nodo;
	}
}

void mostrar(){
	if(!cab){
		cout<<"Lista no creada ";
	}else{
		system("cls");  //  comando para limpiar pantalla
		nodo=cab;
		while(nodo!=NULL){
		
			cout<<nodo->codigo;
			cout<<"\n";
			nodo=nodo->siguiente;
		}
	}
}

void borrar(){
	if(!cab){
		cout<<"Lista no creada ";
		
	}else{
		system("cls");  //  comando para limpiar pantalla
		nodo=cab;
		cab=cab->siguiente;
		delete nodo;
	}
}

void menu(){
	int op;
	cout<<"---------------------\n";
	cout<<"			PILA 	    ";
	cout<<"---------------------\n";
	while(op!=4){
		cout<<"Digite \n";
		cout<<"1 = Insertar \n";
		cout<<"2 = Mostrar \n";
		cout<<"3 = Delete \n";
		cout<<"4 = Salir "
	cout<< "    " ;cin>>op;
		switch(op){
			case 1: capturar(); break;
			case 2: mostrar();break;
			case 3: borrar();break;
		
		}
	}
	
}

int main(){
	menu();
	return 0;
}
