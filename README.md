
# Salt'n'Pepper
## Logiciels prérequis :
### Partie Web
 - MySQL
 - Apache 2 + PHP7
### Partie C++
 - g++
 - Qt (version supérieure ou égale à 5.7.1)
 - librairie mysqlccpconnector
## Instructions de mise en place web
1. Créer dans la base de données un utilisateur nommé `etd-cir2-prj-10` dont le mot de passe est `ewWK3oYg`
   1. Créer avec lui une base de données nommée `etd-cir2-prj-10`, sur laquelle il possède les droits
   2. Importer `salt-n-pepper/sql/db.sql` dans MySQL
   3. Importer `salt-n-pepper/sql/dbfiller.sql` dans MySQL
       1. Le site se connecte par défaut sur l'hôte local. Si la base de donnée n'est pas sur le même serveur que le serveur web,   changer dans `salt-n-pepper/website/php/dbconnect.php` la ligne 7, en remplaçant `127.0.0.1` par l'adresse de votre base

 2. Ajouter le répertoire `salt-n-pepper/website` dans les fichiers du serveur web : il s'y trouvera le site web (par défaut `/var/www`)
 3. Copier `salt-n-pepper/salt-n-pepper.conf` du répertoire du projet à `/etc/apache2/sites-available`
    1. Activer cette configuration : `# a2ensite salt-n-pepper.conf`
    2. Désactiver la configuration par défaut : `# a2dissite 000-default.conf`
    3. Recharger apache2 : `# /etc/init.d/apache2 reload`
 5. Aller sur l'adresse du serveur dans un navigateur web.

## Instructions de compilation C++
 1. Naviguer vers `salt-n-pepper/app`
 2. Générer le Makefile : `$ qmake`
 3. Compiler via le Makefile : `$ make`
 4. Lancer le programme : `$ ./salt-n-pepper`
