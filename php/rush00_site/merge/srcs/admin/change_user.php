<?PHP
$i = 0;
$hash = hash('whirlpool', $_POST['passwd']);
$file = file_get_contents("../private/passwd");
$content = unserialize($file);
foreach ($content as $value)
{
	if ($_GET['login'] == $value['login'])
		$content[$i]['passwd'] = $hash;
	$i++;
}
$file = serialize($content);
file_put_contents("../private/passwd", $file);
header("Location: ../../index.php?modif=accounts");
?>
