#include <stdio.h>
#include <stdlib.h >
#include <math.h>
#define T 200
//-------------------------------------------------------------
typedef struct _nodo{
	
	int claves[2*T-1];
	int hijos[2*T];
	char eshoja;
	int cantidadactual;
	int MiNombre;	
	
}Nodo;
//-------------------------------------------------------------
typedef struct _arbol{
	int raiz;
	int cantidadNodos;
}Arbol;
//Cormen asume que los arreglos parten en 1
//-------------------------------------------------------------
Nodo *CrearNodo(int nombreNodo){

	Nodo *Nuevo_nodo;
	Nuevo_nodo=malloc(sizeof(Nodo));
	int i=0;
	for(i;i<(2*T-1);i++){
		/*printf("\nIntroduzca la clave %i:",i);
		scanf("%i",&Nuevo_nodo->claves[i]);*/
		Nuevo_nodo->claves[i]=i;
		Nuevo_nodo->hijos[i]=i;
	}
	
	Nuevo_nodo->hijos[2*T-1]=0;
	Nuevo_nodo->cantidadactual=2*T-1;
	Nuevo_nodo->eshoja=1;
	Nuevo_nodo->MiNombre=nombreNodo;
	return(Nuevo_nodo);
	
}
//-------------------------------------------------------------
int GuardarNodo(Nodo *nodo){

	FILE *estructura;
	if(nodo==NULL){
		return -1;
	}
	char nombreNodo[10];
	if(estructura==NULL){
		return 0;
	}else{
		sprintf(nombreNodo,"%i",nodo->MiNombre);
		estructura=fopen(nombreNodo,"wb");
		fwrite(nodo,sizeof(Nodo),1,estructura);
		printf("Nodo Creado en el disco duro\n");
		}
	fclose(estructura);
	
}
//-------------------------------------------------------------
Nodo *leeNodo(int nombre){
	FILE *estructura;
	Nodo *nodoLeido;
	nodoLeido=malloc(sizeof(Nodo));
	char nombreNodo[10];
	sprintf(nombreNodo,"%i",nombre);
	estructura=fopen(nombreNodo,"rb");
	if(estructura==NULL){
		printf("Error\nNo existe el nodo");
		return 0;
	}else{
		printf("\nNodo leido en el disco duro\n");
	}
	fread(nodoLeido,sizeof(Nodo),1,estructura);
	return(nodoLeido);
}
//-------------------------------------------------------------
Nodo *insertaClave(Arbol *arbol,int clave){
	arbol->cantidadNodos++;
	int nombreNodo=(arbol->cantidadNodos);	
	Nodo *r=leeNodo(arbol->raiz);
	if(r->cantidadactual==2*T-1){
		Nodo *s=CrearNodo(nombreNodo);
		arbol->raiz=s->MiNombre;
		s->eshoja=0;
		s->cantidadactual=0;
		s->hijos[0]=r->MiNombre;
		divideHijoArbolB(s,0);
		insertarNoLLenoArbolB(s,clave);
	}else{
		insertaNoLLenoArbolB(r,clave);
	}
}
//-------------------------------------------------------------

int divideHijoArbolB(Nodo *s,int clave){
	Nodo *z;
	
}

int insertarNoLLenoArbolB(Nodo *s,int clave){
	
}

int insertaNoLLenoArbolB(Nodo *r,int clave){
	
}
//-------------------------------------------------------------
int imprimeNodo(Nodo *nodoLeido){
	printf("Nombre del nodo: %i \n",nodoLeido->MiNombre);
	int i=0;
	for(i=0;i<(2*T-1);i++){
		printf("Claves:%i \n",nodoLeido->claves[i]);
		printf("hijos: %i \n",nodoLeido->hijos[i]);
	}
	
}
