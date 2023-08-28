#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "C:\Users\Alesia\Desktop\Final_exe\teste\Shared\Data\articol.h"
#include "C:\Users\Alesia\Desktop\Final_exe\teste\Shared\Data\comentariu.h"

void adaugaArticol(std::vector<Articol> &articole, const std::vector<std::string> &args)
{
    if (args.size() < 5)
    {
        std::cout << "Parametri insuficienti pentru comanda 'adauga_articol'." << std::endl;
        return;
    }

    std::string titlu = args[1];
    std::string autor = args[2];
    std::string continut = args[3];
    std::string data = args[4];
    int like = 0, dislike = 0, love = 0;

    Articol articol(titlu, autor, continut, data, like, dislike, love);
    articole.push_back(articol);

    // Salvare in fisier
    std::ofstream file("C:\\Users\\Alesia\\Desktop\\Final_exe\\teste\\Shared\\Files\\articole.txt", std::ios::app);
    if (file.is_open())
    {
        file << "Titlu: " << titlu << std::endl;
        file << "Autor: " << autor << std::endl;
        file << "Continut: " << continut << std::endl;
        file << "Data: " << data << std::endl;
        file << "Like-uri: " << like << std::endl;
        file << "Dislike-uri: " << dislike << std::endl;
        file << "Reactii de iubire: " << love << std::endl;
        file << std::endl;
        file.close();
        std::cout << "Articolul a fost adaugat cu succes!" << std::endl;
    }
    else
    {
        std::cerr << "Eroare la deschiderea fisierului." << std::endl;
    }
}

