<?php
	session_start();
	if (isset($_SESSION['cart']))
	{
		$i = count($_SESSION['cart']['product']);
		echo $i;
		echo "tt";
		$j = 0;
		while ($j < $i)
		{
			unset($_SESSION['cart']['product'][$j]);
			unset($_SESSION['cart']['prix'][$j]);
			unset($_SESSION['cart']['qt'][$j]);
			$j++;
			echo "$j";
		}
	}

 echo "<meta http-equiv='refresh' content='0;URL=../../index.php'>";
?>
