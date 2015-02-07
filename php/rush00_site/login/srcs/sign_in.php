<?PHP
include 'front.html';
?>
			<form class="log" method="POST" action="create.php">
				<input type="text" name="login" value="identifiant<?PHP echo $_SESSION['login'] ?>" /> 
				<input type="password" name="passwd" value="mot de passe<?PHP echo $_SESSION['password'] ?>" />
				<input type="submit" name="submit" value="OK"/>
			</form>
	</body>
</html>
