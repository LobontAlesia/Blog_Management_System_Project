#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "C:\Users\Alesia\Desktop\Final_exe\teste\Shared\Data\comentariu.h"
#include "C:\Users\Alesia\Desktop\Final_exe\teste\Shared\Data\articol.h"

bool existaArt(const std::string &articol, const std::vector<Articol> &articole)
{
    for (const Articol &art : articole)
    {
        if (art.getTitlu() == articol)
        {
            return true;
        }
    }
    return false;
}
bool existaArticol(const std::string &articol, const std::vector<Comentariu> &comentarii)
{
    for (const Comentariu &c : comentarii)
    {
        if (c.getArticol() == articol)
        {
            return true;
        }
    }
    return false;
}

void adauga_comentariu(const std::string &articol, const std::string &text, const std::string &autor, const std::string &data, std::vector<Comentariu> &comentarii, const std::vector<Articol> &articole)
{
    if (!existaArt(articol, articole))
    {
        std::cerr << "Articolul '" << articol << "' nu exista." << std::endl;
        return;
    }

    Comentariu comentariu(text, autor, data, 0, 0, 0);
    comentariu.setArticol(articol);
    comentarii.push_back(comentariu);

    // Salvare în fișier
    std::ofstream file("C:\\Users\\Alesia\\Desktop\\Final_exe\\teste\\Shared\\Files\\comentariu.txt", std::ios::app);
    if (file.is_open())
    {
        file << "Articol: " << articol << std::endl;
        file << "Text: " << text << std::endl;
        file << "Autor: " << autor << std::endl;
        file << "Data: " << data << std::endl;
        file << "Like-uri: " << comentariu.getLike() << std::endl;
        file << "Dislike-uri: " << comentariu.getDislike() << std::endl;
        file << "Reactii de iubire: " << comentariu.getLove() << std::endl;
        file << std::endl;
        file.close();
        std::cout << "Comentariul a fost adăugat cu succes!" << std::endl;
    }
    else
    {
        std::cerr << "Eroare la deschiderea fișierului." << std::endl;
    }
}
void afisare_comentarii_articol(const std::string &articol_titlu, const std::vector<Comentariu> &comentarii)
{
    std::cout << "Comentariile pentru articolul \"" << articol_titlu << "\":" << std::endl;
    bool exista_comentarii = false;

    // Caută comentariile asociate articolului
    for (const auto &comentariu : comentarii)
    {
        if (comentariu.getArticol() == articol_titlu)
        {
            std::cout << "Articol: " << comentariu.getArticol() << std::endl;
            std::cout << "Text: " << comentariu.getText() << std::endl;
            std::cout << "Autor: " << comentariu.getAutor() << std::endl;
            std::cout << "Data: " << comentariu.getData() << std::endl;
            std::cout << "Like-uri: " << comentariu.getLike() << std::endl;
            std::cout << "Dislike-uri: " << comentariu.getDislike() << std::endl;
            std::cout << "Reactii de iubire: " << comentariu.getLove() << std::endl;
            std::cout << std::endl;
            exista_comentarii = true;
        }
    }

    if (!exista_comentarii)
    {
        std::cout << "Nu exista articolul sau nu exista comentarii pentru articolul \"" << articol_titlu << "\"." << std::endl;
    }
}

