<?php
//session_start();
// a faire avec des var chope dans le csv

//$id = $_GET[product];
$item = "pates";
$id = "ROUBLE";
$designation = "texte a prendre dans un csv";
$img = "img/lessive_vegan_magnolia_lily_600ml-v.jpg";
$prix = "33";
$add_cart = "add_item.php?item=$id&prix=$prix";
echo 
	"
	<div id = 'test'>
	<b style = text-align : center>$id </b>
		<img src = $img width = 100px height = 100px align = left>
	<p>
		$designation
	</p>
	<br/>
	Prix = $prix
	<br/>
		<a href= $add_cart> ajouter au panier</a>
			</div>";
	?>
