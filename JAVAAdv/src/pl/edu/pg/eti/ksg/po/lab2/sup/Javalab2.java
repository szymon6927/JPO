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
		 * Wprowadzone w Javie 8. Pozwala przekonwertowaæ metodê obiektu na
		 * klasê implementuj¹c¹ interfejs funkcjonalny.
		 */
		listaSluchaczy.add(instancjaB::zwyklaMetoda);
		/**
		 * Wprowadzone w Javie 8. Pozwala przekonwertowaæ metodê statyczn¹ na
		 * klasê implementuj¹c¹ interfejs funkcjonalny
		 */
		listaSluchaczy.add(ZwyklaKlasa::zwyklaStatycznaMetoda);
		String nazwa = "Test Interfejsów";
		int priorytet = 8;
		for (SluchaczZdarzen sl : listaSluchaczy) {
			sl.wystapiloZdarzenie(priorytet, nazwa);
		}
	}
}