void adauga_reactie_comentariu(const std::string &articol, int index_comentariu, const std::string &reactie, std::vector<Comentariu> &comentarii)
{
    if (!existaArticol(articol, comentarii))
    {
        std::cerr << "Articolul '" << articol << "' nu exista." << std::endl;
        return;
    }

    if (index_comentariu >= 0 && index_comentariu < comentarii.size())
    {
        Comentariu &comentariu = comentarii[index_comentariu];
        if (reactie == "like")
        {
            comentariu.incrementeazaLike();
        }
        else if (reactie == "dislike")
        {
            comentariu.incrementeazaDislike();
        }
        else if (reactie == "love")
        {
            comentariu.incrementeazaLove();
        }
        else
        {
            std::cerr << "Reactie invalida." << std::endl;
            return;
        }

        // Actualizare în fișier
        std::ofstream file("C:\\Users\\Alesia\\Desktop\\Final_exe\\teste\\Shared\\Files\\comentariu.txt", std::ios::out | std::ios::trunc);
        if (file.is_open())
        {
            for (const Comentariu &c : comentarii)
            {
                file << "Articol: " << c.getArticol() << std::endl;
                file << "Text: " << c.getText() << std::endl;
                file << "Autor: " << c.getAutor() << std::endl;
                file << "Data: " << c.getData() << std::endl;
                file << "Like-uri: " << c.getLike() << std::endl;
                file << "Dislike-uri: " << c.getDislike() << std::endl;
                file << "Reactii de iubire: " << c.getLove() << std::endl;
                file << std::endl;
            }
            file.close();
            std::cout << "Reactia a fost adaugata cu succes!" << std::endl;
        }
        else
        {
            std::cerr << "Eroare la deschiderea fisierului." << std::endl;
        }
    }
    else
    {
        std::cerr << "Indexul comentariului este invalid." << std::endl;
    }
}
void adauga_reactie_articol(const std::string &titlu_articol, const std::string &reactie, std::vector<Articol> &articole)
{
    for (auto &articol : articole)
    {
        if (articol.getTitlu() == titlu_articol)
        {
            if (reactie == "like")
            {
                articol.incrementeazaLike();
                std::cout << "Reactia de like a fost adaugata cu succes la articolul \"" << titlu_articol << "\"." << std::endl;
            }
            else if (reactie == "dislike")
            {
                articol.incrementeazaDislike();
                std::cout << "Reactia de dislike a fost adaugata cu succes la articolul \"" << titlu_articol << "\"." << std::endl;
            }
            else if (reactie == "love")
            {
                articol.incrementeazaLove();
                std::cout << "Reactia de love a fost adaugata cu succes la articolul \"" << titlu_articol << "\"." << std::endl;
            }
            else
            {
                std::cerr << "Reactia specificata nu este valida. Reactiile valide sunt: like, dislike, love." << std::endl;
                return;
            }

            // Salvare în fișier
            std::ofstream file("C:\\Users\\Alesia\\Desktop\\Final_exe\\teste\\Shared\\Files\\articole.txt");
            if (file.is_open())
            {
                for (const auto &articol : articole)
                {
                    file << "Titlu: " << articol.getTitlu() << std::endl;
                    file << "Autor: " << articol.getAutor() << std::endl;
                    file << "Continut: " << articol.getContinut() << std::endl;
                    file << "Data: " << articol.getData() << std::endl;
                    file << "Like-uri: " << articol.getLike() << std::endl;
                    file << "Dislike-uri: " << articol.getDislike() << std::endl;
                    file << "Reactii de iubire: " << articol.getLove() << std::endl;
                    file << std::endl;
                }
                file.close();
            }
            else
            {
                std::cerr << "Eroare la deschiderea fisierului." << std::endl;
            }

            return;
        }
    }

    std::cerr << "Articolul cu titlul \"" << titlu_articol << "\" nu a fost gasit." << std::endl;
}

void sterge_comentariu(const std::string& articol_titlu, int index, std::vector<Comentariu>& comentarii)
{
    // Verificăm dacă indexul este valid
    if (index >= 0 && index < comentarii.size())
    {
        // Verificăm dacă comentariul aparține articolului dat
        if (comentarii[index].getArticol() == articol_titlu)
        {
            // Ștergem comentariul din vector
            comentarii.erase(comentarii.begin() + index);
            std::cout << "Comentariul a fost sters cu succes!" << std::endl;
        }
        else
        {
            std::cerr << "Comentariul nu apartine articolului specificat." << std::endl;
            return; // Ieșim din funcție dacă comentariul nu aparține articolului
        }
    }
    else
    {
        std::cerr << "Indexul comentariului este invalid." << std::endl;
        return; // Ieșim din funcție dacă indexul comentariului este invalid
    }

    // Salvăm comentariile în fișier
    std::ofstream file("C:\\Users\\Alesia\\Desktop\\Final_exe\\teste\\Shared\\Files\\comentariu.txt");
    if (file.is_open())
    {
        for (const auto& comentariu : comentarii)
        {
            file << "Articol: " << comentariu.getArticol() << std::endl;
            file << "Text: " << comentariu.getText() << std::endl;
            file << "Autor: " << comentariu.getAutor() << std::endl;
            file << "Data: " << comentariu.getData() << std::endl;
            file << "Like-uri: " << comentariu.getLike() << std::endl;
            file << "Dislike-uri: " << comentariu.getDislike() << std::endl;
            file << "Reactii de iubire: " << comentariu.getLove() << std::endl;
            file << std::endl;
        }
        file.close();
    }
    else
    {
        std::cerr << "Eroare la deschiderea fisierului comentariu.txt." << std::endl;
    }
}


