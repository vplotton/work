<?php
trait Move
{
	public function rotate($area, $pos, $side) {
		$new_pos = new Vertex(array('x' => 0, 'y' => 0, 'dir' => 1));
		$side_nw = ($pos->getDir() == "S" || $pos->getDir() == "W" ? 1 : -1);
		$side_sw = ($pos->getDir() == "N" || $pos->getDir() == "W" ? 1 : -1);
		if ($side == "left")
		{
			if ($pos->getnDir() > 1)
				$new_pos->setDir($pos->getnDir() - 1);
			else
				$new_pos->setDir(4);
			$new_pos->setX($pos->getX() + (($area['y'] / 2))
				* $side_nw);
			$new_pos->setY($pos->getY() + (($area['y'] / 2))
				* $side_sw);
		}
		else if ($side == "right")
		{
			if ($pos->getnDir() < 4)
				$new_pos->setDir($pos->getnDir() + 1);
			else
				$new_pos->setDir(1);
			$new_pos->setX($pos->getX() + (($area['y'] / 2))
				* $side_sw);
			$new_pos->setY($pos->getY() - (($area['y'] / 2))
				* $side_nw);
		}
		else
			return (NULL);
		return ($new_pos);
	}
	public function move($pos, $side) {
		$new_pos = new Vertex(array('x' => 0, 'y' => 0, 'dir' => 1));
		$move = ($pos->getDir() == "N" || $pos->getDir() == "E" ? 1 : -1);
		if ($pos->getDir() == "N" || $pos->getDir() == "S")
			$new_pos->setY($pos->getY() + $move);
		else
			$new_pos->setX($pos->getX() + $move);
		return ($new_pos);
	}
}
?>
