<?PHP
function remove_user($login)
{
	$index = 0;
	$file = file_get_contents("./srcs/private/passwd");
	$content = unserialize($file);
	if (isset($content) && isset($login))
	{
		foreach ($content as $value)
		{
			if ($value['login'] == $login)
				break ;
			$index++;
		}
		if ($index !== FALSE)
			unset($content[$index]);
		$content = array_merge($content);
		$file = serialize($content);
		file_put_contents("./srcs/private/passwd", $file);
	}
}
?>
