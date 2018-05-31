#------------------------------------------------------------
#        Script MySQL.
#------------------------------------------------------------


#------------------------------------------------------------
# Table: game
#------------------------------------------------------------

CREATE TABLE game(
        id_game Int  Auto_increment  NOT NULL
	,CONSTRAINT game_PK PRIMARY KEY (id_game)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: user
#------------------------------------------------------------

CREATE TABLE user(
        id_user    Int  Auto_increment  NOT NULL ,
        login      Varchar (50) NOT NULL ,
        password   Varchar (50) NOT NULL ,
        best_score Int ,
        id_game    Int
	,CONSTRAINT user_PK PRIMARY KEY (id_user)

	,CONSTRAINT user_game_FK FOREIGN KEY (id_game) REFERENCES game(id_game)
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
# Table: question
#------------------------------------------------------------

CREATE TABLE question(
        id_theme      Int NOT NULL ,
        id_question   Int NOT NULL ,
        main_question Varchar (100) NOT NULL ,
        answer1       Varchar (50) NOT NULL ,
        answer2       Varchar (50) NOT NULL
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
# Table: game_question
#------------------------------------------------------------

CREATE TABLE game_question(
        id_game     Int NOT NULL ,
        id_theme    Int NOT NULL ,
        id_question Int NOT NULL
	,CONSTRAINT game_question_PK PRIMARY KEY (id_game,id_theme,id_question)

	,CONSTRAINT game_question_game_FK FOREIGN KEY (id_game) REFERENCES game(id_game)
	,CONSTRAINT game_question_question0_FK FOREIGN KEY (id_theme,id_question) REFERENCES question(id_theme,id_question)
)ENGINE=InnoDB;