int main(int argc, char *argv[])
{
    std::vector<Comentariu> comentarii;
    std::vector<Articol> articole;

    // Read existing articles from file
    std::ifstream f("C:\\Users\\Alesia\\Desktop\\Final_exe\\teste\\Shared\\Files\\articole.txt");
    if (f.is_open())
    {
        std::string line;
        std::string titlu, autor, continut, data;
        int like = 0, dislike = 0, love = 0;
        while (std::getline(f, line))
        {
            if (line.find("Titlu: ") != std::string::npos)
            {
                titlu = line.substr(7);
                std::getline(f, line); // Read the next line (Autor)
                autor = line.substr(7);
                std::getline(f, line); // Read the next line (Continut)
                continut = line.substr(9);
                std::getline(f, line); // Read the next line (Data)
                data = line.substr(6);
                std::getline(f, line); // Read the next line (Like-uri)
                if (line.find("Like-uri: ") != std::string::npos)
                    like = std::stoi(line.substr(10));
                std::getline(f, line); // Read the next line (Dislike-uri)
                if (line.find("Dislike-uri: ") != std::string::npos)
                    dislike = std::stoi(line.substr(13));
                std::getline(f, line); // Read the next line (Reactii de iubire)
                if (line.find("Reactii de iubire: ") != std::string::npos)
                    love = std::stoi(line.substr(19));

                Articol articol(titlu, autor, continut, data, like, dislike, love);
                articole.push_back(articol); // Add the article to the vector of articles
            }
        }
        f.close();
    }
    else
    {
        std::cout << "Error opening the file articole.txt." << std::endl;
        return 1;
    }

    // Read existing comments from file
    std::ifstream file("C:\\Users\\Alesia\\Desktop\\Final_exe\\teste\\Shared\\Files\\comentariu.txt");
    if (file.is_open())
    {
        std::string line;
        std::string articol, text, autor, data;
        int like, dislike, love;
        while (std::getline(file, line))
        {
            if (line.find("Articol: ") != std::string::npos)
            {
                articol = line.substr(9);
                std::getline(file, line); // Read the next line (Text)
                text = line.substr(6);
                std::getline(file, line); // Read the next line (Autor)
                autor = line.substr(7);
                std::getline(file, line); // Read the next line (Data)
                data = line.substr(6);
                std::getline(file, line); // Read the next line (Like-uri)
                if (line.find("Like-uri: ") != std::string::npos)
                    like = std::stoi(line.substr(10));
                std::getline(file, line); // Read the next line (Dislike-uri)
                if (line.find("Dislike-uri: ") != std::string::npos)
                    dislike = std::stoi(line.substr(13));
                std::getline(file, line); // Read the next line (Reactii de iubire)
                if (line.find("Reactii de iubire: ") != std::string::npos)
                    love = std::stoi(line.substr(19));

                Comentariu comentariu(text, autor, data, like, dislike, love);
                comentariu.setArticol(articol);
                comentarii.push_back(comentariu); // Add the comment to the vector of comments
            }
        }
        file.close();
    }
    else
    {
        std::cout << "Error opening the file comentariu.txt." << std::endl;
        return 1;
    }

    if (argc < 2)
    {
        std::cerr << "Comanda nu a fost specificata." << std::endl;
        return 1;
    }
    std::string command = argv[1];

    if (command == "adauga_comentariu")
    {
        if (argc < 6)
        {
            std::cerr << "Argumente insuficiente pentru adauga_comentariu." << std::endl;
            return 1;
        }

        std::string articol = argv[2];
        std::string text = argv[3];
        std::string autor = argv[4];
        std::string data = argv[5];

        // Apelul funcției adauga_comentariu
        adauga_comentariu(articol, text, autor, data, comentarii, articole);
    }
    else if (command == "afisare_comentarii_articol")
    {
        // Verifică dacă există suficiente argumente pentru această comandă
        if (argc >= 3)
        {
            std::string articol_titlu = argv[2];

            // Apelarea funcției afisare_comentarii_articol cu argumentele corespunzătoare
            afisare_comentarii_articol(articol_titlu, comentarii);
        }
        else
        {
            std::cout << "Argumente insuficiente. Utilizare: ./app2.exe afisare_comentarii_articol <titlu_articol>" << std::endl;
            return 1;
        }
    }
    else if (command == "adauga_reactie_comentariu")
    {
        if (argc < 5)
        {
            std::cerr << "Argumente insuficiente pentru adauga_reactie_comentariu." << std::endl;
            return 1;
        }

        std::string articol = argv[2];
        int index_comentariu = std::stoi(argv[3]);
        std::string reactie = argv[4];

        adauga_reactie_comentariu(articol, index_comentariu, reactie, comentarii);
    }
    else if (command == "adauga_reactie_articol")
    {
        if (argc < 4)
        {
            std::cerr << "Argumente insuficiente pentru adauga_reactie_articol." << std::endl;
            return 1;
        }

        std::string titlu_articol = argv[2];
        std::string reactie = argv[3];

        // Apelul funcției adauga_reactie_articol
        adauga_reactie_articol(titlu_articol, reactie, articole);
    }
    else if (command == "sterge_comentariu")
    {
        if (argc < 4)
        {
            std::cerr << "Argumente insuficiente pentru sterge_comentariu." << std::endl;
            return 1;
        }

        std::string titlu_articol = argv[2];
        int index = std::stoi(argv[3]);

        // Apelul funcției sterge_comentariu
        sterge_comentariu(titlu_articol, index, comentarii);
    }
    else if (command == "iesire")
        {
            std::cout << "Programul s-a incheiat. La revedere!" << std::endl;
            return 0;
        }
    else
    {
        std::cerr << "Comanda invalida." << std::endl;
        return 1;
    }

    return 0;
}