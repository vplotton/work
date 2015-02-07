<?php
class Square {
	private $_has_ship = False;
	private $_has_object = False;
	private $_pos;

	public function color(array $ships, $pos) {
		foreach ($ships as $ship)
		{
			$vert = $ship->getPos();
			if ($pos->getX() == $vert->getX() && $pos->getY() == $vert->getY())
				return ("id=\"barrier-square\"");
			if ($ship->is_in($ship->getPos(), $pos, $ship->getArea()) === true)
				return ("id=\"ship-square\"");
		}
		return ("id=\"normal-square\"");
	}
}
?>
