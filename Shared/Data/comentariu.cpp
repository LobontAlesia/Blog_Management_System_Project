// comentariu.cpp
#include "comentariu.h"
#include <fstream>

Comentariu::Comentariu(const std::string& text, const std::string& autor, const std::string& data, int like, int dislike, int love)
    : text(text), autor(autor), data(data), like(like), dislike(dislike), love(love) {}

std::string Comentariu::getArticol() const {
    return articol;
}

std::string Comentariu::getText() const {
    return text;
}

std::string Comentariu::getAutor() const {
    return autor;
}

std::string Comentariu::getData() const {
    return data;
}

int Comentariu::getLike() const {
    return like;
}

int Comentariu::getDislike() const {
    return dislike;
}

int Comentariu::getLove() const {
    return love;
}

const std::vector<std::string>& Comentariu::getReactii() const {
    return reactii;
}

void Comentariu::setArticol(const std::string& articol) {
    this->articol = articol;
}

void Comentariu::incrementeazaLike() {
    like++;
}

void Comentariu::incrementeazaDislike() {
    dislike++;
}

void Comentariu::incrementeazaLove() {
    love++;
}

void Comentariu::adaugaReactie(const std::string& reactie) {
    reactii.push_back(reactie);
}
