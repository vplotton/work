<?php
require_once('Move.class.php');
require_once('Shoot.class.php');
require_once('Area.class.php');
class Ship {
	private $_id;
	private $_pos;
	private $_name;
	private $_excerpt;
	private $_weapons;
	private $_pp = 10;
	private $_area;
	private $_life = 8;
	private $_shield = 0;
	private $_speed = 14;
	private $_is_alive = true;

	use Move;
	use Shoot;
	use	Area;
	public function getId() {
		return($this->_id);
	}
	public function getPos() {
		return($this->_pos);
	}
	public function getName() {
		return($this->_name);
	}
	public function getArea() {
		return($this->_area);
	}
	public function getExcerpt() {
		return($this->_excerpt);
	}
	public function getWeapons() {
		return($this->_weapons);
	}
	public function setId($id) {
		if (isset($id))
			$this->_id = $id;
	}
	public function setPos($pos) {
		if (isset($pos))
			$this->_pos = $pos;
	}
	public function setName($name) {
		if (isset($name))
			$this->_name = $name;
	}
	public function setArea($area) {
		if (isset($area))
			$this->_area = $area;
	}
	public function setExcerpt($excerpt) {
		if (isset($excerpt))
			$this->_excerpt = $excerpt;
	}
	public function setWeapons($weapons) {
		if (isset($weapons))
			$this->_weapons = $weapons;
	}
	public static function doc() {
	}
	public function __construct($kwargs) {
		if ($kwargs['id'])
			$this->setId($kwargs['id']);
		if ($kwargs['pos'])
			$this->setPos($kwargs['pos']);
		if ($kwargs['name'])
			$this->setName($kwargs['name']);
		if ($kwargs['area'])
			$this->setArea($kwargs['area']);
		return ;
	}
	public function __destruct() {
		return ;
	}
}
?>
