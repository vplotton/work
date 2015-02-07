<?PHP
include ('remove_user.php');
if ($_SESSION['loggued_on_user'] == "admin")
{
	if ($_GET['remove'])
		remove_user($_GET['remove']);
	$file = file_get_contents('./srcs/private/passwd');
	$content = unserialize($file);
	echo '<span id = "users_handle_title">Gestion des utilisateurs
		</span></br>';
	foreach ($content as $value)
	{
		echo '<span width="50px">Compte: </span><span width="100px">'
			.$value['login'].'</span>';
		echo '<span float="right">
			<a href="./index.php?modif=accounts&&remove='
			.$value['login'].'">Supprimer</a>
			| 
			<form method="POST" action="./srcs/admin/change_user.php?login='
			.$value['login'].'">
			<input type="password" name="passwd" placeholder="Nouveau mot de passe" />
			<input type="submit" name="submit" value="Modifier"/>
			</form>
			</br>';
	}
}
?>
