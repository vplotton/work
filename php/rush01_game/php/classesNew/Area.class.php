<?php
trait Area {
	public function is_in($pos, $curr_pos, $area) {
		if ($pos->getDir() === "N")
		{
			if ($curr_pos->getX() < $area['x'] + $pos->getX()
				&& $curr_pos->getX() >= $pos->getX()
				&& $curr_pos->getY() < $area['y'] + $pos->getY()
				&& $curr_pos->getY() >= $pos->getY())
				return (true);
		}
		else if ($pos->getDir() === "S")
		{
			if ($curr_pos->getX() > -$area['x'] + $pos->getX()
				&& $curr_pos->getX() <= $pos->getX()
				&& $curr_pos->getY() > -$area['y'] + $pos->getY()
				&& $curr_pos->getY() <= $pos->getY())
				return (true);
		}

		else if ($pos->getDir() === "W")
		{
			if ($curr_pos->getX() < $area['y'] + $pos->getX()
				&& $curr_pos->getX() >= $pos->getX()
				&& $curr_pos->getY() > -$area['x'] + $pos->getY()
				&& $curr_pos->getY() <= $pos->getY())
				return (true);
		}
		else if ($pos->getDir() === "E")
		{
			if ($curr_pos->getX() > -$area['y'] + $pos->getX()
				&& $curr_pos->getX() <= $pos->getX()
				&& $curr_pos->getY() < $area['x'] + $pos->getY()
				&& $curr_pos->getY() >= $pos->getY())
				return (true);
		}
		return (false);
	}
}
?>
