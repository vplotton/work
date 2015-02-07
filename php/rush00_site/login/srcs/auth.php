<?PHP
function auth($login, $passwd)
{
	$hash = hash("whirlpool", $passwd);
	$file_name = "../private/passwd";
	$file = file_get_contents($file_name);
	$content = unserialize($file);
	foreach ($content as $value)
	{
		if ($value[login] == $login && $value[passwd] == $hash)
			return (TRUE);
	}
	return (FALSE);
}
?>
