<?php
function ft_dec($name_prod, $how_much)
{
	$file = file_get_contents("../csv/produits.csv");
	$content_prod = unserialize($file);
	if (!empty($content_prod))
	{
		for($i = 0; $i < count($content_prod) && $content_prod[$i]['name'] !== $name_prod; $i++)
			;
		if ($i < count($content_prod) && $content_prod[$i]['name'] === $name_prod)
		{
			$amount = $content_prod[$i]['amount'];
			$content_prod[$i]['amount'] = $amount - $how_much;
			if ($content_prod[$i]['amount'] < 0)
				$content_prod[$i]['amount'] = 0;
			$file = serialize($content_prod);
			file_put_contents("../csv/produits.csv", $file);
		}
	}
}
?>
