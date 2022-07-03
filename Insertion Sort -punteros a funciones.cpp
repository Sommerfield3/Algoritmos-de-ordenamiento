#include <iostream>
using namespace std;
class prueba{
public:
	string nombre;
	int numero;
	bool operator>(prueba &b);
	bool operator<=(prueba &b);
};
bool prueba::operator>(prueba &b){
	return numero>b.numero;
}
bool prueba::operator<=(prueba &b){
	return numero<=b.numero;
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
	cout<<endl;
}
void imprimirObjetosPrueba(prueba lista[], int tam){
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
void insertionSort(T lista[],int tam, bool (*funcion)(T,T)){/*Esta función es usada para ordenar de menor a mayor*/
	int i=1;
	int j;
	while (i<tam){
		T menMay;
		menMay=lista[i];
		j=i-1;
		while (j>=0 && funcion(menMay,lista[j])){
			lista[j+1]=lista[j];
			j--;
		}
		lista[j+1]=menMay;/*
		cout<<"Búsqueda desde el elemento actual ("<<i<<"): ";
		void (*impr)(int[],int);
		impr=&imprimir;
		(*impr)(lista, tam);
		cout<<endl;*/
		i++;
	}
}

int main(int argc, char *argv[]) {
	prueba *lista=new prueba[6];
	lista[0].nombre="a";
	lista[1].nombre="b";
	lista[2].nombre="c";
	lista[3].nombre="d";
	lista[4].nombre="e";
	lista[5].nombre="f";
	lista[0].numero=661;
	lista[1].numero=348;
	lista[2].numero=845;
	lista[3].numero=969;
	lista[4].numero=765;
	lista[5].numero=137;
	int lista1[]={23,432,325,45,5,25};
	float lista2[]={88.23,52.12,75.56,4.98,97.655,97.5,100.34};
	int tam1=sizeof(lista1) / sizeof(lista1[0]);/*Tamaño del array*/
	int tam2=sizeof(lista2) / sizeof(lista2[0]);
	cout<<"La lista de objetos inicial (se muestra el numero) es: ";
	imprimirObjetosPrueba(lista, 6);/*Imprimimos la lista final*/
	cout<<"La lista 1 inicial es: ";
	imprimir(lista1, tam1);
	cout<<"La lista 2 inicial es: ";
	imprimir(lista2, tam2);
	insertionSort<int>(lista1,tam1,descendente);
	insertionSort<float>(lista2,tam2,ascendente);
	insertionSort<prueba>(lista,6,descendente);
	cout<<"La lista de objetos final (Descendente) es: ";
	imprimirObjetosPrueba(lista, 6);/*Imprimimos la lista final*/
	cout<<"La lista 1 final (Descendente) es: ";
	imprimir(lista1, tam1);
	cout<<"La lista 2 final (Ascendente) es: ";
	imprimir(lista2, tam2);
	delete [] lista;
	system("pause");
	return 0;
}
