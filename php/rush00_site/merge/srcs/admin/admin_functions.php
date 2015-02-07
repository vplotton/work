<?php

function ft_in_cat_array($s, $content)
{
	if (!empty($content))
		foreach($content as $category)
		{
			if ($category['name'] === $s)
				return (TRUE);
		}
	return (FALSE);
}

function ft_in_prod_array($s, $content)
{
	if (!empty($content))
		foreach($content as $prod)
		{
			if ($prod['name'] === $s)
				return (TRUE);
		}
	return (FALSE);
}

function ft_name_cat($content)
{
	if (!empty($content))
		foreach($content as $category)
		{
			echo '<option value="'.$category['name'].'">'.$category['name'].'</option>';
		}
}

function ft_select_prod($content)
{
	if (!empty($content))
		foreach($content as $prod)
		{
			echo '<option value="'.$prod['name'].'">'.$prod['name'].'</option>';
		}
}

function ft_warning($s)
{echo '<div style="background-color: red; color: white">'.$s.'</div>'; }

function ft_confirm($s)
{echo '<div style="background-color: green; color: white">'.$s.'</div>';}

function ft_add_cat($name, $products)
{
	$file = file_get_contents("../../csv/categories.csv");
	$content_cat = unserialize($file);
	if (empty($content_cat))
		$content_cat = array();
	$category = array();
	$category['name'] = $name;
	$category['products'] = $products;
	$content_cat[] = $category;
	$file = serialize($content_cat);
	file_put_contents("../../csv/categories.csv", $file);
}
?>
