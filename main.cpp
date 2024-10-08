/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 2 octobre 2024, 16 h 49
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include "ordonnanceur.h"
#include "Processus.h"

using namespace std;

// Programme principal
int main() {    // Création d'un processus
    /*Processus p1("P1", 0, 10, 10, 0, 0, 1, TypeProcessus::systeme);
    
    // Test des accesseurs
    assert(p1.req_pid() == "P1");
    assert(p1.req_arrive() == 0);
    assert(p1.req_duree() == 10);
    assert(p1.req_restant() == 10);
    assert(p1.req_attente() == 0);
    assert(p1.req_fin() == 0);
    assert(p1.req_priorite() == 1);
    assert(p1.req_type() == TypeProcessus::systeme);
    
    // Test de l'opérateur <
    Processus p2("P2", 1, 5, 5, 0, 0, 2, TypeProcessus::batch);
    assert(p1 < p2);
 
    // Modifier des attributs
    p1.asgnRestant(8);
    p1.asgattente(2);
    p1.asgnFin(10);

    // Vérifier les modifications
    assert(p1.req_restant() == 8);
    assert(p1.req_attente() == 2);
    assert(p1.req_fin() == 10);
    
    // Affichage formaté
    std::cout << p1.reqProcessusFormate();
    std::cout << p2.reqProcessusFormate();

    std::cout << "Tous les tests ont réussi." << std::endl;
    return 0;

///////////////////
 ///test algo 1

    // Créer une file d'entrée de processus*/
  /* file<Processus> f_entree;

    // Ajouter des processus à la file d'entrée
    f_entree.enfiler(Processus("P1", 0, 24, 24, 0, 0, 1, TypeProcessus::student));
    f_entree.enfiler(Processus("P2", 0, 3, 3, 0, 0, 1, TypeProcessus::student));
    f_entree.enfiler(Processus("P3", 0, 3, 3, 0, 0, 1, TypeProcessus::student));
    f_entree.enfiler(Processus("P4", 30, 2, 2, 0, 0, 1, TypeProcessus::student));

    int temps = 0;

    TP tp; // Créer une instance de la classe TP
    file<Processus> f_resultat = tp.fcfs(f_entree, temps);

    // Afficher les résultats
    while (!f_resultat.estvide()) {
        Processus p = f_resultat.defiler();
    }*/
  ///////////////////////////////////////////////////
  ///////TESTalgo2
   /*file<Processus> f_entree;

    // Ajouter des processus à la file
    f_entree.enfiler(Processus("P1", 0, 24, 24, 0, 0, 1, TypeProcessus::systeme));
    f_entree.enfiler(Processus("P2", 0, 3, 3, 0, 0, 1, TypeProcessus::interactif));
    f_entree.enfiler(Processus("P3", 0, 3, 3, 0, 0, 1, TypeProcessus::batch));
    f_entree.enfiler(Processus("P4", 30, 2, 2, 0, 0, 1, TypeProcessus::student));
    int temps =0;
    TP tp_instance;
    file<Processus> f_resultat = tp_instance.fjs (f_entree, temps);
    return 0;
    */
    // Add processes to the entry file (assuming the constructor initializes the fields)
    // Example: Processus(name, arrival_time, duration, waiting_time, priority, type)
   
   ////////////////////////////////////////////////
    // Test Algo3
    /*file<Processus> f_entree;

    // Ajouter des processus à la file
    f_entree.enfiler(Processus("P1", 0, 24, 24, 0, 0, 1, TypeProcessus::systeme));
    f_entree.enfiler(Processus("P2", 0, 3, 3, 0, 0, 1, TypeProcessus::interactif));
    f_entree.enfiler(Processus("P3", 0, 3, 3, 0, 0, 1, TypeProcessus::batch));
    f_entree.enfiler(Processus("P4", 30, 2, 2, 0, 0, 1, TypeProcessus::student));

    int quantum = 4; // Définir un quantum pour l'algorithme
    int temps_initial = 0;

    // Créer une instance de TP
    TP tp_instance;

    // Appeler la fonction Round Robin 
    file<Processus> f_resultat = tp_instance.round_robin(f_entree, quantum, temps_initial);
    return 0;*/
   ///////////////////////
      ////test Algo 4 probleme temps d'attente 
/*    file<Processus> f_entree;

    f_entree.enfiler(Processus("P1", 0, 5, 5, 0, 0, 1, TypeProcessus::systeme));
    f_entree.enfiler(Processus("P2", 1, 3, 3, 0, 0, 2, TypeProcessus::interactif));
    f_entree.enfiler(Processus("P3", 2, 8, 8, 0, 0, 1, TypeProcessus::batch));
    f_entree.enfiler(Processus("P4", 3, 6, 6, 0, 0, 3, TypeProcessus::student));

    // Initialiser l'ordonnanceur
    TP tp;
    int temps_ecoule = 0;

    // Appeler la méthode priorite
    file<Processus> resultats = tp.priorite(f_entree, temps_ecoule);

    // Afficher les résultats
    std::cout << "Temps total écoulé : " << temps_ecoule << " unités de temps.\n";

    return 0;
 */
//////////////////////////////////////////////////
  //Test ALGO5
  
    /*int temps = 0;
    file<Processus> file_processus;

    // Ajout de quelques processus à la file
    file_processus.enfiler(Processus("p1", 0, 5, 5, 0, 0, 2, TypeProcessus::systeme));
    file_processus.enfiler(Processus("p2", 1, 3, 3, 0, 0, 4, TypeProcessus::interactif));
    file_processus.enfiler(Processus("p3", 2, 1, 1, 0, 0, 1, TypeProcessus::batch));
    file_processus.enfiler(Processus("p4", 3, 2, 2, 0, 0, 3, TypeProcessus::student));
    file_processus.enfiler(Processus("p5", 4, 4, 4, 0, 0, 2, TypeProcessus::interactif));

    TP ordonnanceur;
    file<Processus> result = ordonnanceur.multiniveaux(file_processus, 2, temps);

     std::cout << "Résultat de la simulation:" << std::endl;
     while (!result.estvide()) {
    Processus p = result.defiler();
    std::cout << p.reqProcessusFormate() << std::endl;
}

    return 0;*/

}
