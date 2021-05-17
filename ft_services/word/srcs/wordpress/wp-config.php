<?php
define('DB_NAME', 'my_db');
define('DB_USER', 'admin');
define('DB_PASSWORD', 'password');
define('DB_HOST', 'cip-mariadb');
define('WP_HOME', 'http://192.168.99.10:5050' );
define('WP_SITEURL', 'http://192.168.99.10:5050' );
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');
$table_prefix  = 'wp_';
define('WP_DEBUG', false);
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

require_once(ABSPATH . 'wp-settings.php');
