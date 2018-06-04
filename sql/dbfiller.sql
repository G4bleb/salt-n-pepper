
insert into user(id_user, login, password) values('1', 'login', '5E884898DA28047151D0E56F8DC6292773603D0D6AABBDD62A11EF721D1542D8');
insert into topic(id_topic, topic_name) values('1', 'Fraude fiscale');
insert into question(id_topic, num_question, main_question, answer1, answer2) values('1', '1', 'Bernard Tapie, un tapis ou les deux ?', 'Bernard Tapie', 'Un tapis');
insert into proposition(id_topic, num_question, num_proposition, main_proposition, answer_nb) values('1', '1', '1', 'Il peut voler', '3');
insert into proposition(id_topic, num_question, num_proposition, main_proposition, answer_nb) values('1', '1', '2', 'On peut le rouler', '3');
insert into proposition(id_topic, num_question, num_proposition, main_proposition, answer_nb) values('1', '1', '3', 'A été ministre de la ville', '1');
insert into proposition(id_topic, num_question, num_proposition, main_proposition, answer_nb) values('1', '1', '4', 'Ses ancêtres remontent à moins 500 avant J.C.', '2');
insert into proposition(id_topic, num_question, num_proposition, main_proposition, answer_nb) values('1', '1', '5', 'Il y a beaucoup de contrefaçons', '2');
insert into proposition(id_topic, num_question, num_proposition, main_proposition, answer_nb) values('1', '1', '6', 'Il s\'entretient de façon journalière avec un aspirateur', '2');
insert into proposition(id_topic, num_question, num_proposition, main_proposition, answer_nb) values('1', '1', '7', 'Matricule 265-449G', '1');
insert into proposition(id_topic, num_question, num_proposition, main_proposition, answer_nb) values('1', '1', '8', 'A une époque, j\'ai vomi dessus', '2');

insert into game(id_game) values('1');
insert into game_question(id_game, id_topic, num_question) values('1','1','1');
