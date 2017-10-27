package pl.edu.pg.eti.ksg.po.lab2;

import java.util.Set;

import pl.edu.pg.eti.ksg.po.lab2.biegpolesie.Uczestnik;

import java.util.HashSet;

public class Javalab2 {
	public static void main(String[] args) {
		Set<Uczestnik> uczestnicy = new HashSet<>();
		uczestnicy.add(new BagiennyBiegacz("Krzysztof", "Kowalski", Czlowiek.Plec.MEZCZYZNA));
		uczestnicy.add(new RobotMobilny(1));
		uczestnicy.add(new Terminator(3912));
		uczestnicy.add(new Student("Alfred", "Archiwista", Czlowiek.Plec.MEZCZYZNA, "Historia"));
		uczestnicy.add(new StudentWETIOrazLesnik("Apoloniusz", "Ga³¹zka", Czlowiek.Plec.MEZCZYZNA, "Informatyka"));
		
		bieg.przeprowadzImpreze();
	}
}