/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   ordonnanceur.h
 * Author: etudiant
 *
 * Created on 3 octobre 2024, 19 h 23
 */

#ifndef ORDONNANCEUR_H
#define ORDONNANCEUR_H
#include <sstream>
#include <string>
#include <vector>
#include "Processus.h"
#include <queue>
#include <vector>
#include <stdexcept>
#include <algorithm>
template <typename T>
class file {
public:
    bool estvide() const { return data.empty(); }
    void enfiler(const T &p) { data.push_back(p); }
    T defiler() {
        if (estvide()) throw std::runtime_error("File vide");
        T element = data.front();
        data.erase(data.begin());
        return element;
    }
       int taille() const {
        return data.size();
    }
        T& front() {
        if (estvide()) {
            throw std::out_of_range("La file est vide");
        }
        return head->data;
    }
         void trier(bool (*comparer)(const T&, const T&)) {
        std::sort(data.begin(), data.end(), comparer);
    }
    void retirer(const T& element) {
        auto it = std::remove_if(data.begin(), data.end(), [&element](const T& e) {
            return e.req_pid() == element.req_pid();  // Supposons que vous utilisez req_pid pour identifier le processus
        });
        data.erase(it, data.end());
    }
    // Méthodes pour obtenir des itérateurs
    typename std::vector<T>::iterator begin() {
        return data.begin();
    }

    typename std::vector<T>::iterator end() {
        return data.end();
    }

    typename std::vector<T>::const_iterator begin() const {
        return data.begin();
    }

    typename std::vector<T>::const_iterator end() const {
        return data.end();
    }

private:
    std::vector<T> data;
        struct Node {
        T data;
        Node* next;
    };
    Node* head; // Pointeur vers le premier élément de la file
    Node* tail;
};

class TP {
public:
    file<Processus> fcfs(file<Processus> f_entree, int &temps);
    file<Processus> fjs(file<Processus> f_entree, int &temps);
    file<Processus> round_robin(file<Processus> f_entree, int quantum, int &temps);
    file<Processus> priorite(file<Processus> f_entree, int &temps);
    file<Processus> multiniveaux(file<Processus> f_entree, int quantum, int &temps);
};


#endif /* ORDONNANCEUR_H */
