package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Punkt {
	/*
	 * S³owo kluczowe final oznacza, ¿e po pierwszym przypisaniu 
	 * zawartoœæ pól x oraz y nie mo¿e zostaæ zmieniona 
	 * w tym miejscu jest to odpowiednik s³owa kluczowego const 
	 * z jêzyka C++.
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
		return "Instancja klasy Punkt zawieraj¹ca liczby " + x + " oraz " + y;
	}
	
	/**
	 * Pocz¹tek uk³adu wspó³rzêdnych. 
	 * W tym miejscu s³owo kluczowe final oznacza, ¿e statyczne 
	 * pole klasy Punkt nie mo¿e zostaæ zmienione. 
	 * Dotyczy to jednak samej referencji, a nie obiektu, na który 
	 * wskazuje. 
	 */
	public static final Punkt O = new Punkt(0, 0); 
	/** * Punkt (1,0) w uk³adzie wspó³rzêdnych */
	public static final Punkt E_X = new Punkt(1, 0); 
	/** * Punkt (0,1) w uk³adzie wspó³rzêdnych */
	public static final Punkt E_Y = new Punkt(0, 1);
}