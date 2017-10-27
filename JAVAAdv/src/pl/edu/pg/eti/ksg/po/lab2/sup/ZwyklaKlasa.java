package pl.edu.pg.eti.ksg.po.lab2.sup;

public class ZwyklaKlasa {
	private static int liczbaInstancji = 0;
	private int numerInstancji;

	/**
	 * Klasa wewnêtrzna ma dostêp do wszystkich pól i metod obiektu oraz klasy.
	 * Nie musi implementowaæ interfesju. Mo¿e mieæ dowolny zasiêg widocznoœci.
	 */
	private class KlasaWewnetrzna implements SluchaczZdarzen {
		private int poleKlasyWewnentrznej;

		public KlasaWewnetrzna(int poleKlasyWewnentrznej) {
			this.poleKlasyWewnentrznej = poleKlasyWewnentrznej;
		}

		@Override
		public void wystapiloZdarzenie(int priorytet, String nazwa) {
			System.out.println("KlasaWewnetrzna obs³uguje zdarzenie " + nazwa + " o priorytecie " + priorytet);
			System.out.println("Wartosci pól:");
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
					"StatycznaKlasaWewnetrzna" + "obs³uguje zdarzenie " + nazwa + " o priorytecie " + priorytet);
			System.out.println("Wartosci pól:");
			System.out.println("liczbaInstancji: " + liczbaInstancji);
			// Brak dostêpu do pola numerInstancji - klasa wewnêtrzna jest
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
		 * obiekt klasy anonimowej tworzony w metodzie obiektu nadrzêdnego ma
		 * dostêp do wszystkich pól i metod analogicznie do klasy wewnêtrznej.
		 * Klasy anonimowe mog¹ byæ utworzone na bazie ka¿dej klasy po której
		 * mo¿na dziedziczyæ, b¹dŸ interfejsu. Najczêœciej jednak klasy te s¹
		 * tworzone na bazie klas abstrakcyjnych i interfejsów.
		 */
		return new SluchaczZdarzen() {
			int poleKlasyAnonimowej = 5 * numerInstancji;

			@Override
			public void wystapiloZdarzenie(int priorytet, String nazwa) {
				System.out.println("KlasaAnonimowa obs³uguje zdarzenie " + nazwa + " o priorytecie " + priorytet);
				System.out.println("Wartosci pól:");
				System.out.println("liczbaInstancji: " + liczbaInstancji);
				System.out.println("numerInstancji: " + numerInstancji);
				System.out.println("poleKlasyAnonimowej: " + poleKlasyAnonimowej);
			}
		};
	}

	public SluchaczZdarzen wyrazenieLambda() {
		/**
		 * Wyra¿enia lambda wprowadzono w Javie 8. Mo¿na przyj¹æ, * ¿e jest to
		 * skrócona wersja klasy anonimowej * dla interfejsu oznaczonego
		 * andotacj¹ * @FunctionalInterface
		 */
		return (int p, String n) -> {
			System.out.println("Wyra¿enie Lambda obs³uguje zdarzenie " + n + " o priorytecie " + p);
			System.out.println("Wartosci pól:");
			System.out.println("liczbaInstancji: " + liczbaInstancji);
			System.out.println("numerInstancji: " + numerInstancji);
		};
	}

	public void zwyklaMetoda(int priorytet, String nazwa) {
		System.out.println("zwyklaMetoda obs³uguje zdarzenie " + nazwa + " o priorytecie " + priorytet);
		System.out.println("Wartosci pól:");
		System.out.println("liczbaInstancji: " + liczbaInstancji);
		System.out.println("numerInstancji: " + numerInstancji);
	}

	public static void zwyklaStatycznaMetoda(int priorytet, String nazwa) {
		System.out.println("zwyklaStatycznaMetoda obs³uguje zdarzenie " + nazwa + " o priorytecie " + priorytet);
		System.out.println("Wartosci pól:");
		System.out.println("liczbaInstancji: " + liczbaInstancji);
	}
}
