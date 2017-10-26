package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Skalowanie implements Transformacja {
	private final double skalaX, skalaY;

	public Skalowanie(double skalaX, double skalaY) {
		this.skalaX = skalaX;
		this.skalaY = skalaY;
	}

	/*
	 * W przypadku klasy Skalowanie metoda getTransformacjaOdwrotna 
	 * zg³asza b³¹d w przypadku braku transformacji odwrotnej
	 * (z powodu dzielenia przez 0). B³¹d ten jest zg³aszany za 
	 * pomoc¹ specjalnej instrukcji throw która to powoduje 
	 * propagacje informacji o b³êdzie do metod wywo³uj¹cych
	 * do momentu a¿ maszyna wirtualna natrafi na fragment kodu 
	 * obs³uguj¹cy wyrzucony wyj¹tek
	 */
	@Override
	public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException {
		if (skalaX == 0 || skalaY == 0) {
			throw new BrakTransformacjiOdwrotnejException(
					"Brak transformacji odwrotnej. Przynajmniej jeden z czynników skalowania jest równy 0.");
		}

		return new Skalowanie(1 / skalaX, 1 / skalaY);
	}

	@Override
	public Punkt transformuj(Punkt p) {
		return new Punkt(skalaX * p.getX(), skalaY * p.getY());
	}

	public double getSkalaX() {
		return skalaX;
	}

	public double getSkalaY() {
		return skalaY;
	}

	@Override
	public String toString() {
		return "Skalowanie " + skalaX + "x oraz " + skalaY + "y";
	}
}
