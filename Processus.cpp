/*
 * Click nbfs:///SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <string>
#include <sstream>
#include <string>
#include "Processus.h"
using namespace std;
Processus:: Processus (std::string p_pid,int p_arrive, int p_duree, int p_restant, int p_attente, int p_fin, int p_priorite, TypeProcessus p_type):
m_pid(p_pid),m_arrive(p_arrive),m_duree(p_duree),m_restant(p_restant),m_attente(0),m_fin(0),m_priorite(p_priorite),m_type(p_type){
/*PRECONDITION
PRECONDITION
PRECONDITION
POSTCONDITION(m_pid == p_pid);
POSTCONDITION(m_arrive == p_arrive);
POSTCONDITION(m_duree == p_duree);
POSTCONDITION(m_restant == p_restant);
POSTCONDITION(m_priorite == p_priorite);
INVARIANTS();
*/}

std::string Processus::req_pid() const {
    return m_pid;
}
int Processus::req_arrive() const {
    return m_arrive;
}
int Processus::req_duree() const {
    return m_duree;
}
int Processus::req_restant() const {
    return m_restant;
}
int Processus::req_attente() const {
    return( m_attente) ;
}
int Processus::req_fin() const {
    return m_fin;
}
int Processus::req_priorite() const {
    return m_priorite;
}
TypeProcessus Processus::req_type() const {
    return m_type;
}
bool Processus::operator < (const Processus& autre) const{
        return m_priorite < autre.m_priorite;
}
void Processus::asgnRestant(int p_restant) {
  m_restant = p_restant;
  /*POSTCONDITION(m_restant == p_restant);
  INVARIANTS();*/
}
void Processus::asgattente(int p_attente) {
    m_attente = p_attente; // Update the waiting time attribute
}
void Processus::asgnFin(int p_fin) {
  m_fin = p_fin;
  /*POSTCONDITION(m_fin == p_fin);
  INVARIANTS();*/
}
void Processus::executer(int& temps_execution) {
    // Si le processus n'est pas encore arrivé, avancer le temps d'exécution à son temps d'arrivée
    if (m_arrive > temps_execution) {
        temps_execution = m_arrive;  // Avancer le temps d'exécution
    }

    // Ici, vous pouvez ajouter d'autres logiques si nécessaire, par exemple :
    // Exécution du processus pendant sa durée
    temps_execution += m_duree;  // Ajouter la durée d'exécution du processus
    // Mettre à jour l'état du processus si nécessaire
    asgnFin(temps_execution);  // Mettre à jour le temps de fin
}

std::string Processus::reqProcessusFormate() {
 std::ostringstream os;
 os <<  req_pid()<< " Arrivée : " << req_arrive() << " Duree : " << req_duree()  << " Temps d'attente : " << req_attente() << " Priorité: " << req_priorite() << " Type : " << static_cast<int>(req_type()) <<std::endl; // si tu utilises enum
 return os.str();
}

/*void Borne::verifieInvariant(void) const
{
	INVARIANT(m_identifiant > 0);
}*/
