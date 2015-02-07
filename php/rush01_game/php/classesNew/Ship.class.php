<?PHP

Interface IShip
{
	use move;
	public $speed;
	public $shield;
	public $PV;
	public $PP;
	public $manu;
	public $weapons;
	public $pos;
	public $face;
	public $active = FALSE;
	public $static = TRUE;

	public function end_turn()
	{
		//		reinit speed, shield, pp;
		//		propre a la classe
	}
?>
