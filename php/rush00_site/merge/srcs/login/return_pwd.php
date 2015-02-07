<?PHP
function return_pwd($login)
{
	$file_name = "../../private/passwd";
	$file = file_get_contents($file_name);
	$content = unserialize($file);
	foreach ($content as $value)
	{
		if ($value[login] == $login)
		{
			$crypt	= mcrypt_encrypt(MCRYPT_RIJNDAEL_128, "admin"
				, $value[passw], MCRYPT_MODE_NOFB);
			return ($crypt);
		}
	}
	return (NULL);
}
?>
