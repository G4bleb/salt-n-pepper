#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

/**
 * \file mainwindow.hpp
 * \brief Header de la page de connexion
 * \author Barraud Lorens
 * \date 15 juin 2018
 */

#include "include.hpp"
#include "mainmenu.hpp"

namespace Ui {
class MainWindow;
}

/*! \class MainWindow
   * \brief classe representant le page de connexion
   *
   *  La classe permet la connexion à la bdd
   */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe MainWindow
         *
         *  \param parent:pointeur qui pointe sur la fenetre precedente
         */

    explicit MainWindow(QWidget *parent = 0);

    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe MainWindow
         */

    ~MainWindow();

private slots:

    /*!
       *  \brief Connexion à la bdd
       *
       *  Methode qui permet de se connecter
       *  Ouverture d'une nouvelle fenetre
       */

    void on_pushButton_login_clicked();

    /*!
       *  \brief Fermeture de l'application
       */

    void on_pushButton_quit_clicked();

private:
    Ui::MainWindow *ui;
    MainMenu *mainMenu;
    Driver *driver;
    Connection *con;
    int status;

};

#endif // MAINWINDOW_HPP
