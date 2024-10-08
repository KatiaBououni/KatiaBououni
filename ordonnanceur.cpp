/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include <iomanip>
#include <vector>
#include <queue>
#include <vector>
#include <stdexcept>
#include "ordonnanceur.h"
#include"Processus.h"
#include <algorithm>  
using namespace std;
file<Processus> TP::fcfs(file<Processus> f_entree, int& temps) {
    std::vector<Processus> liste_processus;
    while (!f_entree.estvide()) {
        liste_processus.push_back(f_entree.defiler());
    }
    std::sort(liste_processus.begin(), liste_processus.end(), [](const Processus& p1, const Processus& p2) {
        return p1.req_arrive() < p2.req_arrive();
    });
    file<Processus> f_resultat;  
    int temps_execution = temps; // Suivi du temps d'exécution
    for (auto& p : liste_processus) {
        // Si le temps d'exécution est inférieur à l'arrivée, avancez le temps
        if (temps_execution < p.req_arrive()) {
            temps_execution = p.req_arrive();
        }
        int temps_attente = temps_execution - p.req_arrive();
        p.asgattente(temps_attente);
        temps_execution += p.req_duree();  
        f_resultat.enfiler(p);
    }
    std::cout << "simulation de FCFS Resultat:\n";
    while (!f_resultat.estvide()) {
        Processus p = f_resultat.defiler();
        std::cout << p.reqProcessusFormate();
    }
    double temps_attente_moyen = 0;
    for (const auto& p : liste_processus) {
        temps_attente_moyen += p.req_attente();
    }
    temps_attente_moyen /= liste_processus.size();
    std::cout << "Temps d'attente moyen : " << temps_attente_moyen << std::endl;

    return f_resultat;
}
file<Processus> TP::fjs(file<Processus> f_entree, int& temps) {
    std::vector<Processus> liste_processus;

    while (!f_entree.estvide()) {
        liste_processus.push_back(f_entree.defiler());
    }

    std::sort(liste_processus.begin(), liste_processus.end(), [](const Processus& a, const Processus& b) {
        return a.req_duree() < b.req_duree();
    });

    file<Processus> result;
    int total_attente = 0;

    for (auto& p : liste_processus) {
        // Calcul du temps d'attente
        int temps_attente = std::max(0, temps - p.req_arrive());
        p.asgattente(temps_attente);
        total_attente += temps_attente;
        
        temps += p.req_duree();
        result.enfiler(p);
    }

    // Afficher le résultat
    std::cout << "Simulation de FJS Resultat:" << std::endl;
    for (const auto& p : result) {
        Processus processus_temp = p; // Créez une copie non constante
        std::cout << processus_temp.reqProcessusFormate();
    }
    
    // Calculer le temps d'attente moyen
    double temps_moyen = static_cast<double>(total_attente) / liste_processus.size();
    std::cout << "Temps d'attente moyen : " << temps_moyen << std::endl;

    return result;
}



 file<Processus> TP::round_robin(file<Processus> f_entree, int quantum, int& temps) {
    vector<Processus> liste_processus;  // Liste des processus initialement disponibles
    file<Processus> file_pret_inf;       // File des processus prêts avec durée <= quantum
    file<Processus> file_pret_sup;       // File des processus prêts avec durée > quantum
    int total_attente = 0;
    int nb_processus = 0;
    bool premier_processus = true; // Drapeau pour vérifier si c'est le premier processus
    while (!f_entree.estvide()) {
        liste_processus.push_back(f_entree.defiler());
        nb_processus++;  // Compter le nombre de processus
    }
    sort(liste_processus.begin(), liste_processus.end(), [](const Processus& p1, const Processus& p2) {
        return p1.req_arrive() < p2.req_arrive();
    });
    int currentTime = temps;
    cout << "Simulation de Round Robin Resultat:\n";
    // Boucle jusqu'à ce que tous les processus soient traités
    while (!file_pret_inf.estvide() || !file_pret_sup.estvide() || !liste_processus.empty()) {
        // Ajouter les processus qui sont arrivés
        while (!liste_processus.empty() && liste_processus.front().req_arrive() <= currentTime) {
            Processus p = liste_processus.front();
            liste_processus.erase(liste_processus.begin());

            // Classifier les processus en fonction de leur durée
            if (p.req_duree() <= quantum) {
                file_pret_inf.enfiler(p);
            } else {
                file_pret_sup.enfiler(p);
            }
        }
        if (!file_pret_inf.estvide()) {
            Processus p = file_pret_inf.defiler();
            int temps_exec = p.req_restant();  // Exécution de la totalité de la durée restante
            currentTime += temps_exec;  // Avancer le temps
            p.asgnRestant(0);  // Processus terminé
            int temps_attente;
            if (premier_processus) {
                temps_attente = quantum;  // Temps d'attente du premier processus
                premier_processus = false; // Passer au prochain processus
            } else {
                temps_attente = currentTime - p.req_arrive() - p.req_duree();
                if (temps_attente < 0) temps_attente = 0; // S'assurer que le temps d'attente ne soit pas négatif
            }
            p.asgattente(temps_attente);
            total_attente += p.req_attente();
            cout << p.reqProcessusFormate ();
           } else if (!file_pret_sup.estvide()) {
            // Exécuter les processus de la file supérieure si la file inférieure est vide
            Processus p = file_pret_sup.defiler();
            int temps_exec = min(p.req_restant(), quantum);
            currentTime += temps_exec;  // Avancer le temps
            p.asgnRestant(p.req_restant() - temps_exec);  // Décrémenter la durée restante
            int temps_attente;
            if (premier_processus) {
                temps_attente = quantum;  // Temps d'attente du premier processus
                premier_processus = false; // Passer au prochain processus
            } else {
                temps_attente = currentTime - p.req_arrive() - p.req_duree();
                if (temps_attente < 0) temps_attente = 0; // S'assurer que le temps d'attente ne soit pas négatif
            }
            p.asgattente(temps_attente);
            total_attente += p.req_attente();
            if (p.req_restant() == 0) {
                cout << p.reqProcessusFormate ();
            } else {
                file_pret_sup.enfiler(p);
            }
        }
        // Si aucune file n'est prête, avancer le temps au prochain processus
        if (file_pret_inf.estvide() && file_pret_sup.estvide() && !liste_processus.empty()) {
            currentTime = liste_processus.front().req_arrive();
        }
    }
    // Calcul et affichage du temps d'attente moyen
    double temps_attente_moyen = static_cast<double>(total_attente) / nb_processus;
    cout << "Temps d'attente moyen : " << temps_attente_moyen << endl;
    return file_pret_inf; // Ou file_pret_sup selon ce que vous voulez retourner*/  
}


