
/*----TOPIC POLITIQUE-----*/
INSERT INTO `topic` (`id_topic`, `topic_name`) VALUES ('1', 'Politique');

INSERT INTO `question` (`id_topic`, `num_question`, `main_question`, `answer1`, `answer2`) VALUES ('1', '1', 'Bernard Tapie, un tapis ou les deux ?', 'Bernard Tapie', 'Un tapis');
INSERT INTO `proposition` (`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES
(1, 1, 1, 'Il peut voler', 3),
(1, 1, 2, 'On peut le rouler', 3),
(1, 1, 3, 'A été ministre de la ville', 1),
(1, 1, 4, 'Ses ancêtres remontent à moins 500 avant J.C.', 2),
(1, 1, 5, 'Il y a beaucoup de contrefaçons', 2),
(1, 1, 6, 'Il s\'entretient de façon journalière avec un aspirateur', 2),
(1, 1, 7, 'Matricule 265-449G', 1),
(1, 1, 8, 'A une époque, j\'ai vomi dessus', 2);

INSERT INTO `question` (`id_topic`, `num_question`, `main_question`, `answer1`, `answer2`) VALUES ('1', '2', 'Sissi, Oui-Oui ou les deux ?', 'Sissi', 'Oui-Oui');
INSERT INTO `proposition` (`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES
 (1, 2, 1, 'Impératrice', 1),
(1, 2, 2, 'Vit dans un monde merveilleux', 3),
(1, 2, 3, 'A vraiment existé(e)', 1),
(1, 2, 4, 'Est marié(e)', 1),
(1, 2, 5, 'Potiron', 2),
(1, 2, 6, 'Romy Schneider', 1),
(1, 2, 7, 'Vous fait perdre à ni oui ni non', 2);

INSERT INTO `question` (`id_topic`, `num_question`, `main_question`, `answer1`, `answer2`) VALUES ('1', '3', 'Nicolas Sarkozy, un clou ou les deux ?', 'Nicolas Sarkozy', 'Un clou');
INSERT INTO `proposition` (`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES
(1, 3, 1, 'On peut taper dessus', 3),
(1, 3, 2, 'Maire de Neuilly', 1),
(1, 3, 3, 'Il a une tête plate', 2),
(1, 3, 4, 'Il vaut mieux éviter de marcher dessus', 3),
(1, 3, 5, 'Il a le bout pointu', 2),
(1, 3, 6, 'Il en existe sans tête', 2),
(1, 3, 7, 'Il est très utile', 3);

INSERT INTO `question` (`id_topic`, `num_question`, `main_question`, `answer1`, `answer2`) VALUES ('1', '4', 'Un pet, la paix ou les deux ?', 'Un pet', 'La paix');
INSERT INTO `proposition` (`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES
(1, 4, 1, 'Il faut se serrer la main avant', 2),
(1, 4, 2, 'Ca arrive souvent après une dégustation de poix chiches', 1),
(1, 4, 3, 'On supporte mieux le sien que celui des autres', 1),
(1, 4, 4, 'On peut regretter amèrement de l\'avoir fait', 3),
(1, 4, 5, 'Ca peut soulager une nation entière', 3),
(1, 4, 6, 'Gainsbourg en a fait un livre', 1),
(1, 4, 7, 'Ca peut engendrer des conflits', 3);

/*----TOPIC SPORT-----*/

INSERT INTO `topic` (`id_topic`, `topic_name`) VALUES ('2', 'Sport');

INSERT INTO `question` (`id_topic`, `num_question`, `main_question`, `answer1`, `answer2`) VALUES ('2', '1', 'Monfils, mon père ou les deux ?', 'Monfils', 'Mon père');
INSERT INTO `proposition` (`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES
(2, 1, 1, 'Il est déja allé en demi-finale à Roland Garros', 1),
(2, 1, 2, 'Il a couché avec ma mère', 2),
(2, 1, 3, 'Il a un très bon revers', 3),
(2, 1, 4, '1m93', 1),
(2, 1, 5, 'A des enfants qui courent autour de lui pour ramasser ses balles', 1),
(2, 1, 6, 'Ce n’est pas mon fils', 3);

INSERT INTO `question` (`id_topic`, `num_question`, `main_question`, `answer1`, `answer2`) VALUES ('2', '2', 'Frankenstein, Frank Leboeuf ou les deux ?', 'Frankenstein', 'Frank Leboeuf');
INSERT INTO `proposition` (`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES
(2, 2, 1, 'Joue au foot', 2),
(2, 2, 2, 'A une fermeture éclair sur la gueule', 1),
(2, 2, 3, 'A le crâne rasé', 2),
(2, 2, 4, 'C\'est pas un beau gosse', 1),
(2, 2, 5, 'Est champion du monde', 2),
(2, 2, 6, 'A fait du cinéma', 3),
(2, 2, 7, 'Son corps est fait de différents cadavres', 1);

/*----TOPIC MUSIQUE-----*/

INSERT INTO `topic` (`id_topic`, `topic_name`) VALUES ('3', 'Musique');

INSERT INTO `question` (`id_topic`, `num_question`, `main_question`, `answer1`, `answer2`) VALUES ('3', '1', 'Pavarotti, poulet rôti ou les deux ?', 'Pavarotti', 'Poulet rôti');
INSERT INTO `proposition` (`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES
(3, 1, 1, 'Ne chante pas', 2),
(3, 1, 2, 'Il n\'y aucune raison de le ficeler', 1),
(3, 1, 3, 'Fait ses tournées sur une broche', 2),
(3, 1, 4, 'Il s\'exprime comme ça "ahhhhhhhhhhhh"', 1),
(3, 1, 5, 'A des bonnes cuisses', 3),
(3, 1, 6, 'Chargé de cholestérol', 3),
(3, 1, 7, 'Tu peux en avoir la moitié si tu veux', 2);

/*----TOPIC ISEN-----*/

INSERT INTO `topic` (`id_topic`, `topic_name`) VALUES ('4', 'ISEN');

INSERT INTO `question` (`id_topic`, `num_question`, `main_question`, `answer1`, `answer2`) VALUES ('4', '1', 'Un CSI, un CIR ou les deux ?', 'CSI', 'CIR');
INSERT INTO `proposition` (`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES
(4, 1, 1, 'A fait un bac STI2D', 2),
(4, 1, 3, 'Ne sais pas coder', 1),
(4, 1, 4, 'Paye cher l\'ISEN', 3),
(4, 1, 5, 'Paye PLUS cher l\'ISEN', 2),
(4, 1, 6, 'Va au dub', 3),
(4, 1, 7, 'Passe des khôlles', 1);

/*----GAME-----*/

INSERT INTO `game` (`id_game`) VALUES
(1),
(2),
(3);

/*----GAME_QUESTION-----*/

INSERT INTO `game_question` (`id_game`, `id_topic`, `num_question`) VALUES
(1, 1, 1),
(3, 1, 1),
(2, 1, 2),
(1, 1, 3),
(3, 1, 3),
(2, 2, 1),
(1, 2, 2),
(3, 2, 2),
(2, 3, 1);

/*----USER-----*/

INSERT INTO `user` (`id_user`, `login`, `password`, `best_score`, `id_game`, `token`) VALUES
(1, 'login', sha2('password', 256), NULL, NULL, NULL),
(2, 'Alain', sha2('password', 256), 10002, 1, NULL),
(3, 'Pierre', sha2('password', 256), 12912, 2, NULL),
(4, 'Jean', sha2('password', 256), 12394, 3, NULL),
(5, 'Jacques', sha2('password', 256), 10071, 1, NULL),
(6, 'Kevin', sha2('password', 256), 11675, 2, NULL),
(7, 'Durand', sha2('password', 256), 12317, 3, NULL),
(8, 'Bernard', sha2('password', 256), NULL, NULL, NULL),
(9, 'Zachary', sha2('password', 256), NULL, NULL, NULL),
(10, 'Alex', sha2('password', 256), NULL, NULL, NULL),
(11, 'Julien', sha2('password', 256), NULL, NULL, NULL),
(12, 'Madeleine', sha2('password', 256), NULL, NULL, NULL),
(13, 'Sandrine', sha2('password', 256), NULL, NULL, NULL),
(14, 'Marguerite', sha2('password', 256), NULL, NULL, NULL),
(15, 'Eliane', sha2('password', 256), NULL, NULL, NULL),
(16, 'Mathilde', sha2('password', 256), NULL, NULL, NULL),
(17, 'Manon', sha2('password', 256), NULL, NULL, NULL),
(18, 'Séverine', sha2('password', 256), NULL, NULL, NULL),
(19, 'Céline', sha2('password', 256), NULL, NULL, NULL),
(20, 'Véronique', sha2('password', 256), NULL, NULL, NULL),
(21, 'Micheline', sha2('password', 256), NULL, NULL, NULL);
