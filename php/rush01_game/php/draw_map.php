<?php
require_once('classes/Ship.class.php');
require_once('classes/Square.class.php');
require_once('classes/Vertex.class.php');
require_once('classes/Area.class.php');
$pos = new Vertex(array('x' => 0, 'y' => 0));
$ship = new Ship(array('id' => 0
	, 'pos' => new Vertex(array('x' => 80, 'y' => 80, 'dir' => "W"))
	, 'name' => "baltazar el dominante"
	, 'area' => array('x' => 3, 'y' => '6')
));
$ship->setPos($ship->rotate($ship->getArea(), $ship->getPos(), "right"));
$y = 0;
while ($y < 100)
{
	$x = 0;
	echo "<div id=\"line\">";
	while ($x < 150)
	{
		$pos->setX($x);
		$pos->setY($y);
		$square = new Square();
		if ($x == 149 || $x == 0 || ($x == 80 && $y == 80))
			echo "<div id=\"barrier-square\"></div>";
		else
			echo "<div ".$square->color($ship, $pos)."></div>";
		$x++;
	}
	echo "</div>";
	$y++;
}
?>
