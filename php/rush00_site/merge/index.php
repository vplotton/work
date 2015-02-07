<html>
<head>
<link href="rush.css" rel="stylesheet" type="text/css" />
<meta http-equiv="content-type" content="text/html" charset ="utf-8" />
</HEAD>
<BODY>
	<div id = "conteneur">
		<div id = "head">
			<div id = "right">
				<?PHP include("./srcs/login/session_log.php");?>
			</div>
			<a href="./index.php">
				<img class="banner" id="tornado" src="../Sanstitre.png">
			</a>
		</div>
		<div id = "cont_centre">
			<div id = "left_main">
				<div id = "left1">
					<ul>
						<li id = "title"><a href= "./index.php?panier=normal">Panier</a></li>
					</ul>
				<?PHP include("./srcs/print/print_panier.php");?>
				</div>
				<div id = "left2">
					<ul>
						<li id = "title">Commerce</li>
						<li><a href="./index.php?products=normal">Produits</a></li>
						<li><a href="./index.php?category=normal">Categories</a></li>
						<li><a href="#3">A propos</a></li>
						<li><a href="./index.php?contact=normal">Contact</a></li>
					</ul>
				</div>
				<?PHP include("./srcs/admin/gestion.php");?>
			</div>
			<div id = "center">
				<?PHP include("./srcs/print/print_middle.php");?>
			</div>
		</div>
	</div>
</body>
</html>
