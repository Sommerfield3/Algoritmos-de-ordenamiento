#include <iostream>
using namespace std;
class prueba2{
public:
	string nombre;
	int numero;
	bool operator>(prueba2 &b);
	bool operator<=(prueba2 &b);
};
bool prueba2::operator>(prueba2 &b){
	return numero>b.numero;
}
bool prueba2::operator<=(prueba2 &b){
	return numero<=b.numero;
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
void merge(T lista[],int izq,int med, int der, bool (*func)(T,T)){
	auto const lista1Tam=med-izq+1;
	auto const lista2Tam=der-med;
	T *listaIzq=new T[lista1Tam];
	T *listaDer=new T[lista2Tam];
	for (int i=0;i<lista1Tam;i++){
		listaIzq[i]=lista[izq+i]; /*Recorremos todas las posiciones de listaIzq llenando con elementos de lista desde la parte inicial indicada.*/
	}
	for (int j=0;j<lista2Tam;j++){
		listaDer[j]=lista[med+1+j]; 
	}
	int lista1PosActual=0;
	int lista2PosActual=0;
	int MergedPosActual=izq;
	while (lista1PosActual<lista1Tam && lista2PosActual<lista2Tam){
		if ((*func)(listaIzq[lista1PosActual],listaDer[lista2PosActual])){
			lista[MergedPosActual]=listaIzq[lista1PosActual];
			lista1PosActual++;
		}
		else{
			lista[MergedPosActual]=listaDer[lista2PosActual];
			lista2PosActual++;
		}
		MergedPosActual++;
	}
	while (lista1PosActual<lista1Tam){
		lista[MergedPosActual]=listaIzq[lista1PosActual];
		lista1PosActual++;
		MergedPosActual++;
	}
	while (lista2PosActual<lista2Tam){
		lista[MergedPosActual]=listaDer[lista2PosActual];
		lista2PosActual++;
		MergedPosActual++;
	}
	delete [] listaIzq;
	delete []listaDer;
}	
template <typename T>
void mergeSort(T lista[],int inic,int fin, bool (*func)(T,T)){
	if (inic<fin){
		int med=inic+(fin-inic)/2;
		void (*mismo)(T[],int,int, bool (*func)(T,T));
		void (*base)(T[],int,int,int,bool (*func)(T,T));
		mismo=&mergeSort;
		base=&merge;
		(*mismo)(lista,inic,med,func);
		(*mismo)(lista,med+1,fin,func);
		(*base)(lista,inic,med,fin,func);
	}
}
void imprimir(int lista[], int tam){
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
int main(int argc, char *argv[]) {
	int lista[]={45,3342,23,34,23,4};
	int tam=sizeof(lista)/sizeof(lista[0]);
	cout<<"Lista inicial: "<<endl;
	imprimir(lista, tam);
	cout<<endl;
	cout<<"Procesando..."<<endl;
	mergeSort(lista,0,tam-1,ascendente); /*Aplicamos el ordenamiento.*/
	cout<<"Lista procesada"<<endl;
	cout<<"Lista resultante: "<<endl;
	imprimir(lista, tam);
	cout<<endl;
	system("pause");
	return 0;
}

