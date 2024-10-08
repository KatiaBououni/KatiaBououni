/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
//#include"Test"
#include "ordonnanceur.h"
#include "Processus.h"

using namespace std;

// Fonction pour charger le fichier de scénario
std::queue<Processus> charger_fichier_scenario(const std::string& nom_fichier) {
    std::queue<Processus> file_de_processus; // File de processus
    std::ifstream fichier("scenarios/" + nom_fichier);

    if (!fichier.is_open()) {
        throw std::runtime_error("Erreur lors de l'ouverture du fichier " + nom_fichier);
    }

    std::string ligne;
    while (std::getline(fichier, ligne)) {
        std::istringstream iss(ligne);
        std::string pid;
        int arrivee, duree, priorite, type_num, attente = 0;
        TypeProcessus type;

        // Lecture des champs, s'assurer que chaque champ est bien extrait
        iss >> pid >> arrivee >> duree >> attente >> priorite >> type_num;

        // Créer le processus et l'ajouter à la file
        Processus processus(pid, arrivee, duree, duree, attente, 0, priorite, type);
        file_de_processus.push(processus);
    }

    fichier.close();

    // Afficher les processus chargés
    std::queue<Processus> temp_file = file_de_processus;
    while (!temp_file.empty()) {
        Processus p = temp_file.front();
        std::cout << p.reqProcessusFormate() << std::endl;
        temp_file.pop();
    }

    std::cout << "Fin du chargement\n";
    return file_de_processus;
}

// Affichage des résultats
void afficher_resultats(std::queue<Processus> resultats) {
    double temps_moyen = 0;
    double attente_totale = 0;
    int num_processus = resultats.size();

    while (!resultats.empty()) {
        Processus p = resultats.front();
        std::cout << p.reqProcessusFormate() << std::endl;
        attente_totale += p.req_attente();
        resultats.pop();
    }


// Programme principal
int test() {
std::queue<Processus> charger_fichier_scenario(const std::string& Test);
// Declaration des fonctions de simulation
void faire_simulation_fcfs(file<Processus>& mes_processus);
void faire_simulation_fjs(file<Processus>& mes_processus);
void faire_simulation_rr(file<Processus>& mes_processus);
void faire_simulation_multi(file<Processus>& mes_processus);
void faire_simulation_priorite(file<Processus>& mes_processus); 
}
