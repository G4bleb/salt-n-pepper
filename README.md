# Salt'n'Pepper
## Logiciels prérequis :
### Partie Web
 - MySQL
 - Apache2 + PHP7
### Partie C++
 - g++
 - Qt (version supérieure ou égale à 5.7.1)
 - librairie mysqlccpconnector
## Instructions de mise en place web
1. Modifier dans le fichier `salt-n-pepper/website/php/dbconnect.php` les lignes 10 à 15 pour paramétrer l'accès du site à votre base de données :
    - Nom de la base
    - Nom de l'utilisateur
    - Mot de passe de l'utilisateur
    - Adresse de la base
 2. Importer `salt-n-pepper/sql/db.sql` dans votre base
 3. Importer `salt-n-pepper/sql/dbfiller.sql` dans base
 4. Copier le répertoire `salt-n-pepper/website` dans les fichiers du serveur web : il s'y trouvera le site web (par défaut `/var/www`)

## Instructions de compilation C++
 1. Naviguer vers `salt-n-pepper/app`
 2. Générer le Makefile : `$ qmake`
 3. Compiler via le Makefile : `$ make`
 4. Lancer le programme : `$ ./salt-n-pepper`
