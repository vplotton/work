<?PHP
session_start();
if (isset($_SESSION[loggued_on_user]))
{
	echo 'Compte: '.$_SESSION[loggued_on_user].'.';
	echo '</br><a href="srcs/logout.php">Se deconnecter.</a>';
}
else
{
	echo '<form class="log" method="POST" action="srcs/login.php">
		<input type="text" name="login" value="" />
		<input type="password" name="passwd" value="" />
		<input type="submit" name="submit" value="OK"/>
		</form>';
	echo '<a class="create" href="srcs/sign_in.php" class="log">Creer un comtpe</a>';
}
?>
