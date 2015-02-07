<?PHP
session_start();
include ("auth.php");
if (auth($_POST['login'], $_POST['passwd']))
{
	$_SESSION['loggued_on_user'] = $_POST['login'];
	echo 'You are now loggued on';
}
else
{
	$_SESSION['loggued_on_user'] = "";
	echo 'Login failed';
}
echo '<meta http-equiv="refresh" content="1;URL=../index.php">';
?>
