#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct nodo{
string dato;
	nodo *siguiente;
	
};
void agregar(nodo *&,string);
void sacar(nodo *&, string &);
void agregar(nodo *&pila, string n){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->siguiente=pila;
	pila=nuevo_nodo;
	
}
void sacar(nodo *&pila, string &n){
	nodo *aux=pila;
	n=aux->dato;
	pila=aux->siguiente;
	delete aux;
	
}
int main(){
	nodo *pila=NULL;
string x;
int cantidad;
	cout<<"Digite cantidad de elementos a agregar = "<<endl;
	cin>>cantidad;
	for(int i=0;i<cantidad;i++){
		cout<<"\nDato numero "<<i+1<< " " ;
		cin>>x;
		agregar(pila,x);
		
	}
	
	cout<<"\ncando elementos pila ";
	
	while(pila!=NULL){
		sacar(pila,x);
		
		if(pila!=NULL){
			cout<<x<<" , ";
		}else{
			cout<<x<<" . ";
		}
		
		
	}
	
	getch();
}