file<Processus> TP::priorite(file<Processus> f_entree, int& temps) {
    file<Processus> file_pret;  // File des processus prêts à être exécutés
    file<Processus> result;      // File des processus exécutés
    int current_time = 0;

    // Trier les processus par leur temps d'arrivée initial pour les ajouter progressivement
    std::sort(f_entree.begin(), f_entree.end(), [](const Processus& a, const Processus& b) {
        return a.req_arrive() < b.req_arrive();
    });

    // Boucle principale : tant qu'il reste des processus à traiter
    while (!f_entree.estvide() || !file_pret.estvide()) {
        // Ajouter les nouveaux processus arrivés au temps actuel
        while (!f_entree.estvide() && f_entree.front().req_arrive() <= current_time) {
            file_pret.enfiler(f_entree.defiler());
        }

        // Si des processus sont prêts, choisir celui avec la priorité la plus élevée
        if (!file_pret.estvide()) {
            // Trouver le processus avec la priorité la plus élevée
            auto it = std::max_element(file_pret.begin(), file_pret.end(), [](const Processus& a, const Processus& b) {
                return a.req_priorite() < b.req_priorite(); // Priorité plus haute = valeur numérique plus élevée
            });

            Processus current = *it;
            file_pret.retirer(current);  // Retirer le processus choisi de la file

            // Exécuter le processus en entier
            current_time += current.req_duree();
            current.asgnFin(current_time);  // Temps de fin du processus
            current.asgattente(current_time - current.req_arrive() );  // Calculer temps d'attente

            result.enfiler(current);  // Ajouter le processus terminé à la file de résultat
            
        } else {
            // S'il n'y a pas de processus prêt, avancer le temps jusqu'au prochain processus
            if (!f_entree.estvide()) {
                current_time = f_entree.front().req_arrive();
            }
        }
    }
        // Afficher le résultat
    std::cout << "Simulation de FJS Resultat:" << std::endl;
    for (const auto& p : result) {
        Processus processus_temp = p; // Créez une copie non constante
        std::cout << processus_temp.reqProcessusFormate();
    }
    temps = current_time;  // Mise à jour du temps total écoulé
    return result;  // Retourne la file des processus exécutés
} 
file<Processus> TP::multiniveaux(file<Processus> f_entree, int quantum, int& temps) {
    file<Processus> systeme, interactif, batch, utilisateur;

    // Distribution des processus dans les différentes catégories
    while (!f_entree.estvide()) {
        Processus p = f_entree.defiler();  
        switch (p.req_type()) {
            case TypeProcessus::systeme:
                systeme.enfiler(p);
                break;
            case TypeProcessus::interactif:
                interactif.enfiler(p);
                break;
            case TypeProcessus::batch:
                batch.enfiler(p);
                break;
            case TypeProcessus::student:
                utilisateur.enfiler(p);
                break;
        }
    }

    // Ordonnancer les processus système selon leur priorité
    systeme.trier([](const Processus& a, const Processus& b) {
        return a.req_priorite() > b.req_priorite();
    });

    file<Processus> result;

    // Traitement des processus système
    while (!systeme.estvide()) {
        Processus p = systeme.defiler();
        p.asgattente(temps);  // Comme tous sont arrivés à temps = 0
        temps += p.req_duree();
        result.enfiler(p);
    }

    // Traitement des processus interactifs avec Round Robin
    while (!interactif.estvide()) {
        file<Processus> file_interactif;
        Processus p = interactif.defiler();
        file_interactif.enfiler(p);
        file<Processus> rr_result = round_robin(file_interactif, quantum, temps);
        while (!rr_result.estvide()) {
            result.enfiler(rr_result.defiler());
        }
    }

    // Traitement des processus batch selon FCFS
    while (!batch.estvide()) {
        Processus p = batch.defiler();
        p.asgattente(temps);  // Comme tous sont arrivés à temps = 0
        temps += p.req_duree();
        result.enfiler(p);
    }

    // Traitement des processus utilisateur selon FCFS
    while (!utilisateur.estvide()) {
        Processus p = utilisateur.defiler();
        p.asgattente(temps);  // Comme tous sont arrivés à temps = 0
        temps += p.req_duree();
        result.enfiler(p);
    }

    return result;  // Retourne la file des processus traités
}
