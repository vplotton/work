<?php

session_start();
echo "test";
if (isset($_SESSION['cart']))
{
	$i = 0;
	echo "tttpt";
	
	foreach ($_SESSION['cart']['product'] as $value)
	{
		echo $_SESSION['cart']['product'][$i];
//				$_SESSION['cart']['qt'];
		//$_SESSION['cart']['prix'];
		$i++;
	}
}
else
	echo "panier vide";
?>
