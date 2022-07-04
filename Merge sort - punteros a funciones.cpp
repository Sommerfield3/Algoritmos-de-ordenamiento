#include <iostream>
using namespace std;
class prueba2{
public:
	string nombre;
	int numero;
	void pruebaDatos(string nom,int num);
	bool operator>(prueba2 &b);
	bool operator<=(prueba2 &b);
};
void prueba2::pruebaDatos(string nom,int num){
	nombre=nom;
	numero=num;
}
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
		if ((*func)(listaIzq[lista1PosActual],listaDer[lista2PosActual])){/*Llamamos a la función apuntada por el puntero ingresado como parámetro.*/
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
template <typename T>
void imprimir(T lista[], int tam){
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
void imprimirObjetosPruebaAlter(prueba2 lista[], int tam){
	for (int i=0;i<tam;i++){
		if (tam==1){
			cout<<lista[i].numero;
		}
		else if (i==0){
			cout<<"["<<lista[i].numero;
		}
		else if (i==(tam-1)){
			cout<<", "<<lista[i].numero<<"]";
		}
		else{
			cout<<", "<<lista[i].numero;
		}
	}
	cout<<endl;
}void imprimirObjetosPrueba(prueba2 lista[], int tam){
	for (int i=0;i<tam;i++){
		if (tam==1){
			cout<<lista[i].nombre;
		}
		else if (i==0){
			cout<<"["<<lista[i].nombre;
		}
		else if (i==(tam-1)){
			cout<<", "<<lista[i].nombre<<"]";
		}
		else{
			cout<<", "<<lista[i].nombre;
		}
	}
	cout<<endl;
}
	
int main(int argc, char *argv[]) {
	prueba2 *listaObjetos=new prueba2[4];
	listaObjetos[0].pruebaDatos("primerObjeto",774);
	listaObjetos[1].pruebaDatos("segundoObjeto",33);
	listaObjetos[2].pruebaDatos("tercerObjeto",12);
	listaObjetos[3].pruebaDatos("cuartoObjeto",84);
	int lista[]={45,3342,23,34,23,4};
	int lista2[]={1,2,3,234,4,5,854,6,122,7,8};
	string lista3[]={"a","b","j","x","c","d","g"};
	int tam=sizeof(lista)/sizeof(lista[0]);
	int tam2=sizeof(lista2)/sizeof(lista2[0]);
	int tam3=sizeof(lista3)/sizeof(lista3[0]);
	cout<<"Lista de objetos inicial: "<<endl;
	cout<<"Por metodo nombre: ";
	imprimirObjetosPrueba(listaObjetos, 4);
	cout<<endl;
	cout<<"Por metodo numero: ";
	imprimirObjetosPruebaAlter(listaObjetos, 4);
	cout<<endl;
	cout<<"Lista 1 inicial: "<<endl;
	imprimir(lista, tam);
	cout<<endl;
	cout<<"Lista 2 inicial: "<<endl;
	imprimir(lista2, tam2);
	cout<<endl;
	cout<<"Lista 3 inicial: "<<endl;
	imprimir(lista3, tam3);
	cout<<endl;
	cout<<"Procesando..."<<endl;
	mergeSort(listaObjetos,0,3,descendente);
	mergeSort(lista,0,tam-1,descendente); /*Aplicamos el ordenamiento.*/
	mergeSort(lista2,0,tam2-1,ascendente); /*Aplicamos el ordenamiento.*/
	mergeSort(lista3,0,tam3-1,ascendente); /*Aplicamos el ordenamiento.*/
	cout<<"Listas procesadas"<<endl;
	cout<<"Lista de objetos resultante (descendente): "<<endl;
	cout<<"Por metodo nombre: ";
	imprimirObjetosPrueba(listaObjetos, 4);
	cout<<endl;
	cout<<"Por metodo numero: ";
	imprimirObjetosPruebaAlter(listaObjetos, 4);
	cout<<endl;
	cout<<"Lista 1 resultante (descendente): "<<endl;
	imprimir(lista, tam);
	cout<<endl;
	cout<<"Lista 2 resultante (ascendente): "<<endl;
	imprimir(lista2, tam2);
	cout<<endl;
	cout<<"Lista 3 resultante (ascendente): "<<endl;
	imprimir(lista3, tam3);
	cout<<endl;
	system("pause");
	return 0;
}

