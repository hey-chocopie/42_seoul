#!/bin/sh

PHPMYADMIN_DATA="$(wget https://www.phpmyadmin.net/home_page/version.txt -q -O-)"
PHPMYADMIN_URL="$(echo $PHPMYADMIN_DATA | cut -d ' ' -f 3)"
PHPMYADMIN_VER="$(echo $PHPMYADMIN_DATA | cut -d ' ' -f 1)"

#tar -xvf /tmp/phpMyAdmin-${PHPMYADMIN_VER}-all-languages.tar.gz -C /www
#cp -r /www/phpMyAdmin-${PHPMYADMIN_VER}-all-languages/* /www/
#rm -r /www/phpMyAdmin-${PHPMYADMIN_VER}-all-languages

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages/* /www/
rm phpMyAdmin-5.0.2-all-languages.tar.gz

chmod 777 -R /www/

php -S 0.0.0.0:5000 -t /www/

/bin/sh