void afiseazaArticol(const std::vector<Articol> &articole, const std::vector<Comentariu> &comentarii, const std::vector<std::string> &args)
{
    if (args.size() < 2)
    {
        std::cout << "Parametri insuficienti pentru comanda 'afiseaza_articol'." << std::endl;
        return;
    }

    std::string titlu = args[1];
    bool found = false;
    for (const auto &art : articole)
    {
        if (art.getTitlu() == titlu)
        {
            std::cout << "Titlu: " << art.getTitlu() << std::endl;
            std::cout << "Autor: " << art.getAutor() << std::endl;
            std::cout << "Continut: " << art.getContinut() << std::endl;
            std::cout << "Data: " << art.getData() << std::endl;
            std::cout << "Like-uri: " << art.getLike() << std::endl;
            std::cout << "Dislike-uri: " << art.getDislike() << std::endl;
            std::cout << "Reactii de iubire: " << art.getLove() << std::endl;
            std::cout << "---------------------------" << std::endl;
            std::cout << "Comentarii:" << std::endl;
            std::cout << "---------------------------" << std::endl;

            for (const auto &com : comentarii)
            {
                if (com.getArticol() == titlu)
                {
                    std::cout << "Text: " << com.getText() << std::endl;
                    std::cout << "Autor: " << com.getAutor() << std::endl;
                    std::cout << "Data: " << com.getData() << std::endl;
                    std::cout << "Like-uri: " << com.getLike() << std::endl;
                    std::cout << "Dislike-uri: " << com.getDislike() << std::endl;
                    std::cout << "Reactii de iubire: " << com.getLove() << std::endl;
                    std::cout << "---------------------------" << std::endl;
                }
            }

            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Articolul cu titlul '" << titlu << "' nu a fost gasit." << std::endl;
    }
}


void afiseazaArticole(const std::vector<Articol> &articole)
{
    for (const auto &art : articole)
    {
        std::cout << "Titlu: " << art.getTitlu() << std::endl;
        std::cout << "Autor: " << art.getAutor() << std::endl;
        std::cout << "Continut: " << art.getContinut() << std::endl;
        std::cout << "Data: " << art.getData() << std::endl;
        std::cout << "Like-uri: " << art.getLike() << std::endl;
        std::cout << "Dislike-uri: " << art.getDislike() << std::endl;
        std::cout << "Reactii de iubire: " << art.getLove() << std::endl;
        std::cout << std::endl;
    }
}

void editeazaArticol(std::vector<Articol>& articole, const std::vector<std::string>& args)
{
    if (args.size() < 3) {
        std::cout << "Parametri insuficienti pentru comanda 'editeaza_articol'." << std::endl;
        return;
    }

    std::string titlu = args[1];
    std::string nouContinut = args[2];

    bool articolGasit = false;
    for (auto& art : articole)
    {
        if (art.getTitlu() == titlu)
        {
            art.setContinut(nouContinut);
            articolGasit = true;
            break;
        }
        if (art.getContinut() == nouContinut)
        {
            art.setContinut(nouContinut);
            articolGasit = true;
            break;
        }
    }

    if (articolGasit)
    {
        std::cout << "Continutul articolului '" << titlu << "' a fost actualizat cu succes!" << std::endl;

        // Save changes to file
        std::ofstream file("C:\\Users\\Alesia\\Desktop\\Final_exe\\teste\\Shared\\Files\\articole.txt");
        if (file.is_open())
        {
            for (const auto& art : articole)
            {
                file << "Titlu: " << art.getTitlu() << '\n';
                file << "Autor: " << art.getAutor() << '\n';
                file << "Continut: " << art.getContinut() << '\n';
                file << "Data: " << art.getData() << '\n';
                file << "Like-uri: " << art.getLike() << '\n';
                file << "Dislike-uri: " << art.getDislike() << '\n';
                file << "Reactii de iubire: " << art.getLove() << '\n';
                 file << std::endl;
            }
            file.close();
        }
        else
        {
            std::cout << "Eroare la deschiderea fisierului articole.txt." << std::endl;
        }
    }
    else
    {
        std::cout << "Articolul cu titlul '" << titlu << "' nu a fost gasit." << std::endl;
    }
}

void stergeArticol(std::vector<Articol>& articole, const std::vector<std::string>& args)
{
    if (args.size() < 2) {
        std::cout << "Parametri insuficienti pentru comanda 'sterge_articol'." << std::endl;
        return;
    }

    std::string titlu = args[1];

    auto it = std::find_if(articole.begin(), articole.end(), [&titlu](const Articol& art) {
        return art.getTitlu() == titlu;
    });

    if (it != articole.end())
    {
        articole.erase(it);
        std::cout << "Articolul cu titlul '" << titlu << "' a fost sters cu succes!" << std::endl;

        // Save changes to file
        std::ofstream file("C:\\Users\\Alesia\\Desktop\\Final_exe\\teste\\Shared\\Files\\articole.txt");
        if (file.is_open())
        {
            for (const auto& art : articole)
            {
                file << "Titlu: " << art.getTitlu() << '\n';
                file << "Autor: " << art.getAutor() << '\n';
                file << "Continut: " << art.getContinut() << '\n';
                file << "Data: " << art.getData() << '\n';
                file << "Like-uri: " << art.getLike() << '\n';
                file << "Dislike-uri: " << art.getDislike() << '\n';
                file << "Reactii de iubire: " << art.getLove() << '\n';
                 file << std::endl;
            }
            file.close();
        }
        else
        {
            std::cout << "Eroare la deschiderea fisierului articole.txt." << std::endl;
        }
    }
    else
    {
        std::cout << "Articolul cu titlul '" << titlu << "' nu a fost gasit." << std::endl;
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
        std::cout << "Eroare la deschiderea fisierului articole.txt." << std::endl;
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
        std::cout << "Eroare la deschiderea fisierului comentariu.txt." << std::endl;
        return 1;
    }

    // Parse the command line arguments
    if (argc > 1)
    {
        std::string command = argv[1];
        std::vector<std::string> args;
        for (int i = 1; i < argc; i++)
        {
            args.push_back(argv[i]);
        }

        if (command == "adauga_articol")
        {
            adaugaArticol(articole, args);
        }
        else if (command == "afiseaza_articol")
        {
            afiseazaArticol(articole, comentarii, args);
        }
        else if (command == "afiseaza_articole")
        {
            afiseazaArticole(articole);
        }
        else if (command == "editeaza_articol")
        {
            editeazaArticol(articole, args);
        }
        else if (command == "sterge_articol")
        {
            stergeArticol(articole, args);
        }
        else if (command == "iesire")
        {
            std::cout << "Programul s-a incheiat. La revedere!" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "Comanda necunoscuta." << std::endl;
        }
    }
    else
    {
        std::cout << "Nu s-a specificat nicio comanda." << std::endl;
    }

    return 0;
}
