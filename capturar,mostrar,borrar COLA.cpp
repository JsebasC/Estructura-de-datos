#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct cola{
	int codigo;
	cola *siguiente;
	
}*cab,*nodo,*fin;


void capturar(){
		nodo= new (cola);
		cout<<"\n Digite elemento = ";
		cin>>nodo->codigo;
		nodo->siguiente=NULL;
	
	if(!cab){
		cab=nodo;
		fin=nodo;
	}else{
		fin->siguiente=nodo;
		fin=nodo;
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
	cout<<"			COLA   	    ";
	cout<<"---------------------\n";
	while(op!=4){
		cout<<"Digite \n";
		cout<<"1 = Insertar \n";
		cout<<"2 = Mostrar \n";
		cout<<"3 = Delete \n";
		cout<<"4 = Salir ";
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
