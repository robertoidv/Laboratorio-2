#include "arbol_L7_L8.h"
//---------------------------------------------------------------------------
int main(){
	Nodo *NuevoNodo,*NodoLeido;
	Arbol *arbol;
	arbol=malloc(sizeof(Arbol));
	int nombreNodo=1;
	int alternativa;
	printf("1)Crear Nodo Prueba\n2)Leer Nodo Prueba\nAlternativa: ");
	scanf("%i",&alternativa);
	int clave=20;
	switch(alternativa){
		case 1: NuevoNodo=CrearNodo(nombreNodo);
		GuardarNodo(NuevoNodo);
		arbol->raiz=nombreNodo;
		break;
		case 2:
		NodoLeido=leeNodo(nombreNodo);
		if(NodoLeido!=0){
		imprimeNodo(NodoLeido);
		}
		break;	
	}
	insertaClave(arbol,clave);	
}
