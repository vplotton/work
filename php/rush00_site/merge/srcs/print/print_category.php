<?PHP
function print_category($order)
{
	$i = 0;
	$file = file_get_contents("../../csv/categories.csv");
	$contents = unserialize($file);
	if ($order == "normal")
	{
		foreach ($contents as $value)
		{
			echo '<div class="contain_category">'.$value['name'];
			foreach ($value['products'] as $val)
			{
				echo '<div class="contain_product">'.$val.'</div>';
				$i++;
			}
			echo '</div>';
		}
	}
}
?>
