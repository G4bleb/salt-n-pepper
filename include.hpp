#ifndef INCLUDE_HPP
#define INCLUDE_HPP

/**
 * \file include.hpp
 * \brief Contient toutes les bibliotheques et namespace
 * \author Barraud Lorens
 * \date 15 juin 2018
 */

#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/exception.h>

#include <QMainWindow>
#include <iostream>
#include <QLabel>
#include <QMessageBox>
#include <QDialog>
#include <QRadioButton>
#include <QDebug>

/*! \namespace std
 *
 * permet l'affichage de texte dans la console
 */
using namespace std;

/*! \namespace sql
 *
 * espace de nommage regroupant les outils composants
 * les requetes sql
 */

using namespace sql;

#endif // INCLUDE_HPP
