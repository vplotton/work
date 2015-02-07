<?PHP
function get_value_category($category, $search)
{
	$file = file_get_contents("../csv/categories.csv");
	$content = unserialize($file);
	foreach ($content as $value)
	{
		if ($value[category] == $category)
			return ($value[$search]);
	}
	return (NULL);
}
function get_value_product($product, $search)
{
	$file = file_get_contents("../csv/produits.csv");
	$content = unserialize($content);
	foreach ($content as $key=>$value)
	{
		if ($value[product] == $product)
			return ($value[$search]);
	}
	return (NULL);
}
?>
