package pl.edu.pg.eti.ksg.po.lab1.transformacje;
import java.lang.Math;

public class Obrot implements Transformacja {
	private final double kat;
	private final double katRadian;
	
	public Obrot(double kat) {
		this.kat = kat;
		katRadian = Math.toRadians(kat);
	}
	
	@Override
	public Punkt transformuj(Punkt p) {
		Math.sin(katRadian);
		double xPrim = ( p.getX() * Math.cos(katRadian) ) - ( p.getY() * Math.sin(katRadian) );
		double yPrim = ( p.getX() * Math.sin(katRadian) ) + ( p.getY() * Math.cos(katRadian) );
		return new Punkt(xPrim, yPrim);
	}

	@Override
	public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException {
		return new Obrot(-kat);
	}
	
	public double getKat() {
		return this.kat;
	}
	
	@Override
	public String toString() {
		return "Obrot o kat: " + this.kat;
	}
}
