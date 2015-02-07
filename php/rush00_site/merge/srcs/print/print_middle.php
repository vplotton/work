<?PHP
include ('print_category.php');
include ('print_products.php');
if (!isset($_SESSION['cart']))
{
	   $_SESSION['cart'] = array();
	      $_SESSION['cart']['product'] = array();
	        $_SESSION['cart']['prix'] = array();
	      $_SESSION['cart']['qt'] = array();
}
if (isset($_GET['categorie']) && $_GET['category'])
	print_category($_GET['category']);
else if (isset($_GET['products']) && $_GET['products'])
	print_products($_GET['products']);
else if (isset ($_GET['modif']) && $_GET['modif'] == "category" && $_SESSION['loggued_on_user'] == "admin")
	header("Location: ./srcs/admin/administration.php");
else if (isset ($_GET['modif']) && $_GET['modif'] == "products" && $_SESSION['loggued_on_user'] == "admin")
	modif_products();
else if (isset ($_GET['modif']) && $_GET['modif'] == "accounts" && $_SESSION['loggued_on_user'] == "admin")
	include ('./srcs/admin/admin_users.php');
else if (isset ($_GET['contact']) && $_GET['contact'] == "normal")
	include ('./srcs/contact.php');
 else if (isset ($_GET['panier']) && $_GET['panier'] == "normal")
    include ('./srcs/cart/aff_cart.php');
?>
