package pl.edu.pg.eti.ksg.po.lab2.biegpolesie;
import java.util.Random;

public interface Uczestnik {
	boolean rozwiazZadanie();
	int predkoscPoruszaniaSie();
	
	public static int randInt(int min, int max) {

	    Random rand = new Random();

	    int randomNum = rand.nextInt((max - min) + 1) + min;

	    return randomNum;
	}
}