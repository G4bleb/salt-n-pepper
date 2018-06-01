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
        password   Char (64) NOT NULL ,
        best_score Int ,
        id_game    Int
	,CONSTRAINT user_PK PRIMARY KEY (id_user)

	,CONSTRAINT user_game_FK FOREIGN KEY (id_game) REFERENCES game(id_game)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: topic
#------------------------------------------------------------

CREATE TABLE topic(
        id_theme   Int  Auto_increment  NOT NULL ,
        theme_name Varchar (100) NOT NULL
	,CONSTRAINT topic_PK PRIMARY KEY (id_theme)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: question
#------------------------------------------------------------

CREATE TABLE question(
        id_theme      Int NOT NULL ,
        num_question  Int NOT NULL ,
        main_question Varchar (100) NOT NULL ,
        answer1       Varchar (50) NOT NULL ,
        answer2       Varchar (50) NOT NULL
	,CONSTRAINT question_PK PRIMARY KEY (id_theme,num_question)

	,CONSTRAINT question_topic_FK FOREIGN KEY (id_theme) REFERENCES topic(id_theme)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: proposition
#------------------------------------------------------------

CREATE TABLE proposition(
        id_theme         Int NOT NULL ,
        num_question     Int NOT NULL ,
        num_proposition  Int NOT NULL ,
        main_proposition Varchar (100) NOT NULL ,
        answer_nb        TinyINT NOT NULL
	,CONSTRAINT proposition_PK PRIMARY KEY (id_theme,num_question,num_proposition)

	,CONSTRAINT proposition_question_FK FOREIGN KEY (id_theme,num_question) REFERENCES question(id_theme,num_question)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: game_question
#------------------------------------------------------------

CREATE TABLE game_question(
        id_game      Int NOT NULL ,
        id_theme     Int NOT NULL ,
        num_question Int NOT NULL
	,CONSTRAINT game_question_PK PRIMARY KEY (id_game,id_theme,num_question)

	,CONSTRAINT game_question_game_FK FOREIGN KEY (id_game) REFERENCES game(id_game)
	,CONSTRAINT game_question_question0_FK FOREIGN KEY (id_theme,num_question) REFERENCES question(id_theme,num_question)
)ENGINE=InnoDB;

