#------------------------------------------------------------
#        Script MySQL.
#------------------------------------------------------------

#------------------------------------------------------------
# Tables reset
#------------------------------------------------------------

drop table if exists user;
drop table if exists game_question;
drop table if exists proposition;
drop table if exists question;
drop table if exists topic;
drop table if exists game;

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
        login      Varchar (30) NOT NULL ,
        password   Char (64) NOT NULL ,
        best_score Int ,
        token      Char (16) ,
        id_game    Int
	,CONSTRAINT user_PK PRIMARY KEY (id_user)

	,CONSTRAINT user_game_FK FOREIGN KEY (id_game) REFERENCES game(id_game)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: topic
#------------------------------------------------------------

CREATE TABLE topic(
        id_topic   Int  Auto_increment  NOT NULL ,
        topic_name Varchar (100) NOT NULL
	,CONSTRAINT topic_PK PRIMARY KEY (id_topic)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: question
#------------------------------------------------------------

CREATE TABLE question(
        id_topic      Int NOT NULL ,
        num_question  Int NOT NULL ,
        main_question Varchar (100) NOT NULL ,
        answer1       Varchar (40) NOT NULL ,
        answer2       Varchar (40) NOT NULL,
        enabled BOOLEAN NOT NULL DEFAULT TRUE
	,CONSTRAINT question_PK PRIMARY KEY (id_topic,num_question)

	,CONSTRAINT question_topic_FK FOREIGN KEY (id_topic) REFERENCES topic(id_topic) ON DELETE CASCADE
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: proposition
#------------------------------------------------------------

CREATE TABLE proposition(
        id_topic         Int NOT NULL ,
        num_question     Int NOT NULL ,
        num_proposition  Int NOT NULL ,
        main_proposition Varchar (100) NOT NULL ,
        answer_nb        TinyINT NOT NULL,
        enabled BOOLEAN NOT NULL DEFAULT TRUE
	,CONSTRAINT proposition_PK PRIMARY KEY (id_topic,num_question,num_proposition)

	,CONSTRAINT proposition_question_FK FOREIGN KEY (id_topic,num_question) REFERENCES question(id_topic,num_question) ON DELETE CASCADE
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: game_question
#------------------------------------------------------------

CREATE TABLE game_question(
        id_game      Int NOT NULL ,
        id_topic     Int NOT NULL ,
        num_question Int NOT NULL
	,CONSTRAINT game_question_PK PRIMARY KEY (id_game,id_topic,num_question)

	,CONSTRAINT game_question_game_FK FOREIGN KEY (id_game) REFERENCES game(id_game) ON DELETE CASCADE
	,CONSTRAINT game_question_question0_FK FOREIGN KEY (id_topic,num_question) REFERENCES question(id_topic,num_question) ON DELETE CASCADE
)ENGINE=InnoDB;
