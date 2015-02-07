<?PHP
if (!file_exists("private"))
	mkdir("private", 0777);
if (!file_exists("csv"))
	mkdir("products", 0777);
echo '<p>Definir admin</p>
	<form method="POST" action="srcs/login/create.php">
	Identifiant: admin
	</br>
	Mot de passe: <input type="password" name="passwd" value="" />
	<input type="submit" name="admin" value="OK" />
	</form>'
?>
