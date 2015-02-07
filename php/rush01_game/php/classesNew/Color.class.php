<?PHP
Class Color
{
	public static $verbose = False;
	public $red = 0;
	public $green = 0;
	public $blue = 0;

	public static function doc()
	{
		return file_get_contents('Color.doc.txt');
	}
	function __construct(array $kwargs)
	{
		if (array_key_exists('red', $kwargs))
			$this->red = $kwargs['red'];
		if (array_key_exists('green', $kwargs))
			$this->green = $kwargs['green'];
		if (array_key_exists('blue', $kwargs))
			$this->blue = $kwargs['blue'];
		if (array_key_exists('rgb', $kwargs))
		{
			$this->red = ($kwargs['rgb'] >> 16) & 0xFF;
			$this->green = ($kwargs['rgb'] >> 8) & 0xFF;
			$this->blue = $kwargs['rgb'] & 0xFF;
		}
		if (self::$verbose === True)
		{
			echo self::__tostring()." constructed.".PHP_EOL;
		}
	}
	function __destruct()
	{
		if (self::$verbose === True)
		{
			echo self::__tostring()." destructed.".PHP_EOL;
		}
	}
	public function __tostring()
	{
		$format = 'Color( red: %3d, green: %3d, blue: %3d )';
		$fred = ROUND($this->red);
		$fgreen = ROUND($this->green);
		$fblue = ROUND($this->blue);
		return sprintf($format, $fred, $fgreen, $fblue);
	}
	public function add(Color $rhs)
	{
		$col['red'] = $this->red + $rhs->red;
		$col['green'] = $this->green + $rhs->green;
		$col['blue'] = $this->blue + $rhs->blue;
		$new_color = new Color ($col);
		return ($new_color);
	}
	public function sub(Color $rhs)
	{
		$col['red'] = $this->red - $rhs->red;
		$col['green'] = $this->green - $rhs->green;
		$col['blue'] = $this->blue - $rhs->blue;
		$new_color = new Color ($col);
		return ($new_color);
	}
	public function mult($f)
	{
		$col['red'] = $this->red * $f;
		$col['green'] = $this->green * $f;
		$col['blue'] = $this->blue * $f;
		$new_color = new Color ($col);
		return ($new_color);
	}
}
?>
