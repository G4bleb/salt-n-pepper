#ifndef MAINMENU_HPP
#define MAINMENU_HPP

/**
 * \file mainmenu.hpp
 * \brief Header du menu principal
 * \author Barraud Lorens
 * \date 15 juin 2018
 */

#include "include.hpp"
#include "questionsmenu.hpp"

namespace Ui {
class MainMenu;
}

/*! \class MainMenu
   * \brief classe representant le menu principal
   *
   *  La classe permet l'administration de
   *  la liste des themes et des utilisateurs
   */

class MainMenu : public QDialog
{
    Q_OBJECT
public:

    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe MainMenu
         *
         *  \param driver:pointeur sur le driver de la bdd
         *  \param con:connexion à la bdd
         *  \param parent:pointeur qui pointe sur la fenetre precedente
         */

    explicit MainMenu(Driver * driver,Connection * con, QWidget *parent = 0);

    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe MainMenu
         */

    ~MainMenu();

private slots:

    /*!
       *  \brief rend une case cliquable
       *
       *  Methode qui permet de prendre les coordonnees
       *  d'une case du tableau des utilisateurs
       *
       *  \param row: la ligne de la case
       *  \param column: la colonne de la case
       */

    void on_tableWidget_User_cellClicked(int row, int column);

    /*!
       *  \brief Modification d'un utilisateur
       *
       *  Methode qui permet de modifier les donnees
       *  d'un utilisateur à la bdd
       */

    void on_pushButton_set_user_clicked();

    /*!
       *  \brief Suppression d'un utilisateur
       *
       *  Methode qui permet de supprimer un utilisateur
       *  de la bdd
       *
       */

    void on_pushButton_delete_user_clicked();

    /*!
       *  \brief rend une case cliquable
       *
       *  Methode qui permet de prendre les coordonnées
       *  d'une case du tableau des thèmes
       *
       *  \param row: la ligne de la case
       *  \param column: la colonne de la case
       */

    void on_tableWidget_Topic_cellClicked(int row, int column);

    /*!
       *  \brief Modification d'un utilisateur
       *
       *  Methode qui permet de modifier les donnees
       *  d'un theme à la bdd
       */

    void on_pushButton_set_topic_clicked();

    /*!
       *  \brief Suppression d'un theme
       *
       *  Methode qui permet de supprimer un theme
       *  de la bdd
       *
       */

    void on_pushButton_delete_topic_clicked();

    /*!
       *  \brief Ajout d'un theme
       *
       *  Methode qui permet d'ajouter un utilisateur
       * à la bdd
       *
       */

    void on_pushButton_add_topic_clicked();

    /*!
       *  \brief Ouverture d'une nouvelle fenetre
       *
       *  Methode qui permet de voir les questions associe à
       * un theme
       *
       */

    void on_pushButton_look_topic_clicked();

    /*!
       *  \brief Fermeture de la fenetre
       *
       *  On revient sur la fenetre precedente
       *
       */
    void on_pushButton_disconnect_clicked();

private:
    Ui::MainMenu *ui;

    QuestionsMenu *questionsMenu;
    QWidget * menuConnexion;

    /*--------- DRIVER ----------*/
    Driver * driver_first_window;

    /*--------- CONNECTION ----------*/
    Connection * con_first_window;

    /*--------- STATEMENT ----------*/
    Statement * stmt_show_user;
    Statement * stmt_show_topic;

    /*--------- PREPARED_STATEMENT ----------*/
    PreparedStatement * prepared_stmt_delete_user;
    PreparedStatement * prepared_stmt_set_user;

    PreparedStatement * prepared_stmt_delete_topic;
    PreparedStatement * prepared_stmt_set_topic;
    PreparedStatement * prepared_stmt_add_topic;

    /*--------- RESULTEST ----------*/
    ResultSet * res_show_user;
    ResultSet * res_show_topic;

    QVector <QVector <QLabel*> > TableFirstThumbnail;
    QVector <QVector <QLabel*> > TableSecondThumbnail;


    int row_table_user,column_table_user,row_table_topic,column_table_topic,selected_row_user,selected_row_topic,selected_id_topic;
};

#endif // MAINMENU_HPP
