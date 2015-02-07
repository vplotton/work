<?php
function rotateForReal($dir, $move)
{
	$ret = array ('x' => 0, 'y' => 0);
	$ret['x'] = ($dir == 0 || $dir == 1) ? 1 : -1;
	$ret['x'] = (($dir == 0 || $dir == 2) && $move == "left") ? $ret['x'] * -1 : $ret['x'];
	$ret['y'] = ($dir == 0 || $dir == 1) ? 1 : -1;
	$ret['y'] = (($dir == 1 || $dir == 3) && $move == "right") ? $ret['y'] * -1 : $ret['y'];
	return $ret;
}
trait Move
{
	public function rotate($area, $pos, $side) {
		$new_pos = new Vertex(array('x' => 0, 'y' => 0, 'dir' => 1));
//		$side_nw = ($pos->getDir() == "S" || $pos->getDir() == "W" ? 1 : -1);
//		$side_sw = ($pos->getDir() == "N" || $pos->getDir() == "W" ? 1 : -1);

		$rot = rotateForReal($pos->getnDir(), $side);
//		print_r($rot);
		$area1 = ($side == "right") ? ($area['y'] - $area['x']) / 2 : ($area['y'] + $area['x']) / 2;
		$new_pos->setX($pos->getX() + $rot['x'] * (($pos->getnDir() % 2 == 0) ? $area1 : $area['y'] / 2));
		$new_pos->setY($pos->getY() + $rot['y'] * (($pos->getnDir() % 2 == 1) ? $area1 : $area['y'] / 2));
		if ($side == 'left')
			$new_pos->setDir(($pos->getnDir() + 1) % 4);
		if ($side == 'right')
			$new_pos->setDir(($pos->getnDir() + 3) % 4);
/*
		if ($side == "left")
		{
			if ($pos->getnDir() < 4)
				$new_pos->setDir($pos->getnDir() + 1);
			else
				$new_pos->setDir(1);
			$new_pos->setX($pos->getX() + (($area['y'] / 2))
				* $side_nw);
			$new_pos->setY($pos->getY() + (($area['y'] / 2))
				* $side_sw);
		}
		else if ($side == "right")
		{
			if ($pos->getnDir() > 1)
				$new_pos->setDir($pos->getnDir() - 1);
			else
				$new_pos->setDir(4);
			$new_pos->setX($pos->getX() + (($area['y'] / 2))
				* $side_sw);
			$new_pos->setY($pos->getY() + (($area['y'] / 2))
				* $side_nw);
		}
		else
			return (NULL);
 */
		return ($new_pos);
	}
	public function move($pos, $side) {
		$new_pos = new Vertex(array('x' => $pos->getX(), 'y' => $pos->getY(), 'dir' => $pos->getDir()));
		$move = ($pos->getDir() == "S" || $pos->getDir() == "E" ? 1 : -1);
		if ($pos->getDir() == "N" || $pos->getDir() == "S")
			$new_pos->setY($pos->getY() + $move * $side);
		else
			$new_pos->setX($pos->getX() + $move * $side);
		return ($new_pos);
	}
}
?>
