<?PHP
session_start();
$error = TRUE;
if ($_SESSION['loggued_on_user'])
{
	$file_name = "../../private/passwd";
	$file = file_get_contents($file_name);
	$content = unserialize($file);
	foreach ($content as $value)
	{
		if ($value[login] == $_SESSION['loggued_on_user'])
		{
			$error = FALSE;
			echo $_SESSION['loggued_on_user']."\n";
		}
	}
}
if ($error == TRUE)
	echo "ERROR\n";
echo '<meta http-equiv="refresh" content="1;URL=../../index.php">';
?>
