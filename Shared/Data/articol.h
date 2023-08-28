#ifndef ARTICOL_H
#define ARTICOL_H

#include <string>
#include <vector>
#include "comentariu.h"

class Articol {
private:
    std::string titlu;
    std::string autor;
    std::string continut;
    std::string data;
    int like;
    int dislike;
    int love;
    std::vector<Comentariu> comentarii;

public:
    Articol(const std::string& titlu, const std::string& autor, const std::string& continut,
            const std::string& data, int like, int dislike, int love);

    std::string getTitlu() const;
    std::string getAutor() const;
    std::string getContinut() const;
    std::string getData() const;
    int getLike() const;
    int getDislike() const;
    int getLove() const;
    int getNumarComentarii() const;

    const std::vector<Comentariu>& getComentarii() const; 

    void incrementeazaLike();
    void incrementeazaDislike();
    void incrementeazaLove();

    void adaugaComentariu(const Comentariu& comentariu);
    void setContinut(const std::string& newContinut);
    void stergeArticol(const std::string& articol, std::vector<Articol>& articole);
    void stergeComentariu(int index);
    
};

#endif  // ARTICOL_H
