<?PHP
class Jet implements IShip
{
	public function __create($name, array $pos)
	{
		$this->name = $name;
		$this->speed = 15;
		$this->shield = 0;
		$this->PP = 10;
		$this->PV = 5;
		$this->manu = 4;
		$this->pos['x'] = $pos['x'];
		$this->face = $pos['face'];
	}
//	public function fire()
//	{
//		if ($this->face == 1)
//			return (array('origin' = $this->pos, 'dir' = 'up'));
//		if ($this->face == 2)
//			return (array('origin' = $this->pos, 'dir' = 'left'));
//		if ($this->face == 3)
//			return (array('origin' = $this->pos, 'dir' = 'down'));
//		if ($this->face == 4)
//			return (array('origin' = $this->pos, 'dir' = 'right'));
//	}
	public function end_turn()
	{
		$this->speed = 15;
		$this->shield = 0;
		$this->PP = 10;
		$this->moves = 0;
		$this->ok_turn = 0;
	}
}
?>
