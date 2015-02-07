<?php
include("admin_functions.php");
if (file_exists("../csv/categories.csv") !== FALSE)
{
	$file = file_get_contents("../csv/categories.csv");
	$content_cat = unserialize($file);
}
else
	$content_cat = array();
if (isset($_POST) !== FALSE && isset($_POST['cat_new_nom']) === TRUE)
{
	$cat_name = trim($_POST['cat_new_nom']);
	if (strlen($cat_name) > 0)
	{
		if (ft_in_cat_array($cat_name, $content_cat) === FALSE)
		{
			$category = array();
			$category['name'] = $cat_name;
			$tab = explode("\n", $_POST['cat_new_produits']);
			foreach($tab as $etab)
			{
				$etab = trim($etab);
				if (is_string($etab) && strlen($etab) > 0)
					$category['products'][] = $etab;
			}
			$content_cat[] = $category;
			$file = serialize($content_cat);
			file_put_contents("../csv/categories.csv", $file);
			ft_confirm("La catégorie a bien été ajoutée");
		}
		else
			ft_warning("Une categorie porte deja ce nom");
	}
	else
		ft_warning("Donnez un nom a la categorie");
}

if (isset($_POST) !== FALSE && isset($_POST['cat_mod_nom']) === TRUE)
{
	for($i = 0; $i < count($content_cat) && $content_cat[$i]['name'] !== $_POST['cat_mod_nom']; $i++)
		;
	if ($i < count($content_cat) && $content_cat[$i]['name'] === $_POST['cat_mod_nom'])
	{
		$tab = explode("\n", $_POST['cat_mod_produits']);
		$content_cat[$i]['products'] = array();
		foreach($tab as $etab)
		{
			$etab = trim($etab);
			if (is_string($etab) && strlen($etab) > 0)
				$content_cat[$i]['products'][] = $etab;
		}
		$file = serialize($content_cat);
		file_put_contents("../csv/categories.csv", $file);
		ft_confirm("La catégorie a bien été modifiée");
	}
}

if (isset($_POST) !== FALSE && isset($_POST['cat_del_nom']) === TRUE)
{
	for($i = 0; $i < count($content_cat) && $content_cat[$i]['name'] !== $_POST['cat_del_nom']; $i++)
		;
	if ($i < count($content_cat) && $content_cat[$i]['name'] === $_POST['cat_del_nom'])
	{
		array_splice($content_cat, $i, 1);
		$file = serialize($content_cat);
		file_put_contents("../csv/categories.csv", $file);
		ft_confirm("La catégorie a bien été supprimée");
	}
}

if (file_exists("../csv/produits.csv") !== FALSE)
{
	$file = file_get_contents("../csv/produits.csv");
	$content_prod = unserialize($file);
}
else
	$content_prod = array();
if (isset($_POST) !== FALSE && isset($_POST['prod_new_name']) === TRUE)
{
	$prod_name = trim($_POST['prod_new_name']);
	if (strlen($prod_name) > 0)
	{
		if (ft_in_prod_array($prod_name, $content_prod) === FALSE)
		{
			$product = array();
			$product['name'] = $prod_name;
			$product['amount'] = $_POST['prod_new_amount'];
			$product['price'] = $_POST['prod_new_price'];
			$product['url'] = $_POST['prod_new_url'];
			$product['dscpt'] = $_POST['prod_new_dscpt'];
			$content_prod[] = $product;
			$file = serialize($content_prod);
			file_put_contents("../csv/produits.csv", $file);
			ft_confirm("Le produit a bien été ajouté");
		}
		else
			ft_warning("Un produit porte deja ce nom");
	}
	else
		ft_warning("Donnez un nom au produit");
}
if (isset($_POST) !== FALSE && isset($_POST['prod_mod']) === TRUE)
{
	for($i = 0; $i < count($content_prod) && $content_prod[$i]['name'] !== $_POST['prod_mod_nom']; $i++)
		;
	if ($i < count($content_prod) && $content_prod[$i]['name'] === $_POST['prod_mod_nom'])
	{
		$product = array();
		$product['name'] = $_POST['prod_mod_nom'];
		$product['amount'] = $_POST['prod_new_amount'];
		$product['price'] = $_POST['prod_new_price'];
		$product['url'] = $_POST['prod_new_url'];
		$product['dscpt'] = $_POST['prod_new_dscpt'];
		$content_prod[$i] = $product;
		$file = serialize($content_prod);
		file_put_contents("../csv/produits.csv", $file);
		ft_confirm("Le produit a bien été modifié");
	}
}

if (isset($_POST) !== FALSE && isset($_POST['prod_del_nom']) === TRUE)
{
	for($i = 0; $i < count($content_prod) && $content_prod[$i]['name'] !== $_POST['prod_del_nom']; $i++)
		;
	if ($i < count($content_prod) && $content_prod[$i]['name'] === $_POST['prod_del_nom'])
	{
		array_splice($content_prod, $i, 1);
		$file = serialize($content_prod);
		file_put_contents("../csv/produits.csv", $file);
		ft_confirm("Le produit a bien été supprimé");
	}
}
?>
