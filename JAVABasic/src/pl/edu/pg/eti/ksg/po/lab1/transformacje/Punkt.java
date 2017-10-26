package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Punkt {
	/*
	 * S�owo kluczowe final oznacza, �e po pierwszym przypisaniu 
	 * zawarto�� p�l x oraz y nie mo�e zosta� zmieniona 
	 * w tym miejscu jest to odpowiednik s�owa kluczowego const 
	 * z j�zyka C++.
	 */ 
	private final double x, y;

	public Punkt(double x, double y) {
		this.x = x;
		this.y = y;
	}

	public double getX() {
		return x;
	}

	public double getY() {
		return this.y;
	}

	@Override
	public boolean equals(Object obj) {
		if (obj instanceof Punkt) {
			Punkt other = (Punkt) obj;
			return x == other.x && y == other.y;
		}
		return false;
	}

	@Override
	public int hashCode() {
		int hash;
		hash = (59 * Double.hashCode(x) + 7) + (59 * Double.hashCode(y) + 7);
		return hash;
	}

	@Override public String toString() {
		return "Instancja klasy Punkt zawieraj�ca liczby " + x + " oraz " + y;
	}
	
	/**
	 * Pocz�tek uk�adu wsp�rz�dnych. 
	 * W tym miejscu s�owo kluczowe final oznacza, �e statyczne 
	 * pole klasy Punkt nie mo�e zosta� zmienione. 
	 * Dotyczy to jednak samej referencji, a nie obiektu, na kt�ry 
	 * wskazuje. 
	 */
	public static final Punkt O = new Punkt(0, 0); 
	/** * Punkt (1,0) w uk�adzie wsp�rz�dnych */
	public static final Punkt E_X = new Punkt(1, 0); 
	/** * Punkt (0,1) w uk�adzie wsp�rz�dnych */
	public static final Punkt E_Y = new Punkt(0, 1);
}