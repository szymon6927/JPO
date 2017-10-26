package pl.edu.pg.eti.ksg.po.lab1.transformacje;

/* * Klasa ta jawnie dziedziczy po klasie java.lang.Exception */
public class BrakTransformacjiOdwrotnejException extends Exception {
	/*
	 * Klasa ta jawnie dziedziczy po klasie java.lang.Exception
	 */
	public BrakTransformacjiOdwrotnejException() {
		// Niejawne wywo³anie konstruktora klasy nadrzêdnej
		// super();
	}

	/*
	 * Konstruktor przyjmuj¹cy jako parametr tekst opisuj¹cy b³¹d
	 */
	public BrakTransformacjiOdwrotnejException(String message) {
		super(message);
	}

	/*
	 * Konstruktor przyjmuj¹cy jako parametr referencje do innego wyj¹tku, który
	 * spowodowa³ b³¹d
	 */
	public BrakTransformacjiOdwrotnejException(Throwable cause) {
		super(cause);
	}

	/*
	 * Konstruktor przyjmuj¹cy jako parametr tekst opisuj¹cy b³¹d oraz wyj¹tek,
	 * który spowodowa³ b³¹d.
	 */
	public BrakTransformacjiOdwrotnejException(String message, Throwable cause) {
		super(message, cause);
	}
}