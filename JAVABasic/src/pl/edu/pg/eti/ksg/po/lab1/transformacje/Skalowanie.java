package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Skalowanie implements Transformacja {
	private final double skalaX, skalaY;

	public Skalowanie(double skalaX, double skalaY) {
		this.skalaX = skalaX;
		this.skalaY = skalaY;
	}

	/*
	 * W przypadku klasy Skalowanie metoda getTransformacjaOdwrotna 
	 * zg�asza b��d w przypadku braku transformacji odwrotnej
	 * (z powodu dzielenia przez 0). B��d ten jest zg�aszany za 
	 * pomoc� specjalnej instrukcji throw kt�ra to powoduje 
	 * propagacje informacji o b��dzie do metod wywo�uj�cych
	 * do momentu a� maszyna wirtualna natrafi na fragment kodu 
	 * obs�uguj�cy wyrzucony wyj�tek
	 */
	@Override
	public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException {
		if (skalaX == 0 || skalaY == 0) {
			throw new BrakTransformacjiOdwrotnejException(
					"Brak transformacji odwrotnej. Przynajmniej jeden z czynnik�w skalowania jest r�wny 0.");
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
