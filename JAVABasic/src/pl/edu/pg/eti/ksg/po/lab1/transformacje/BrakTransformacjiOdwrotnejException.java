package pl.edu.pg.eti.ksg.po.lab1.transformacje;

/* * Klasa ta jawnie dziedziczy po klasie java.lang.Exception */
public class BrakTransformacjiOdwrotnejException extends Exception {
	/*
	 * Klasa ta jawnie dziedziczy po klasie java.lang.Exception
	 */
	public BrakTransformacjiOdwrotnejException() {
		// Niejawne wywo�anie konstruktora klasy nadrz�dnej
		// super();
	}

	/*
	 * Konstruktor przyjmuj�cy jako parametr tekst opisuj�cy b��d
	 */
	public BrakTransformacjiOdwrotnejException(String message) {
		super(message);
	}

	/*
	 * Konstruktor przyjmuj�cy jako parametr referencje do innego wyj�tku, kt�ry
	 * spowodowa� b��d
	 */
	public BrakTransformacjiOdwrotnejException(Throwable cause) {
		super(cause);
	}

	/*
	 * Konstruktor przyjmuj�cy jako parametr tekst opisuj�cy b��d oraz wyj�tek,
	 * kt�ry spowodowa� b��d.
	 */
	public BrakTransformacjiOdwrotnejException(String message, Throwable cause) {
		super(message, cause);
	}
}