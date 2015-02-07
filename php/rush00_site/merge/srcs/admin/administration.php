<html>
<head>
<meta charset="utf-8" />
<link rel="stylesheet" href="admin.css" />
</head>
</body>
<?php
include("admin_functions.php");
include("admin_post.php");
?>

<h1>Administration du site</h1>
	<h2>Catégories</h2>
	<h3>Liste des catégories</h3>
	<table>
<?php
if (!empty($content_cat))
	foreach($content_cat as $elem)
	{
		echo "<tr>";
		echo '<td id="tab_head">'.$elem['name']."</td>";
		if (!empty($elem['products']) && is_array($elem['products']))
			foreach ($elem['products'] as $products)
				echo "<td>".$products."</td>";
		echo "</tr>";
	}
?>
	</table>

	<h3>Ajouter une catégorie</h2>
	<form method="post" action="administration.php"><p>
	Nom de la catégorie: <input type="text" name="cat_new_nom" min="1"/><br />
	Liste des produits associés à la catégorie:<br />Listez les produits séparés par des sauts de ligne<br />
	<textarea name="cat_new_produits" /></textarea><br />
	<input type="submit" name="cat_new" value="Envoyer"/><br />
	</p></form>

	<h3>Modifier catégorie</h2>
	<form method="post" action="administration.php"><p>
	Nom de la catégorie:
	<select name="cat_mod_nom"/><?php ft_name_cat($content_cat) ?></select><br />
	Liste des produits associés à la catégorie:<br />Listez les produits séparés par des sauts de ligne<br />
	<textarea name="cat_mod_produits" /></textarea><br />
	<input type="submit" name="cat_mod" value="Envoyer"/><br />
	</p></form>

	<h3>Supprimer une catégorie</h2>
		<form method="post" action="administration.php"><p>
		Nom de la catégorie:
		<select name="cat_del_nom"/><?php ft_name_cat($content_cat) ?></select>
		<input type="submit" name="cat_del" value="Supprimer"/><br />
		</p></form>

	<h2>Produits</h2>
	<h3>Liste des produits</h3>
	<table>
<?php
?>
	<tr id="tab_head">
	<td>Nom du produit</td>
	<td>Quantite restante</td>
	<td>Prix</td>
	<td>URL de l'image</td>
	<td>Description</td>
	</tr>
<?php
if (!empty($content_prod))
	foreach($content_prod as $line_prod)
	{
		echo "<tr>";
		echo "<td>".$line_prod['name']."</td>";
		echo "<td>".$line_prod['amount']."</td>";
		echo "<td>".$line_prod['price']."</td>";
		echo "<td>".$line_prod['url']."</td>";
		echo "<td>".$line_prod['dscpt']."</td>";
		echo "</tr>";
	}
?>
</table>
<h3>Ajouter un produits</h3>
<form method="post" action="administration.php">
<table>
	<tr id="tab_head">
	<td>Nom du produit</td>
	<td>Quantite restante</td>
	<td>Prix</td>
	<td>URL de l'image</td>
	<td>Description</td>
	<td></td>
	</tr>
	<tr id="tab_head">
	<td><input type="texte" name="prod_new_name" min="1"/></td>
	<td><input type="number" min="0" name="prod_new_amount"</td>
	<td><input type="number" min="0" name="prod_new_price"</td>
	<td><input type="texte" name="prod_new_url"/></td>
	<td><textarea name="prod_new_dscpt" /></textarea></td>
	<td><input type="submit" name="prod_new" value="Ajouter"</td>
	</tr>
</table>
</form>
<h3>Modifier un produits</h3>
<form method="post" action="administration.php">
<table>
	<tr id="tab_head">
	<td>Nom du produit</td>
	<td>Quantite restante</td>
	<td>Prix</td>
	<td>URL de l'image</td>
	<td>Description</td>
	<td></td>
	</tr>
	<tr id="tab_head">
	<td><select name="prod_mod_nom"/><?php ft_select_prod($content_prod) ?></select><br /></td>
	<td><input type="number" min="0" name="prod_new_amount"</td>
	<td><input type="number" min="0" name="prod_new_price"</td>
	<td><input type="texte" name="prod_new_url"/></td>
	<td><textarea name="prod_new_dscpt" /></textarea></td>
	<td><input type="submit" name="prod_mod" value="Modifier"</td>
	</tr>
</table>
</form>
<h3>Supprimer un produits</h3>
	<form method="post" action="administration.php"><p>
		Supprimer un produit:
		<select name="prod_del_nom"/><?php ft_select_prod($content_prod) ?></select>
		<input type="submit" name="prod_del" value="Supprimer"/><br />
	</p></form>
<a href="../../index.php")>Retourner a la page d'acceuil</a>
</body>
</html>
