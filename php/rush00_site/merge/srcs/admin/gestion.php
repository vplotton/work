<?PHP
session_start();
	echo '<div id = "left3">
		<ul>
		<li id = "title">Gestion</li>
		<li>
		<a href="./index.php?modif=account">Compte</a>
		</li>';
if (isset ($_SESSION['loggued_on_user']) && $_SESSION['loggued_on_user'] == "admin")
{
	echo'<li>
		<a href="./index.php?modif=accounts">Utilisateurs</a>
		</li>
		<li>
		<a href="./index.php?modif=category">Categories</a>
		</li>
		<li>
		<a href="./index.php?modif=products">Produits</a>
		</li>';
}
echo '</ul></div>';
?>
