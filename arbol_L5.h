#include<stdio.h>
#include<stdlib.h>
#include <math.h>
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
	printf("%c\n",caracter);
	system("pause");
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
}
//----------------------------------------------------------------------
int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
//---------------------------------------------------------------------
int alturaArbol(Arbol *unArbol){
	if(unArbol==NULL){
		return (-1);
	}
	return (1+max(alturaArbol(unArbol->hizq),alturaArbol(unArbol->hder)));
}
//-----------------------------------------------------------------------
void copiarArbolenArreglo(Arbol *unArbol,int tamano,char arreglo[tamano],int pos){
	if(unArbol==NULL){
		arreglo[pos]='N';
		return;
	}
	arreglo[pos]=unArbol->dato;
	copiarArbolenArreglo(unArbol->hizq,tamano,arreglo,2*pos+1);
	copiarArbolenArreglo(unArbol->hder,tamano,arreglo,2*pos+2);
}
//----------------------------------------------------------------------
void vaciarArreglo(int tamano,char arreglo[tamano]){
	int i=0;
	while(i<tamano){
		arreglo[i]='\0';
		i++;
	}
}
//---------------------------------------------------------------------
char *crearArbolEnArreglo(Arbol *unArbol){
	int h;
	h=alturaArbol(unArbol);
	int tamano;
	tamano=(pow(2,h+2)-1);		//tamaño maximo de nodo que puede haber en un arbol de altura h
	char *arreglo=malloc(sizeof(char)*tamano);
	vaciarArreglo(tamano,arreglo);
	copiarArbolenArreglo(unArbol,tamano,arreglo,0);
	return arreglo;
}
//-----------------------------------------------------------------------
int muestraArbolEnTerminal(Arbol *unArbol){
	char *arreglo;
	int h;
	arreglo=crearArbolEnArreglo(unArbol);
	h=alturaArbol(unArbol);
	int tamano;
	tamano=(pow(2,h+2)-1);

	int contador=0,nivelActual=0,nodosEnNivel=0,nodoActual=0;
							//contador es un indice que recorre los nodos actuales de un nivel
							//mientras que niveles es otro indice recorre los niveles que tiene el arbol
							//nodosEnNivel se usa porque no me deja usar el pow en un if
							//nodoActual es un indice que recorre TODOS los nodos actuales

	while(nivelActual<h+2){
			nodosEnNivel=pow(2,nivelActual);
			contador=0;
			while(contador<nodosEnNivel){
				printf("%c",arreglo[nodoActual]);
				contador++;
				nodoActual++;
			}
			printf("\n");
			nivelActual++;
	}
}
