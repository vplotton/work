<?PHP
if ($_POST[submit] == "OK" && $_POST[newpw] != NULL)
{
	$i = 0;
	$content = array();
	$error = TRUE;
	$hasholdpw = hash("whirlpool", $_POST[oldpw]);
	$hashnewpw = hash("whirlpool", $_POST[newpw]);
	$file = file_get_contents("../private/passwd");
	$content = unserialize($file);
	foreach ($content as $value)
	{
		if ($value[login] == $_POST[login])
		{
			if ($value[passwd] == $hasholdpw && $value[passwd] != $hashnewpw)
			{
				$content[$i][passwd] = $hashnewpw;
				$error = FALSE;
			}
			break ;
		}
		$i++;
	}
	if ($error == TRUE)
		echo "ERROR\n";
	else
	{
		$file = serialize($content);
		file_put_contents("../private/passwd", $file);
		echo "OK\n";
	}
}
else
	echo "ERROR\n";
?>
