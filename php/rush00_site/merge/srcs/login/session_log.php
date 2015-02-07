<?PHP
session_start();
if ($_SESSION[loggued_on_user])
{
	if ($_GET[login] == "success")
		echo '<span class="success">Authentification success</span>';
	echo '<div id = "user_log">Compte: '.$_SESSION[loggued_on_user].'.</div>';
	echo '</br><a href="./srcs/login/logout.php" class="log_button">Se deconnecter.</a>';
}
else if ($_GET['new_id'] == "OK" || $_GET[create] == "failed")
{
	if ($_GET[create] == "failed")
		echo '<span class="error">Account creation failed</span>';
	echo '<form method="POST" action="./srcs/login/create.php">
		<input type="text" name="login" placeholder="Nouvel identifiant" />
		<input type="password" name="passwd" placeholder="Mot de passe" />
		<input type="submit" name="submit" value="OK"/>
		</form>';
}
else
{
	if ($_GET[login] == "failed")
		echo '<span class="error">Authentification failed</span>';
	echo '<form method="POST" action="./srcs/login/login.php">
		<input type="text" name="login" placeholder="Identifiant" />
		<input type="password" name="passwd" placeholder="Mot de passe" />
		<input type="submit" name="submit" value="OK"/>
		</form>';
	echo '<a class="log_button" href="./index.php?new_id=OK">Creer un comtpe</a>';
}
?>
