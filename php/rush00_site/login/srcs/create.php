<?PHP
function ft_create($login, $passwd, $is_admin)
{
	$content = array();
	$error = FALSE;
	$path = "../private";
	$file_name = "/passwd";
	if (file_exists($path) == FALSE)
		mkdir($path, 0777);
	else
	{
		$file = file_get_contents($path.$file_name);
		if (($content = unserialize($file)) != FALSE)
		{
			foreach ($content as $value)
			{
				if ($value[login] === $login)
				{
					echo "<p>Account already created</p>";
					$error = TRUE;
				}
			}
		}
	}
	if ($error == TRUE)
	{
		echo "Creation of your account failed\n";
		return (FALSE);
	}
	else
	{
		$add_to_file[login] = $login;
		$add_to_file[passwd] = $passwd;
		$add_to_file[is_admin] = $is_admin;
		$content[] = $add_to_file;
		$file = serialize($content);
		file_put_contents($path.$file_name, $file);
		echo "Account creation successfull";
		return (TRUE);
	}
}
session_start();
if ($_POST[submit] == "OK" && $_POST[passwd] != NULL && $_POST[login] != NULL)
{
	$hash = hash("whirlpool", $_POST[passwd]);
	if (ft_create($_POST[login], $hash, 0) == TRUE)
	{
		$wait = 1;
		$_SESSION['loggued_on_user'] = $_POST[login];
	}
	else
		$wait = 2;
	echo '<meta http-equiv="refresh" content="$wait;URL=../index.php">';
}
else if ($_POST[admin] == "OK" && $_POST[passwd] != NULL)
{
	$hash = hash("whirlpool", $_POST[passwd]);
	if (ft_create("admin", $hash, 1) == TRUE)
	{
		$_SESSION['loggued_on_user'] = "admin";
		echo '<meta http-equiv="refresh" content="1;URL=../index.php">';
	}
	else
		echo '<meta http-equiv="refresh" content="2;URL=../install.php">';
}
?>
