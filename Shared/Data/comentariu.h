// comentariu.h
#ifndef COMENTARIU_H
#define COMENTARIU_H

#include <string>
#include <vector>

class Comentariu {
private:
    std::string articol;
    std::string text;
    std::string autor;
    std::string data;
    int like;
    int dislike;
    int love;
    std::vector<std::string> reactii;

public:
    Comentariu(const std::string& text, const std::string& autor,const std::string& data, int like = 0, int dislike = 0, int love = 0);

    std::string getText() const;
    std::string getAutor() const;
    std::string getArticol() const;
    std::string getData() const;
    int getLike() const;
    int getDislike() const;
    int getLove() const;
    const std::vector<std::string>& getReactii() const;

    void setArticol(const std::string& articol);
    void incrementeazaLike();
    void incrementeazaDislike();
    void incrementeazaLove();
    void adaugaReactie(const std::string& reactie);

};

#endif
