<?php
session_start();
 if(isset($_SESSION['cart']))
 {
    $pos = array_search($_GET['item'], $_SESSION['cart']['product']);
     if (isset($pos) != FALSE)
	 {
		 if ($_SESSION['cart']['qt'][$pos] > 0)
		 	$_SESSION['cart']['qt'][$pos] -= 1;
    }
    echo "<meta http-equiv='refresh' content='0;URL=aff_cart.php'>";
?>
