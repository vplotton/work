<?php
class Square {
	private $_has_ship = False;
	private $_has_object = False;
	private $_pos;

	public function color($ship, $pos) {
		if ($ship->is_in($ship->getPos(), $pos, $ship->getArea()) === true)
			return ("id=\"ship-square\"");
		else
			return ("id=\"normal-square\"");
	}
}
?>
