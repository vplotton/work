<?php
session_start();
//session_destroy();
?>
<HTML>
<HEAD>
<link href="rush.css" rel="stylesheet" type="text/css" />
<meta http-equiv="content-type" content="text/html; charset=ISO-8859-1" />
</HEAD>
<BODY>
</br>
<br />


<?php
//session_start();
if (!isset($_SESSION['cart']))
{
   $_SESSION['cart'] = array();
   $_SESSION['cart']['product'] = array();
     $_SESSION['cart']['prix'] = array();
   $_SESSION['cart']['qt'] = array();
}
//cete include doit etre dans index
//include("session_cart_start.php");
// recup des csv le nombre de prod de la cat
$i = 0;
while ( $i < 3)
{
	include("item_display.php");
	$i++;
}
echo "debug";
print_r($_SESSION['cart']['product']);
print_r($_SESSION['cart']['prix']);
print_r($_SESSION['cart']['qt']);
?>
</body>
</html>
