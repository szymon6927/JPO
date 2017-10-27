package pl.edu.pg.eti.ksg.po.lab2.sup;

import java.util.LinkedList;
import java.util.List;

public class Javalab2 {
	public static void main(String[] args) {
		ZwyklaKlasa instancjaA = new ZwyklaKlasa();
		ZwyklaKlasa instancjaB = new ZwyklaKlasa();
		List<SluchaczZdarzen> listaSluchaczy = new LinkedList<>();
		listaSluchaczy.add(instancjaA.klasaWewnetrzna());
		listaSluchaczy.add(instancjaA.statycznaKlasaWewnetrzna());
		listaSluchaczy.add(instancjaA.klasaAnonimowa());
		listaSluchaczy.add(instancjaB.wyrazenieLambda());
		/**
		 * Wprowadzone w Javie 8. Pozwala przekonwertowa� metod� obiektu na
		 * klas� implementuj�c� interfejs funkcjonalny.
		 */
		listaSluchaczy.add(instancjaB::zwyklaMetoda);
		/**
		 * Wprowadzone w Javie 8. Pozwala przekonwertowa� metod� statyczn� na
		 * klas� implementuj�c� interfejs funkcjonalny
		 */
		listaSluchaczy.add(ZwyklaKlasa::zwyklaStatycznaMetoda);
		String nazwa = "Test Interfejs�w";
		int priorytet = 8;
		for (SluchaczZdarzen sl : listaSluchaczy) {
			sl.wystapiloZdarzenie(priorytet, nazwa);
		}
	}
}
