<?PHP
function print_products($order)
{
	$i = 0;
	$file = file_get_contents("./csv/produits.csv");
	$contents = unserialize($file);
	if ($order == "normal")
	{
		foreach ($contents as $value)
		{
				$id = $value['name'];
				$prix = $value['price'];
				$add_cart = "./srcs/cart/add_item.php?item=$id&prix=$prix";
			echo '<div class="contain_product">
				'.$value['name'].'</br>
				<img src="'.$value['url'].'" padding="5px" width="100px"></img>
				'.$value['dscpt'].'</br>
				<span class="price_img">Price: '.$value['price'].'</span>
				<a href= '.$add_cart.'> ajouter au panier</a>
				</div>';
			$i++;
		}
		echo '</div>';
	}
}
?>
