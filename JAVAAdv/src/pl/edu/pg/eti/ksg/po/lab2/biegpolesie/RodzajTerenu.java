
package pl.edu.pg.eti.ksg.po.lab2.biegpolesie;

/**
 * Rodzaje terenu na jakie mog� natkn�� si� uczestnicy biegu po lesie
 * @author TB
 */
public enum RodzajTerenu {
	/** 
	 * Teren po kt�rym �atwo jest si� porsuza� 
	 */
	DROGA,
	/**
	 * Nieco mniej przebie�na ni�
	 * {@link pl.edu.pg.eti.ksg.po.lab2.biegpolesie.RodzajTerenu#DROGA}
	 */
	SCIEZKA,
	/** 
	 * Teren w kt�rym trzeba si� ostro�nie prusza� 
	 */
	WYSOKI_LAS,
	/** 
	 * Teren trudny 
	 */
	NISKI_LAS,
	/** 
	 * Teren niebezpieczny, prawie niemo�liwy do przebycia 
	 */
	BAGNO;
}
