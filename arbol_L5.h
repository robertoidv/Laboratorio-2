#include<stdio.h>
#include<stdlib.h>
//----------------------------------------------------------------------
typedef struct _nodo{
	int dato;
	struct _nodo *hizq,*hder;
}Arbol;
//----------------------------------------------------------------------
int abrirArchivo(char nombreArchivoArbol[]){	
	FILE *archivo;
	archivo=fopen(nombreArchivoArbol,"r");
		if(archivo==NULL){
			return 0;
		}else{
		return 1;
		}
	fclose(archivo);	
}
//----------------------------------------------------------------------
Arbol *CrearNodo(char caracter){
	Arbol *nuevo;
	nuevo=malloc(sizeof(Arbol));
	nuevo->dato=caracter;
	nuevo->hizq=NULL;
	nuevo->hder=NULL;
	return nuevo;
}
//----------------------------------------------------------------------
Arbol *serializa(FILE *archivo){
	char caracter;
	caracter=fgetc(archivo);
	//printf("%c\n",caracter);
	//system("pause");
		if(caracter=='N'){
			return NULL;
		}else{
			Arbol *Nuevo_nodo;
			Nuevo_nodo=CrearNodo(caracter);
			Nuevo_nodo->hizq=serializa(archivo);
			Nuevo_nodo->hder=serializa(archivo);
			return Nuevo_nodo;
	}
}
//----------------------------------------------------------------------
Arbol *creaArbol(char nombreArchivoArbol[]){
		FILE *archivo;
		archivo=fopen(nombreArchivoArbol,"r");
		Arbol *auxArbol;
		auxArbol = serializa(archivo); 
		fclose(archivo);
		return auxArbol;
}/*
//----------------------------------------------------------------------
int calcularalturaArbol(Arbol unArbol){
}
//----------------------------------------------------------------------
Dato *creaArbolenarreglo(Arbol unArbol){
}
//----------------------------------------------------------------------
int muestraArbolenterminal(arbol unArbol){
}

