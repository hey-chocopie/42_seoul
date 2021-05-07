openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/O=42Seoul/OU=Gun/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
mv default.conf /etc/nginx/conf.d
mv index.html /var/www/localhost/htdocs/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

mkdir -p /run/nginx
nginx -g "daemon off;"
#wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
#tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
#mv phpMyAdmin-5.0.2-all-languages phpmyadmin
#mv phpmyadmin /var/www/html/

#wget https://wordpress.org/latest.tar.gz
#tar -xvf latest.tar.gz
#mv wordpress/ var/www/html/
#chown -R www-data:www-data /var/www/html/wordpress

#cp -rp var/www/html/phpmyadmin/config.sample.inc.php var/www/html/phpmyadmin/config.inc.php
#cp var/www/html/wordpress/wp-config-sample.php var/www/html/wordpress/wp-config.php
#cat config.inc.php > var/www/html/phpmyadmin/config.inc.php
#cat wp-config.php > var/www/html/wordpress/wp-config.php
#chown -R www-data:www-data /var/www/html/phpmyadmin

#mkdir /var/www/html/phpmyadmin/tmp && \
#chmod 777 /var/www/html/phpmyadmin/tmp

#rm phpMyAdmin-5.0.2-all-languages.tar.gz latest.tar.gz server config.inc.php wp-config.php

#service nginx reload
#service nginx start
#service mysql start
#service php7.3-fpm start

#echo "CREATE DATABASE IF NOT EXISTS wordpress;" \
#	| mysql -u root --skip-password
#echo "CREATE USER IF NOT EXISTS 'djeon'@'localhost' IDENTIFIED BY 'djeon';" \
#	| mysql -u root --skip-password
#echo "GRANT ALL PRIVILEGES ON *.* TO 'djeon'@'localhost' WITH GRANT OPTION;" \
#	| mysql -u root --skip-password

#bash
