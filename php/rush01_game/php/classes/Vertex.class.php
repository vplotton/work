<?PHP
Class Vertex
{
	private $_x;
	private $_y;
	private $_dir;

	public function getX() { return $this->_x; }
	public function getY() { return $this->_y; }
	public function getDir() { return $this->_dir; }
	public function getnDir() {
		if ($this->_dir == "N")
			return (1);
		if ($this->_dir == "E")
			return (2);
		if ($this->_dir == "S")
			return (3);
		if ($this->_dir == "W")
			return (4);
	}
	public function setX($x) {
		if (!isset($x))
		{
			trigger_error($x."is a mandatory value", E_USER_ERROR);
			return ;
		}
		else	
			$this->_x = (int)$x;
	}
	public function setY($y) {
		if (!isset($y))
		{
			trigger_error($y."is a mandatory value", E_USER_ERROR);
			return ;
		}
		else
			$this->_y = (int)$y;
	}
	public function setDir($dir) {
		if (isset($dir))
		{
			if ($dir == 1)
				$dir = "N";
			if ($dir == 2)
				$dir = "E";
			if ($dir == 3)
				$dir = "S";
			if ($dir == 4)
				$dir = "W";
			$this->_dir = $dir;
		}
	}
	public static function doc() {
		return file_get_contents('Vertex.doc.txt');
	}
	function __construct(array $kwargs)
	{
		if (isset($kwargs['x']))
			$this->setX($kwargs['x']);
		if (isset($kwargs['y']))
			$this->setY($kwargs['y']);
		if (isset($kwargs['dir']))
			$this->setDir($kwargs['dir']);
	}
	function __destruct() {
	}
}
?>
