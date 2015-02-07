<?PHP

function rotate($dir, $move)
{
	$ret = array ('x' => 0, 'y' => 0);
	$ret['x'] = ($dir == 1 || $dir == 2) ? 1 : -1;
	$ret['x'] = (($dir == 1 || $dir == 3) && $move == 'left') ? $ret['x'] * -1 : $sing1;
	$ret['y'] = ($dir == 1 || $dir == 2) ? 1 : -1;
	$ret['y'] = (($dir == 2 || $dir == 4) && $move == 'right') ? $ret['y'] * -1 : $sing1;
	return $ret;
}

trait move
{
	private $_moves;
	private $_ok_turn;

	public function move($move)
	{
		if ($this->_moves >= $this->speed)
		{
			//can't move
			return ;
		}
		if ((($move == 'left' || $move == 'right')
		{
			if (($this->static && $_moves == 0) || ($this->_ok_turn > $this->manu))
			{
				$this->_ok_turn = 0;
				$rot = rotate($this->face, $move);
				$this->pos['x'] = $rot['x'] * ($this->size['len'] - 1) / 2;
				$this->pos['y'] = $rot['y'] * ($this->size['len'] - 1) / 2;
				if ($move == 'left')
					$this->face = ($this->face + 1) % 4;
				if ($move == 'right')
					$this->face = ($this->face + 3) % 4;
			}
			else
			{
				//can't turn;
				return ;
			}
		}
		else
		{
			$sign = ($this->face == 'up' || $this->face == 'right' ? 1 : -1);
			$dir = ($move == 'up' ? 1 : -1);
			$pos['x'] = (($this->face == 'left' || $this->face == 'right') ? $this->pos['x'] + $dir * $sign : $this->pos['x'];
			$pos['y'] = (($this->face == 'up' || $this->face == 'down') ? $this->pos['y'] + $dir * $sign : $this->pos['y'];
			$this->_moves++;
			$this->_ok_turn++;
		}
	}
}
?>
