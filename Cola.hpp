/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.hpp
 * Author: Usuario
 *
 * Created on 2 de septiembre de 2018, 09:46 PM
 */

#ifndef COLA
#define COLA // Define la cola
using namespace std;

template <class T>
class Cola{
    struct Nodo{
        T elemento;
        struct Nodo* siguiente;  // coloca el nodo en la segunda posición
    };
    Nodo* primero;
    Nodo* ultimo;
    unsigned int elementos;

public:
    Cola():
    primero(0),
    ultimo(0),
    elementos(0)
    {}
       
    ~Cola(){
        while (elementos != 0) pop();
    }

    void push(const T& elem){
        Nodo* aux = new Nodo;
        aux->elemento = elem;
        if (elementos == 0) primero = aux;
        else ultimo->siguiente = aux;
        ultimo = aux;
        ++elementos;
    }

    void pop(){
        Nodo* aux = primero;
        primero = primero->siguiente;
        if (ultimo == aux){
            ultimo = primero;
        }
        delete aux;
        --elementos;
    }

    T consultar() const{
        return primero->elemento;
    }
    bool vacia() const{
        return elementos == 0;
    }
    unsigned int size() const{
        return elementos;
    }
};
#endif