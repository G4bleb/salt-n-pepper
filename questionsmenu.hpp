#ifndef QUESTIONSMENU_HPP
#define QUESTIONSMENU_HPP

/**
 * \file mainmenu.hpp
 * \brief Header du menu principal
 * \author Barraud Lorens
 * \date 15 juin 2018
 */

#include "include.hpp"
#include "propositionsmenu.hpp"

namespace Ui {
class QuestionsMenu;
}

/*! \class QuestionsMenu
   * \brief classe representant les propositions des questions
   *
   *  La classe permet l'administration des propositions
   */

class QuestionsMenu : public QDialog
{
    Q_OBJECT
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe QuestionsMenu
         *
         *  \param driver_forst_window:pointeur sur le driver de la bdd
         *  \param con_first_window:connexion à la bdd
         *  \param selected_id_topic: prend l'id du theme de la question selectionnee
         *  \param parent:pointeur qui pointe sur la fenetre precedente
         */
    explicit QuestionsMenu(Driver * driver_first_window,Connection * con_first_window,int selected_id_topic,QWidget *parent = 0);


    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe QuestionsMenu
         */

    ~QuestionsMenu();

private slots:
    /*!
       *  \brief rend une case cliquable
       *
       *  Methode qui permet de prendre les coordonnées
       *  d'une case du tableau des questions
       *
       *  \param row: la ligne de la case
       *  \param column: la colonne de la case
       */

    void on_tableWidget_Question_cellClicked(int row, int column);

    /*!
       *  \brief Suppression d'une question
       *
       *  Methode qui permet de supprimer une question
       *
       */

    void on_pushButton_delete_clicked();

    /*!
       *  \brief Modification d'une question
       *
       *  Methode qui permet de modifier les donnees
       *  d'une question
       */

    void on_pushButton_set_clicked();

    /*!
       *  \brief Ajout d'une proposition
       *
       *  Methode qui permet d'ajouter une question
       *
       */
    void on_pushButton_add_clicked();

    /*!
       *  \brief Ouverture d'une nouvelle fenetre
       *
       *  Methode qui permet de voir les propositions associees à
       * une question
       *
       */
    void on_pushButton_look_clicked();

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
    Ui::QuestionsMenu *ui;
    PropositionsMenu * propositionsMenu;
    QWidget *lastWindow;

    /*--------- DRIVER ----------*/
    Driver * driver_second_window;

    /*--------- CONNECTION ----------*/
    Connection * con_second_window;

    /*--------- PREPARED_STATEMENT ----------*/
    PreparedStatement * prepared_stmt_show_question;
    PreparedStatement * prepared_stmt_delete_question;
    PreparedStatement * prepared_stmt_set_question;
    PreparedStatement * prepared_stmt_add_question;
    PreparedStatement * prepared_stmt_get_num_question;
    PreparedStatement * prepared_stmt_status_question;

    /*--------- RESULTSET ----------*/
    ResultSet * res_show_question;
    ResultSet * res_get_num_question;

    QVector < QVector <QLabel*> > tableQuestion;

    int id_topic,row_table,column_table,selected_row,num_question,question_selected,status;
};

#endif // QUESTIONSMENU_HPP
