#include "articol.h"
#include <algorithm>
#include <fstream>
#include <iostream>


Articol::Articol(const std::string& titlu, const std::string& autor, const std::string& continut,
                 const std::string& data, int like, int dislike, int love)
    : titlu(titlu), autor(autor), continut(continut), data(data), like(like), dislike(dislike), love(love) {
}

std::string Articol::getTitlu() const {
    return titlu;
}

std::string Articol::getAutor() const {
    return autor;
}

std::string Articol::getContinut() const {
    return continut;
}

std::string Articol::getData() const {
    return data;
}

int Articol::getLike() const {
    return like;
}

int Articol::getDislike() const {
    return dislike;
}

int Articol::getLove() const {
    return love;
}

int Articol::getNumarComentarii() const {
    return comentarii.size();
}

void Articol::adaugaComentariu(const Comentariu& comentariu) {
    comentarii.push_back(comentariu);
}

const std::vector<Comentariu>& Articol::getComentarii() const {
    return comentarii;
}

void Articol::incrementeazaLike() {
    like++;
}

void Articol::incrementeazaDislike() {
    dislike++;
}

void Articol::incrementeazaLove() {
    love++;
}

void Articol::setContinut(const std::string& newContinut) {
    continut = newContinut;
}

void Articol::stergeArticol(const std::string& articol, std::vector<Articol>& articole) {
    auto it = std::find_if(articole.begin(), articole.end(), [&](const Articol& a) {
        return a.getTitlu() == articol;
    });

    if (it != articole.end()) {
        articole.erase(it);
        std::cout << "Articolul \"" << articol << "\" a fost sters cu succes!" << std::endl;

        // Actualizare fisier
        std::ofstream file("articole.txt");
        if (file.is_open()) {
            for (const auto& art : articole) {
                file << "Titlu: " << art.getTitlu() << std::endl;
                file << "Autor: " << art.getAutor() << std::endl;
                file << "Continut: " << art.getContinut() << std::endl;
                file << "Data: " << art.getData() << std::endl;
                file << "Like-uri: " << art.getLike() << std::endl;
                file << "Dislike-uri: " << art.getDislike() << std::endl;
                file << "Reactii de iubire: " << art.getLove() << std::endl;
                file << std::endl;
            }
            file.close();
        } else {
            std::cerr << "Eroare la deschiderea fisierului." << std::endl;
        }
    } else {
        std::cout << "Articolul \"" << articol << "\" nu a fost gasit." << std::endl;
    }
}

void Articol::stergeComentariu(int index) {
    if (index >= 0 && index < comentarii.size()) {
        comentarii.erase(comentarii.begin() + index);
    }
}
