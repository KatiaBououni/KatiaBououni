/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Processus.h
 * Author: etudiant
 *
 * Created on 2 octobre 2024, 16 h 49
 */

#ifndef PROCESSUS_H
#define PROCESSUS_H
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <string>
//#include "ContratException.h"
/**
 * \class Borne
 * \brief Classe abstraite qui permet de gérer des Bornes
 */
enum class TypeProcessus {
    systeme,
    interactif,
    batch,
    student 
};
class Processus
{
public:
    Processus(std::string p_pid,int p_arrive, int p_duree, int p_restant, int p_attente, int p_fin, int p_priorite, TypeProcessus p_type);
    std::string req_pid() const;
    int req_arrive() const;
    int req_duree() const;
    int req_restant() const;
    int req_attente() const;
    int req_fin() const;
    int taille () ;
    int req_priorite() const;
    TypeProcessus req_type() const;
    std:: string reqProcessusFormate ();
    void asgnRestant(int p_restant);
    void asgnFin(int p_fin);
    void asgattente(int p_attente);
    bool operator<(const Processus &autre) const;
    void executer(int& temps_execution);
private:
std::string m_pid;
        int m_arrive;
        int m_duree;
        int m_restant; 
        int m_attente;
        int m_fin;
        int m_priorite;
        TypeProcessus m_type;
};

#endif /* PROCESSUS_H */

