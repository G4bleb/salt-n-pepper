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
 1. Ajouter le répertoire website dans les fichiers du serveur web : il s'y trouvera le site web (par défaut `/var/www`)

 3. Copier `salt-n-pepper.conf` dans `/etc/apache2/sites-available`
  3.1. Activer cette configuration : `# a2ensite salt-n-pepper.conf`
  3.2. Désactiver la configuration par défaut : `# a2dissite 000-default.conf`

 3. Créer dans la base de données un utilisateur nommé 'etd-cir2-prj-10' dont le mot de passe est 'ewWK3oYg'
  3.1. Créer avec lui une base de données nommée 'etd-cir2-prj-10', sur laquelle il possède les droits
  3.2. Exécuter sql/db.sql dans MySQL
  3.3. Exécuter sql/dbfiller.sql dans MySQL
4. Copier
