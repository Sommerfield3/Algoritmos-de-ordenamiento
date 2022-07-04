#include <iostream>
using namespace std;
template <typename T>
void imprimir(T lista[], int tam){/*Para imprimir la lista*/
	for (int i=0;i<tam;i++){
		if (tam==1){
			cout<<lista[i];
		}
		else if (i==0){
			cout<<"["<<lista[i];
		}
		else if (i==(tam-1)){
			cout<<", "<<lista[i]<<"]";
		}
		else{
			cout<<", "<<lista[i];
		}
	}
}
template <typename T>
		bool descendente(T a, T b){
	return a>b;
}
template <typename T>
	bool ascendente(T a, T b){
	return a<=b;
}

template <typename T>
void intercambiar(T *a,T *b){
	T t=*a;
	*a=*b;
	*b=t;
}
template <typename T>
int particion(T lista[],int prim, int ult,bool (*funcion)(T,T)){
	T piloto=lista[ult];	
	int i=(prim-1);
	for (int j=prim;j<=ult-1;j++){
		if (funcion(lista[j],piloto)){/*Llamamos a la función apuntada por el puntero ingresado como parámetro.*/
			i++;
			intercambiar(&lista[i],&lista[j]);
		}
	}
	intercambiar(&lista[i+1],&lista[ult]);
	return (i+1);
}
template <typename T>
void quickSort(T lista[],int prim, int ult,bool (*funcion)(T,T)){
	if (prim<ult){/*Recursivo*/
		int part=particion(lista,prim,ult,funcion);
			quickSort(lista,prim,part-1,funcion);/*Primera división: inferior al piloto*/
			quickSort(lista,part+1,ult,funcion);/*Primera división: superior al piloto*/
	}
}
int main(int argc, char *argv[]) {
	int lista[]={56,34,123,8,204,323,235,53,5,322};
	int tam=sizeof(lista)/sizeof(lista[0]);
	quickSort(lista,0,tam-1,descendente);
	cout<<"La lista ordenada (descendentemente) es: ";
	imprimir(lista,tam);
	cout<<endl;
	quickSort(lista,0,tam-1,descendente);
	cout<<"La lista ordenada (descendentemente) es: ";
	imprimir(lista,tam);
	system("pause");
	return 0;
}

