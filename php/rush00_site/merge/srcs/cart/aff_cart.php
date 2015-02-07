<?php

//session_start();
//echo "test";
//print_r($_SESSION['cart']);
echo "
<TABLE BORDER='3'> 
  <CAPTION> Panier </CAPTION> 
    <TR> 
	 <TH><b> PRODUIT</b> </TH> 
	  <TH> <b>Quantite</b> </TH> 
	   <TH><b> Prix unitaire</b> </TH> 
	</TR> 
	"; 
				  if (isset($_SESSION['cart']))
				  {
					  $i = count($_SESSION['cart']['product']);
					  $j = 0;
					  $total = 0;
					  while ($j < $i)
					  {
						  if (isset($_SESSION['cart']['product'][$j]))
						  {
							echo "<tr>";
							echo "<TD>";
						  	echo $_SESSION['cart']['product'][$j];
							echo "</TD>";
							echo "<TD>";
		              		echo $_SESSION['cart']['qt'][$j];
							echo "</TD>";
							echo "<td>";
							echo $_SESSION['cart']['prix'][$j];
							echo "</td>";
							echo "</tr>";
							$total = $total + ($_SESSION['cart']['prix'][$j] * $_SESSION['cart']['qt'][$j]);
						  }
						  //				$_SESSION['cart']['qt'];
						  //$_SESSION['cart']['prix'];
						  $j++;
					  }
				  }
				  else
					  echo "panier vide";
echo "</TR>
	</TABLE>";
if ($_GET['calcul'])
	echo "<b>Total</b> = $total";
echo '<a href="./srcs/cart/cart_del_item.php"> Effacer le panier </a>';
echo '<a href="./index.php?panier=normal&calcul=normal"> Calculer </a>';
echo '<a href="./index.php?valid=normal"> Valider </a>';
?>
