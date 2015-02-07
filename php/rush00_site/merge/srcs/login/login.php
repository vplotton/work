<?PHP
session_start();
include ("auth.php");
if (auth($_POST['login'], $_POST['passwd']))
{
	$_SESSION['loggued_on_user'] = $_POST['login'];
	header("Location: ../../index.php?login=success");
}
else
{
	$_SESSION['loggued_on_user'] = "";
	header("Location: ../../index.php?login=failed");
}
?>
