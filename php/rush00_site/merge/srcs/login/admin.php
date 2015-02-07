<?PHP
session_start();
include ('return_pwd.php');
$crypt = return_pwd("admin");
$crypt = mcrypt_encrypt(MCRYPT_RIJNDAEL_128, "admin"
	, $crypt, MCRYPT_MODE_NOFB);
$hash = hash('whirlpool', $_SERVER[PHP_AUTH_PW]);
if ($_SESSION['loggued_on_user'] == "admin")
{
	echo "Bonjour admin, ca farte??";
}
else
	echo "Vous n'etes pas connecte en tant qu'admin";
?>
