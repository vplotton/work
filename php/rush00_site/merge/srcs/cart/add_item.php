<?php
session_start();
if(isset($_SESSION['cart']))
{
	echo $_GET['item'];
	//print_r($_SESSION['cart']['product'][0]);
	$pos = array_search($_GET['item'], $_SESSION['cart']['product']);
	if ($pos !==	false)
	{
		$_SESSION['cart']['qt'][$pos] += 1;
//		echo "qt = ";
		echo $_SESSION['cart']['qt'][$pos];
	}
	else
	{
//			echo "add new   ";
				array_push($_SESSION['cart']['product'], $_GET['item']);
//		$_SESSION['cart']['product'][] = $_GET['item'];
//		print_r($_SESSION['cart']['product']);
			array_push($_SESSION['cart']['prix'], $_GET['prix']);
//		$_SESSION['cart']['prix'][] = $_GET['prix'];
//		$_SESSION['cart']['qt'][] = '1';
		array_push($_SESSION['cart']['qt'], '1');
	}
}
else
	echo "error, vous n avez rien a faire la";
echo "<meta http-equiv='refresh' content='0;URL=../../index.php'>";
?>
