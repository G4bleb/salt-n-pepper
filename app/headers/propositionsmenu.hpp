#ifndef PROPOSITIONSMENU_HPP
#define PROPOSITIONSMENU_HPP

/**
 * \file propositionsmenu.hpp
 * \brief Affichage des propositions des questions
 * \author Barraud Lorens
 * \date 15 juin 2018
 */

#include "include.hpp"

namespace Ui {
class PropositionsMenu;
}

/*! \class PropositionsMenu
   * \brief classe representant les propositions des questions
   *
   *  La classe permet l'administration des propositions
   */

class PropositionsMenu : public QDialog
{
    Q_OBJECT

public:

    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe PropositionsMenu
         *
         *  \param driver_second_window pointeur sur le driver de la bdd
         *  \param con_second_window connexion à la bdd
         *  \param id_topic prend l'id du theme de la question selectionnee
         *  \param questions_selected prend l'id de la question selectionnee
         *  \param parent pointeur qui pointe sur la fenetre precedente
         */

    explicit PropositionsMenu(Driver* driver_second_window,Connection* con_second_window,int id_topic,int question_selected,QWidget *parent = 0);


    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe PropositionsMenu
         */

    ~PropositionsMenu();

private slots:
    /*!
       *  \brief rend une case cliquable
       *
       *  Methode qui permet de prendre les coordonnées
       *  d'une case du tableau des propositions
       *
       *  \param row la ligne de la case
       *  \param column la colonne de la case
       */

    void on_tableWidget_Proposition_cellClicked(int row);

    /*!
       *  \brief Modification d'une proposition
       *
       *  Methode qui permet de modifier les donnees
       *  d'une proposition d'une question
       */

    void on_pushButton_set_clicked();

    /*!
       *  \brief Suppression d'une proposition
       *
       *  Methode qui permet de supprimer une proposition
       *  d'une question
       *
       */

    void on_pushButton_delete_clicked();

    /*!
       *  \brief Ajout d'une proposition
       *
       *  Methode qui permet d'ajouter une proposition
       *  à une question
       *
       */

    void on_pushButton_add_clicked();

    /*!
       *  \brief Change l'etat d'une proposition
       */

    void on_pushButton_disable_clicked();

    /*!
       *  \brief Fermeture de la fenetre
       *
       *  On revient sur la fenetre precedente
       *
       */

    void on_pushButton_return_clicked();

private:
    Ui::PropositionsMenu *ui;
    QWidget *lastWindow;

    /*--------- DRIVER ----------*/
    Driver * driver_third_window;

    /*--------- CONNECTION ----------*/
    Connection * con_third_window;

    /*--------- PREPARED_STATEMENT ----------*/
    PreparedStatement * prepared_stmt_show_proposition;
    PreparedStatement * prepared_stmt_get_answer1;
    PreparedStatement * prepared_stmt_get_answer2;
    PreparedStatement * prepared_stmt_get_num_proposition;
    PreparedStatement * prepared_stmt_delete_proposition;
    PreparedStatement * prepared_stmt_set_proposition;
    PreparedStatement * prepared_stmt_add_proposition;
    PreparedStatement * prepared_stmt_status_proposition;

    /*--------- RESULTSET ----------*/
    ResultSet * res_show_proposition;
    ResultSet * res_get_answer1;
    ResultSet * res_get_answer2;
    ResultSet * res_get_num_proposition;

    QVector <QVector <QLabel*> > tableProposition;

    int id_topic_parent,num_question_parent,row_table,column_table,selected_row,answer,num_proposition,status;

};

#endif // PROPOSITIONSMENU_HPP
