package pl.edu.pg.eti.ksg.po.lab2.sup;

public class ZwyklaKlasa {
	private static int liczbaInstancji = 0;
	private int numerInstancji;

	/**
	 * Klasa wewn�trzna ma dost�p do wszystkich p�l i metod obiektu oraz klasy.
	 * Nie musi implementowa� interfesju. Mo�e mie� dowolny zasi�g widoczno�ci.
	 */
	private class KlasaWewnetrzna implements SluchaczZdarzen {
		private int poleKlasyWewnentrznej;

		public KlasaWewnetrzna(int poleKlasyWewnentrznej) {
			this.poleKlasyWewnentrznej = poleKlasyWewnentrznej;
		}

		@Override
		public void wystapiloZdarzenie(int priorytet, String nazwa) {
			System.out.println("KlasaWewnetrzna obs�uguje zdarzenie " + nazwa + " o priorytecie " + priorytet);
			System.out.println("Wartosci p�l:");
			System.out.println("liczbaInstancji: " + liczbaInstancji);
			System.out.println("numerInstancji: " + numerInstancji);
			System.out.println("poleKlasyWewnentrznej: " + poleKlasyWewnentrznej);
		}
	}

	private static class StatycznaKlasaWewnetrzna implements SluchaczZdarzen {
		private int poleStatycznejKlasyWewnentrznej;

		public StatycznaKlasaWewnetrzna(int p) {
			this.poleStatycznejKlasyWewnentrznej = p;
		}

		@Override
		public void wystapiloZdarzenie(int priorytet, String nazwa) {
			System.out.println(
					"StatycznaKlasaWewnetrzna" + "obs�uguje zdarzenie " + nazwa + " o priorytecie " + priorytet);
			System.out.println("Wartosci p�l:");
			System.out.println("liczbaInstancji: " + liczbaInstancji);
			// Brak dost�pu do pola numerInstancji - klasa wewn�trzna jest
			// statycza
			// System.out.println("numerInstancji: "+ numerInstancji);
			System.out.println("poleStatycznejKlasyWewnentrznej: " + poleStatycznejKlasyWewnentrznej);
		}
	}

	public ZwyklaKlasa() {
		liczbaInstancji++;
		numerInstancji = liczbaInstancji;
	}

	public SluchaczZdarzen klasaWewnetrzna() {
		return new KlasaWewnetrzna(2 * numerInstancji);
	}

	public SluchaczZdarzen statycznaKlasaWewnetrzna() {
		return new StatycznaKlasaWewnetrzna(3 * liczbaInstancji);
	}

	public SluchaczZdarzen klasaAnonimowa() {
		/**
		 * obiekt klasy anonimowej tworzony w metodzie obiektu nadrz�dnego ma
		 * dost�p do wszystkich p�l i metod analogicznie do klasy wewn�trznej.
		 * Klasy anonimowe mog� by� utworzone na bazie ka�dej klasy po kt�rej
		 * mo�na dziedziczy�, b�d� interfejsu. Najcz�ciej jednak klasy te s�
		 * tworzone na bazie klas abstrakcyjnych i interfejs�w.
		 */
		return new SluchaczZdarzen() {
			int poleKlasyAnonimowej = 5 * numerInstancji;

			@Override
			public void wystapiloZdarzenie(int priorytet, String nazwa) {
				System.out.println("KlasaAnonimowa obs�uguje zdarzenie " + nazwa + " o priorytecie " + priorytet);
				System.out.println("Wartosci p�l:");
				System.out.println("liczbaInstancji: " + liczbaInstancji);
				System.out.println("numerInstancji: " + numerInstancji);
				System.out.println("poleKlasyAnonimowej: " + poleKlasyAnonimowej);
			}
		};
	}

	public SluchaczZdarzen wyrazenieLambda() {
		/**
		 * Wyra�enia lambda wprowadzono w Javie 8. Mo�na przyj��, * �e jest to
		 * skr�cona wersja klasy anonimowej * dla interfejsu oznaczonego
		 * andotacj� * @FunctionalInterface
		 */
		return (int p, String n) -> {
			System.out.println("Wyra�enie Lambda obs�uguje zdarzenie " + n + " o priorytecie " + p);
			System.out.println("Wartosci p�l:");
			System.out.println("liczbaInstancji: " + liczbaInstancji);
			System.out.println("numerInstancji: " + numerInstancji);
		};
	}

	public void zwyklaMetoda(int priorytet, String nazwa) {
		System.out.println("zwyklaMetoda obs�uguje zdarzenie " + nazwa + " o priorytecie " + priorytet);
		System.out.println("Wartosci p�l:");
		System.out.println("liczbaInstancji: " + liczbaInstancji);
		System.out.println("numerInstancji: " + numerInstancji);
	}

	public static void zwyklaStatycznaMetoda(int priorytet, String nazwa) {
		System.out.println("zwyklaStatycznaMetoda obs�uguje zdarzenie " + nazwa + " o priorytecie " + priorytet);
		System.out.println("Wartosci p�l:");
		System.out.println("liczbaInstancji: " + liczbaInstancji);
	}
}
