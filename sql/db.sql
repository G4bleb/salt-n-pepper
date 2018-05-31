#------------------------------------------------------------
#        Script MySQL.
#------------------------------------------------------------


#------------------------------------------------------------
# Table: user
#------------------------------------------------------------

CREATE TABLE user(
        id_user  Int  Auto_increment  NOT NULL ,
        login    Varchar (50) NOT NULL ,
        password Varchar (50) NOT NULL
	,CONSTRAINT user_PK PRIMARY KEY (id_user)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: theme
#------------------------------------------------------------

CREATE TABLE theme(
        id_theme   Int  Auto_increment  NOT NULL ,
        theme_name Varchar (100) NOT NULL
	,CONSTRAINT theme_PK PRIMARY KEY (id_theme)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: game
#------------------------------------------------------------

CREATE TABLE game(
        id_theme Int NOT NULL ,
        id_game  Int NOT NULL
	,CONSTRAINT game_PK PRIMARY KEY (id_theme,id_game)

	,CONSTRAINT game_theme_FK FOREIGN KEY (id_theme) REFERENCES theme(id_theme)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: question
#------------------------------------------------------------

CREATE TABLE question(
        id_theme      Int NOT NULL ,
        id_question   Int NOT NULL ,
        main_question Varchar (100) NOT NULL ,
        answer1       Varchar (50) NOT NULL ,
        answer2       Varchar (50) NOT NULL ,
        answer3       Varchar (50) NOT NULL
	,CONSTRAINT question_PK PRIMARY KEY (id_theme,id_question)

	,CONSTRAINT question_theme_FK FOREIGN KEY (id_theme) REFERENCES theme(id_theme)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: proposition
#------------------------------------------------------------

CREATE TABLE proposition(
        id_theme       Int NOT NULL ,
        id_question    Int NOT NULL ,
        id_proposition Int NOT NULL ,
        question       Varchar (100) NOT NULL ,
        answer_nb      TinyINT NOT NULL
	,CONSTRAINT proposition_PK PRIMARY KEY (id_theme,id_question,id_proposition)

	,CONSTRAINT proposition_question_FK FOREIGN KEY (id_theme,id_question) REFERENCES question(id_theme,id_question)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Played
#------------------------------------------------------------

CREATE TABLE Played(
        id_user    Int NOT NULL ,
        id_theme   Int NOT NULL ,
        id_game    Int NOT NULL ,
        game_score Int NOT NULL
	,CONSTRAINT Played_PK PRIMARY KEY (id_user,id_theme,id_game)

	,CONSTRAINT Played_user_FK FOREIGN KEY (id_user) REFERENCES user(id_user)
	,CONSTRAINT Played_game0_FK FOREIGN KEY (id_theme,id_game) REFERENCES game(id_theme,id_game)
)ENGINE=InnoDB;

