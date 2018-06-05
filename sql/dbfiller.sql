
insert into user(id_user, login, password) values('1', 'login', sha2('password', 256));
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

INSERT INTO `topic` (`id_topic`, `topic_name`) VALUES ('2', 'Sport');
INSERT INTO `question` (`id_topic`, `num_question`, `main_question`, `answer1`, `answer2`) VALUES ('2', '1', 'Monfils, mon père ou les deux ?', 'Monfils', 'Mon père');
INSERT INTO `proposition` (`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES ('2', '1', '1', 'Il est déja allé en demi-finale à Roland Garros', '1');
INSERT INTO `proposition` (`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES ('2', '1', '2', 'Il a couché avec ma mère', '2');
INSERT INTO `proposition` (`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES ('2', '1', '3', 'Il a un très bon revers', '3');
INSERT INTO `proposition` (`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES ('2', '1', '4', '1m93', '1');
INSERT INTO `proposition` (`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES ('2', '1', '5', 'A des enfants qui courent autour de lui pour ramasser ses balles', '1');
INSERT INTO `proposition` (`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES ('2', '1', '6', 'Ce n’est pas mon fils', '3');

INSERT INTO `topic` (`id_topic`, `topic_name`) VALUES ('3', 'ISEN');

INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Alain', sha2('password', 256), '32', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Pierre', sha2('password', 256), '78', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Jean', sha2('password', 256), '25', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Jacques', sha2('password', 256), '23', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Kevin', sha2('password', 256), '14', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Durand', sha2('password', 256), '41', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Bernard', sha2('password', 256), '55', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Zachary', sha2('password', 256), '5', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Alex', sha2('password', 256), '36', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Julien', sha2('password', 256), '1', '1', NULL);

INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Madeleine', sha2('password', 256), '63', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Sandrine', sha2('password', 256), '25', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Marguerite', sha2('password', 256), '78', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Eliane', sha2('password', 256), '36', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Mathilde', sha2('password', 256), '63', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Manon', sha2('password', 256), '12', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Séverine', sha2('password', 256), '45', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Céline', sha2('password', 256), '72', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Véronique', sha2('password', 256), '12', '1', NULL);
INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES (NULL, 'Micheline', sha2('password', 256), '3', '1', NULL);
