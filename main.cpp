#include "NodoArbolBinario.h"
#include "NodoArbolNArio.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

int suma(NodoArbolBinario* raiz)
{
    int TotalSuma=0; //variable que guarda los elemntos del arbol

    if(raiz==NULL) //si el arbol esta vacio retornamos 0
        return 0;

        TotalSuma+= raiz->num; //si no esta vacio guardamos los elementos de la raiz en la variable

        TotalSuma+=suma(raiz->hijo_der)+suma(raiz->hijo_izq);// Hacemos la llamada recursiva por el lado derecho y el lado izquierdo para guardar todos los valores del arbol
    return TotalSuma;// al final retornamos la suma de todos los elementos del arbol
}

int suma(NodoArbolNArio* raiz)
{
    int totalSuma=0;// variable que guarda los elementos del arbol
    if (raiz == NULL)//si el arbol esta vacio retornamos 0
        return 0 ;

    totalSuma+=raiz->num;//si no esta vacio guardamos los elemtos de la raiz en la variable

    for(list<NodoArbolNArio*>::iterator a = raiz-> hijos.begin();a!= raiz->hijos.end();a++){
                 totalSuma+= suma(*a);
                 } //recorremos el arbol con el iterador y sumamos los elementos del arbol con la funcion recursiva
    return totalSuma;//retornamos la suma de todos  los elementos
}

int cantidadNodos(NodoArbolBinario* raiz)
{
    int c=0;//Variable para guardar la cantidad de nodos

    if(raiz==NULL)//si el arbol esta vacio retornamos cero
        return 0;
        c+=1;//sumamos uno en la variable c por cada elemento del arbol
        c+=(cantidadNodos(raiz->hijo_der) + cantidadNodos(raiz->hijo_izq));//funcion recursiva que recorre el arbol
    return c; //retornamos la cantidad de elementos en el arbol
}

int cantidadNodos(NodoArbolNArio* raiz)
{
     int c=0;//variable para guardar la cantidad de nodos
    if(raiz==NULL)//si el arbol esta vacio retornamos cero
        return 0;
        c+=1;//sumamos un en la variable c por cada nodo del arbol
        for(list<NodoArbolNArio*>::iterator a = raiz->hijos.begin(); a!= raiz->hijos.end(); a++ ){//recorremos el arbol con un iterador y sumamos uno en la variable c por cada nodo encontrado
            c+=cantidadNodos(*a);//funcion recursiva para guardar en c cuantos nodos hay en el arbol
        }
    return c; //retornamos la cantidad de nodos

}

int promedio(NodoArbolBinario* raiz)
//volvi a implementar cada una de las funciones anteriores para sumar y contar los elementos
    //del arbol al final en la variable p divido la suma de los elementos del arbol entre la cantidad
    //de elementos que hay en el arbol y retorno el promedio

{

    int prom=0;
    int TotalSuma=0;
    if(raiz==NULL)
        return 0;
        TotalSuma+= raiz->num;
        TotalSuma+=suma(raiz->hijo_der)+suma(raiz->hijo_izq);

    int c=0;
        c+=1;
        c+=(cantidadNodos(raiz->hijo_der) + cantidadNodos(raiz->hijo_izq));

    prom=TotalSuma/c;
   return prom;
}

int promedio(NodoArbolNArio* raiz)
{
    //volvi a implementar cada una de las funciones anteriores para sumar y contar los elementos
    //del arbol al final en la variable p divido la suma de los elementos del arbol entre la cantidad
    //de elementos que hay en el arbol y retorno el promedio
    int p=0;
    int totalSuma=0;
    if (raiz == NULL)
        return 0 ;

    totalSuma+=raiz->num;

    for(list<NodoArbolNArio*>::iterator i = raiz-> hijos.begin();i!= raiz->hijos.end();i++){
                 totalSuma+= suma(*i);
                 }

     int c=0;
        c+=1;
        for(list<NodoArbolNArio*>::iterator i = raiz->hijos.begin(); i!= raiz->hijos.end(); i++ ){
            c+=cantidadNodos(*i);
        }

        p= totalSuma/c;


    return p;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}
